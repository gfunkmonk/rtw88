// SPDX-License-Identifier: GPL-2.0 OR BSD-3-Clause
/* Copyright(c) 2018-2019  Realtek Corporation
 */

#include <linux/module.h>
#include <linux/usb.h>
#include "main.h"
#include "rtw8703b.h"
#include "usb.h"

static const struct usb_device_id rtw_8723bu_id_table[] = {
	{ USB_DEVICE_AND_INTERFACE_INFO(RTW_USB_VENDOR_ID_REALTEK, 0xb720, 0xff, 0xff, 0xff),
	  .driver_info = (kernel_ulong_t)&(rtw8703b_hw_spec) }, /* 8723BU 1*1 */
	{ USB_DEVICE_AND_INTERFACE_INFO(0x7392, 0xa611, 0xff, 0xff, 0xff),
	  .driver_info = (kernel_ulong_t)&(rtw8703b_hw_spec) }, /* Edimax EW-7611ULB */
	{ },
};
MODULE_DEVICE_TABLE(usb, rtw_8723bu_id_table);

static int rtw8723bu_probe(struct usb_interface *intf,
			   const struct usb_device_id *id)
{
	return rtw_usb_probe(intf, id);
}

static struct usb_driver rtw_8723bu_driver = {
	.name = KBUILD_MODNAME,
	.id_table = rtw_8723bu_id_table,
	.probe = rtw8723bu_probe,
	.disconnect = rtw_usb_disconnect,
};
module_usb_driver(rtw_8723bu_driver);

MODULE_AUTHOR("Realtek Corporation");
MODULE_DESCRIPTION("Realtek 802.11n wireless 8723BU driver");
MODULE_LICENSE("Dual BSD/GPL");
