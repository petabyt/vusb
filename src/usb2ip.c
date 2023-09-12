// On-the-fly PTP/USB to IP packet conversion.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <ptp.h>

// Get data from the app, convert it to usb for vcam
void *conv_ip_cmd_packet_to_usb(char *buffer, int length, int *outlength) {
	struct PtpIpBulkContainer *bc = (struct PtpIpBulkContainer *)buffer;

	int param_length = (bc->length - 18) / 4;

	printf("Param length: %d\n", param_length);

	if (bc->type == PTPIP_COMMAND_REQUEST) {
		struct PtpBulkContainer *c = (struct PtpBulkContainer *)malloc(12 + (param_length * 4));
		c->length = 12 + (param_length * 4);
		(*outlength) = c->length;
		c->type = PTP_PACKET_TYPE_COMMAND;
		c->transaction = bc->transaction;
		c->code = bc->code;
		for (int i = 0; i < param_length; i++) {
			c->params[i] = bc->params[i];
		}

		return c;
	} else {
		puts("Unsupported command request");
		exit(-1);
	}
}

void *conv_ip_data_packets_to_usb(void *ds_buffer, void *de_buffer, int *outlength) {
	 // else if (bc->type == PTPIP_DATA_PACKET_START) {
		// 
	// } else if (bc->type == PTPIP_DATA_PACKET_END) {
		// 
	// }
}

// Parse data from vcam
// TODO: wrongly named nisnomer
void *conv_usb_packet_to_ip(char *buffer, int length, int *outlength) {
	struct PtpBulkContainer *c = (struct PtpBulkContainer *)buffer;
	int param_length = (c->length - 12) / 4;

	printf("Packet type: %d\n", c->type);

	if (c->type == PTP_PACKET_TYPE_DATA) {
		// Send both payload start (16 bytes) and end packet (12 + payload)
		int payload_length = c->length - 12;
		(*outlength) = sizeof(struct PtpIpStartDataPacket) + sizeof(struct PtpIpEndDataPacket) + payload_length;
		uint8_t *newpkt = malloc((*outlength));

		struct PtpIpStartDataPacket *sd = (struct PtpIpStartDataPacket *)newpkt;
		sd->length = sizeof(struct PtpIpStartDataPacket);
		sd->type = PTPIP_DATA_PACKET_START;
		sd->transaction = c->transaction;
		sd->data_phase_length = (uint64_t)payload_length;

		struct PtpIpEndDataPacket *ed = (struct PtpIpEndDataPacket *)(newpkt + sizeof(struct PtpIpStartDataPacket));
		ed->length = sizeof(struct PtpIpEndDataPacket) + payload_length;
		ed->type = PTPIP_DATA_PACKET_END;
		ed->transaction = c->transaction;

		void *payload = newpkt + sizeof(struct PtpIpStartDataPacket) + sizeof(struct PtpIpEndDataPacket);
		memcpy(payload, ((uint8_t *)buffer) + 12, payload_length);

		return (void *)newpkt;
	} else if (c->type == PTP_PACKET_TYPE_RESPONSE) {
		struct PtpIpResponseContainer *resp = (struct PtpIpResponseContainer *)malloc(14);

		resp->length = 14;
		(*outlength) = resp->length;
		resp->type = PTPIP_COMMAND_RESPONSE;
		resp->code = c->code;
		resp->transaction = c->transaction;

		return (void *)resp;
	} else if (c->type == PTP_PACKET_TYPE_COMMAND) {
		struct PtpIpBulkContainer *req = (struct PtpIpBulkContainer *)malloc(18 + (param_length * 4));
		req->length = 18 + (param_length * 4);
		(*outlength) = req->length;
		req->type = PTPIP_COMMAND_REQUEST;
		req->code = c->code;
		req->transaction = c->transaction;
		for (int i = 0; i < param_length; i++) {
			req->params[i] = c->params[i];
		}

		return (void *)req;
	} else {
		puts("Unknown USB packet\n");
		return NULL;
	}
}
