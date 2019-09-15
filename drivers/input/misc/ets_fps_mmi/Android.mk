DLKM_DIR := kernel/motorola/modules
LOCAL_PATH := $(call my-dir)

ifeq ($(DLKM_INSTALL_TO_VENDOR_OUT),true)
ETS_FPS_MMI_MODULE_PATH := $(TARGET_OUT_VENDOR)/lib/modules/
else
ETS_FPS_MMI_MODULE_PATH := $(KERNEL_MODULES_OUT)
endif

ifeq ($(FPS_NAVI_ENABLE),true)
	KERNEL_CFLAGS += CONFIG_INPUT_EGISTEC_FPS_NAVI_HORIZON=y
	KERNEL_CFLAGS += CONFIG_INPUT_EGISTEC_FPS_NAVI_VERTICAL=y
endif

include $(CLEAR_VARS)
LOCAL_MODULE := ets_fps_mmi.ko
LOCAL_MODULE_TAGS := optional
LOCAL_MODULE_PATH := $(ETS_FPS_MMI_MODULE_PATH)
include $(DLKM_DIR)/AndroidKernelModule.mk

