// External opcode header for camera definitions and ptp_function declarations
// All data in this file is static, and can be included more than once (although try to not)
#ifndef VCAM_OPCODES_H
#define VCAM_OPCODES_H

// Standard USB opcodes
static struct ptp_function ptp_functions_generic[] = {
	{0x1001,	ptp_deviceinfo_write, 		NULL			},
	{0x1002,	ptp_opensession_write, 		NULL			},
	{0x1003,	ptp_closesession_write, 	NULL			},
	{0x1004,	ptp_getstorageids_write, 	NULL			},
	{0x1005,	ptp_getstorageinfo_write, 	NULL			},
	{0x1006,	ptp_getnumobjects_write, 	NULL			},
	{0x1007,	ptp_getobjecthandles_write, NULL			},
	{0x1008,	ptp_getobjectinfo_write, 	NULL			},
	{0x1009,	ptp_getobject_write, 		NULL			},
	{0x100A,	ptp_getthumb_write, 		NULL			},
	{0x100B,	ptp_deleteobject_write, 	NULL			},
	{0x100E,	ptp_initiatecapture_write, 	NULL			},
	{0x1014,	ptp_getdevicepropdesc_write, 	NULL			},
	{0x1015,	ptp_getdevicepropvalue_write, 	NULL			},
	{0x1016,	ptp_setdevicepropvalue_write, 	ptp_setdevicepropvalue_write_data	},
	{0x101B,	ptp_getpartialobject_write, 	NULL			},
	{0x9999,	ptp_vusb_write, 		ptp_vusb_write_data			},
};

static struct ptp_function ptp_functions_nikon_dslr[] = {
	{0x90c2,	ptp_nikon_setcontrolmode_write, NULL			},
};

#ifdef VCAM_CANON
static struct ptp_function ptp_functions_canon[] = {
	{0x9101,	ptp_eos_generic, NULL },
	{0x9102,	ptp_eos_generic, NULL },
	{0x9103,	ptp_eos_generic, NULL },
	{0x9104,	ptp_eos_generic, NULL },
	{0x9107,	ptp_eos_generic, NULL },
	{0x9105,	ptp_eos_generic, NULL },
	{0x9106,	ptp_eos_generic, NULL },
	{PTP_OC_EOS_SetDevicePropValueEx,	ptp_eos_set_property, ptp_eos_set_property_payload},
	{0x9127,	ptp_eos_generic, NULL },
	{0x910b,	ptp_eos_generic, NULL },
	{0x9108,	ptp_eos_generic, NULL },
	{0x9109,	ptp_eos_generic, NULL },
	{0x910c,	ptp_eos_generic, NULL },
	{0x910e,	ptp_eos_generic, NULL },
	{0x910f,	ptp_eos_generic, NULL },
	{0x9115,	ptp_eos_generic, NULL },
	{0x9114,	ptp_eos_generic, NULL },
	{0x9113,	ptp_eos_generic, NULL },
	{PTP_OC_EOS_GetEvent,	vusb_ptp_eos_events, NULL },
	{0x9117,	ptp_eos_generic, NULL },
	{0x9120,	ptp_eos_generic, NULL },
	{0x91f0,	ptp_eos_generic, NULL },
	{0x9118,	ptp_eos_generic, NULL },
	{0x9121,	ptp_eos_generic, NULL },
	{0x91f1,	ptp_eos_generic, NULL },
	{0x911d,	ptp_eos_generic, NULL },
	{0x910a,	ptp_eos_generic, NULL },
	{0x911b,	ptp_eos_generic, NULL },
	{0x911c,	ptp_eos_generic, NULL },
	{0x911e,	ptp_eos_generic, NULL },
	{0x911a,	ptp_eos_generic, NULL },
	{PTP_OC_EOS_GetViewFinderData,	ptp_eos_viewfinder_data, NULL },
	{0x9154,	ptp_eos_generic, NULL },
	{0x9160,	ptp_eos_generic, NULL },
	{0x9155,	ptp_eos_generic, NULL },
	{0x9157,	ptp_eos_generic, NULL },
	{0x9158,	ptp_eos_generic, NULL },
	{0x9159,	ptp_eos_generic, NULL },
	{0x915a,	ptp_eos_generic, NULL },
	{0x911f,	ptp_eos_generic, NULL },
	{0x91fe,	ptp_eos_generic, NULL },
	{0x91ff,	ptp_eos_generic, NULL },
	{PTP_OC_EOS_RemoteReleaseOn,	ptp_eos_remote_release, NULL },
	{PTP_OC_EOS_RemoteReleaseOff,	ptp_eos_remote_release, NULL },
	{0x912d,	ptp_eos_generic, NULL },
	{0x912e,	ptp_eos_generic, NULL },
	{0x912f,	ptp_eos_generic, NULL },
	{0x912c,	ptp_eos_generic, NULL },
	{0x9130,	ptp_eos_generic, NULL },
	{0x9131,	ptp_eos_generic, NULL },
	{0x9132,	ptp_eos_generic, NULL },
	{0x9133,	ptp_eos_generic, NULL },
	{0x9134,	ptp_eos_generic, NULL },
	{0x912b,	ptp_eos_generic, NULL },
	{0x9135,	ptp_eos_generic, NULL },
	{0x9136,	ptp_eos_generic, NULL },
	{0x9137,	ptp_eos_generic, NULL },
	{0x9138,	ptp_eos_generic, NULL },
	{0x9139,	ptp_eos_generic, NULL },
	{0x913a,	ptp_eos_generic, NULL },
	{0x913b,	ptp_eos_generic, NULL },
	{0x913c,	ptp_eos_generic, NULL },
	{0x91da,	ptp_eos_generic, NULL },
	{0x91db,	ptp_eos_generic, NULL },
	{0x91dc,	ptp_eos_generic, NULL },
	{0x91dd,	ptp_eos_generic, NULL },
	{0x91de,	ptp_eos_generic, NULL },
	{0x91d8,	ptp_eos_generic, NULL },
	{0x91d9,	ptp_eos_generic, NULL },
	{0x91d7,	ptp_eos_generic, NULL },
	{0x91d5,	ptp_eos_generic, NULL },
	{0x902f,	ptp_eos_generic, NULL },
	{0x9141,	ptp_eos_generic, NULL },
	{0x9142,	ptp_eos_generic, NULL },
	{0x9143,	ptp_eos_generic, NULL },
	{0x913f,	ptp_eos_generic, NULL },
	{0x9033,	ptp_eos_generic, NULL },
	{0x9068,	ptp_eos_generic, NULL },
	{0x9069,	ptp_eos_generic, NULL },
	{0x906a,	ptp_eos_generic, NULL },
	{0x906b,	ptp_eos_generic, NULL },
	{0x906c,	ptp_eos_generic, NULL },
	{0x906d,	ptp_eos_generic, NULL },
	{0x906e,	ptp_eos_generic, NULL },
	{0x906f,	ptp_eos_generic, NULL },
	{0x913d,	ptp_eos_generic, NULL },
	{0x9180,	ptp_eos_generic, NULL },
	{0x9181,	ptp_eos_generic, NULL },
	{0x9182,	ptp_eos_generic, NULL },
	{0x9183,	ptp_eos_generic, NULL },
	{0x9184,	ptp_eos_generic, NULL },
	{0x9185,	ptp_eos_generic, NULL },
	{0x9140,	ptp_eos_generic, NULL },
	{0x9801,	ptp_eos_generic, NULL },
	{0x9802,	ptp_eos_generic, NULL },
	{0x9803,	ptp_eos_generic, NULL },
	{0x9804,	ptp_eos_generic, NULL },
	{0x9805,	ptp_eos_generic, NULL },
	{0x91c0,	ptp_eos_generic, NULL },
	{0x91c1,	ptp_eos_generic, NULL },
	{0x91c2,	ptp_eos_generic, NULL },
	{0x91c3,	ptp_eos_generic, NULL },
	{0x91c4,	ptp_eos_generic, NULL },
	{0x91c5,	ptp_eos_generic, NULL },
	{0x91c6,	ptp_eos_generic, NULL },
	{0x91c7,	ptp_eos_generic, NULL },
	{0x91c8,	ptp_eos_generic, NULL },
	{0x91c9,	ptp_eos_generic, NULL },
	{0x91ca,	ptp_eos_generic, NULL },
	{0x91cb,	ptp_eos_generic, NULL },
	{0x91cc,	ptp_eos_generic, NULL },
	{0x91ce,	ptp_eos_generic, NULL },
	{0x91cf,	ptp_eos_generic, NULL },
	{0x91d0,	ptp_eos_generic, NULL },
	{0x91d1,	ptp_eos_generic, NULL },
	{0x91d2,	ptp_eos_generic, NULL },
	{0x91e1,	ptp_eos_generic, NULL },
	{0x91e2,	ptp_eos_generic, NULL },
	{0x91e3,	ptp_eos_generic, NULL },
	{0x91e4,	ptp_eos_generic, NULL },
	{0x91e5,	ptp_eos_generic, NULL },
	{0x91e6,	ptp_eos_generic, NULL },
	{0x91e7,	ptp_eos_generic, NULL },
	{0x91e8,	ptp_eos_generic, NULL },
	{0x91e9,	ptp_eos_generic, NULL },
	{0x91ea,	ptp_eos_generic, NULL },
	{0x91eb,	ptp_eos_generic, NULL },
	{0x91ec,	ptp_eos_generic, NULL },
	{0x91ed,	ptp_eos_generic, NULL },
	{0x91ee,	ptp_eos_generic, NULL },
	{0x91ef,	ptp_eos_generic, NULL },
	{0x91f8,	ptp_eos_generic, NULL },
	{0x91f9,	ptp_eos_generic, NULL },
	{0x91f2,	ptp_eos_generic, NULL },
	{0x91f3,	ptp_eos_generic, NULL },
	{0x91f4,	ptp_eos_generic, NULL },
	{0x91f7,	ptp_eos_generic, NULL },
	{0x9122,	ptp_eos_generic, NULL },
	{0x9123,	ptp_eos_generic, NULL },
	{0x9124,	ptp_eos_generic, NULL },
	{0x91f5,	ptp_eos_generic, NULL },
	{0x91f6,	ptp_eos_generic, NULL },
	{0x9052,	ptp_eos_generic, NULL },
	{0x9053,	ptp_eos_generic, NULL },
	{0x9057,	ptp_eos_generic, NULL },
	{0x9058,	ptp_eos_generic, NULL },
	{0x9059,	ptp_eos_generic, NULL },
	{0x905a,	ptp_eos_generic, NULL },
	{0x905f,	ptp_eos_generic, NULL },
	{0x9996,	ptp_eos_generic, NULL },
};
#endif

#ifdef VCAM_FUJI
static struct ptp_function ptp_functions_fuji_x_a2[] = {
	{PTP_OC_FUJI_GetDeviceInfo,	ptp_fuji_get_device_info, NULL },
	{0x101c,	ptp_fuji_capture, NULL },
	{0x1018,	ptp_fuji_capture, NULL },
};
#endif

static struct ptp_map_functions {
	vcameratype		type;
	struct ptp_function	*functions;
	unsigned int		nroffunctions;
} ptp_functions[] = {
	{GENERIC_PTP,	ptp_functions_generic,		sizeof(ptp_functions_generic) / sizeof(ptp_functions_generic[0])},
	{NIKON_D750,	ptp_functions_nikon_dslr,	sizeof(ptp_functions_nikon_dslr) / sizeof(ptp_functions_nikon_dslr[0])},

#ifdef VCAM_CANON
	{CANON_1300D,	ptp_functions_canon,		sizeof(ptp_functions_canon) / sizeof(ptp_functions_canon[0])},
#endif

#ifdef VCAM_FUJI
	{FUJI_X_A2,	ptp_functions_fuji_x_a2,		sizeof(ptp_functions_fuji_x_a2) / sizeof(ptp_functions_fuji_x_a2[0])},
#endif

};

static struct ptp_property {
	int code;
	int (*getdesc)(vcamera *cam, PTPDevicePropDesc *);
	int (*getvalue)(vcamera *cam, PTPPropertyValue *);
	int (*setvalue)(vcamera *cam, PTPPropertyValue *);
} ptp_properties[] = {
    {0x5001, ptp_battery_getdesc, ptp_battery_getvalue, NULL},
    {0x5003, ptp_imagesize_getdesc, ptp_imagesize_getvalue, NULL},
    {0x5007, ptp_fnumber_getdesc, ptp_fnumber_getvalue, ptp_fnumber_setvalue},
    {0x5010, ptp_exposurebias_getdesc, ptp_exposurebias_getvalue, ptp_exposurebias_setvalue},
    {0x500d, ptp_shutterspeed_getdesc, ptp_shutterspeed_getvalue, ptp_shutterspeed_setvalue},
    {0x5011, ptp_datetime_getdesc, ptp_datetime_getvalue, ptp_datetime_setvalue},
};

#endif // endif opcodes.h
