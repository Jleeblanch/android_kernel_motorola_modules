DLKM_DIR := kernel/motorola/modules
LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
LOCAL_MODULE := watchdog_cpu_ctx.ko
LOCAL_MODULE_TAGS := optional
LOCAL_MODULE_PATH := $(KERNEL_MODULES_OUT)
#include $(DLKM_DIR)/AndroidKernelModule.mk
