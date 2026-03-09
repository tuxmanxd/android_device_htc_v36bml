LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
LOCAL_SRC_FILES := camera_shim.cpp
LOCAL_MODULE := libshim_camera
LOCAL_MODULE_TAGS := optional
LOCAL_MODULE_CLASS := SHARED_LIBRARIES
LOCAL_VENDOR_MODULE := true

LOCAL_C_INCLUDES := \
    frameworks/native/include \
    frameworks/native/libs/nativebase/include \
    system/core/include

LOCAL_SHARED_LIBRARIES := libui libutils
include $(BUILD_SHARED_LIBRARY)
