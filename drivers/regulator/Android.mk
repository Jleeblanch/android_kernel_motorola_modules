DLKM_DIR := kernel/motorola/modules
LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
LOCAL_MODULE := madera-ldo1.ko
LOCAL_MODULE_TAGS := optional
LOCAL_MODULE_PATH := $(KERNEL_MODULES_OUT)
include $(DLKM_DIR)/AndroidKernelModule.mk

include $(CLEAR_VARS)
LOCAL_MODULE := madera-micsupp.ko
LOCAL_MODULE_TAGS := optional
LOCAL_MODULE_PATH := $(KERNEL_MODULES_OUT)
include $(DLKM_DIR)/AndroidKernelModule.mk
