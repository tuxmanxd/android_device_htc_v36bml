#include <ui/GraphicBufferMapper.h>
#include <nativebase/nativebase.h>

extern "C" {
    // Previous shim for lockYCbCr
    void _ZN7android19GraphicBufferMapper9lockYCbCrEPK13native_handleiRKNS_4RectEP13android_ycbcr(
            void* obj, buffer_handle_t handle, uint32_t usage, const android::Rect& bounds, void* ycbcr) {
        android::GraphicBufferMapper& mapper = android::GraphicBufferMapper::get();
        mapper.lockYCbCr(handle, usage, bounds, (android_ycbcr*)ycbcr);
    }

    // NEW SHIM: Feature Manager Singleton
    // Adjusted to return a dummy pointer to prevent null-dereference crashes
    void* _ZN5NSCam2v35Utils10FeatureMgr23getFeatureMgrSingleInstEv() {
        return (void*)1; 
    }

    // NEW SHIM: updateCameraMode(unsigned int, unsigned int)
    // Matches the missing symbol: _ZN5NSCam2v35Utils10FeatureMgr16updateCameraModeEjj
    void _ZN5NSCam2v35Utils10FeatureMgr16updateCameraModeEjj(void* obj, unsigned int mode, unsigned int val) {
        // Stub to satisfy libmmsdkservice.feature.so
    }
    // NEW SHIM: DpIspStream::startStream()
    // Matches the missing symbol: _ZN11DpIspStream11startStreamEv
    void _ZN11DpIspStream11startStreamEv(void* obj) {
        // Stub to satisfy libcam.iopipe.so
    }
    void _ZN11DpIspStream15dequeueFrameEndEv(void* obj) {
    }
    // 6. NEW: jpeg_std_error_MTK shim
    // This fixes the "cannot locate symbol jpeg_std_error_MTK" error in libJpgEncPipe.so
    void* jpeg_std_error_MTK(void* err) {
        return err;
    }
    // NEW SHIM: jpeg_CreateCompress_MTK
    // Resolves the symbol: jpeg_CreateCompress_MTK
    // Referenced by: /system/vendor/lib/libJpgEncPipe.so
    void jpeg_CreateCompress_MTK(void* cinfo, int version, size_t structsize) {
        // This is a no-op stub to satisfy the linker.
    }
    // NEW SHIM: jpeg_set_defaults_MTK
    // Resolves the symbol: jpeg_set_defaults_MTK
    // Referenced by: /system/vendor/lib/libJpgEncPipe.so
    void jpeg_set_defaults_MTK(void* cinfo) {
        // This is a no-op stub to satisfy the linker.
    }
    // NEW SHIM: jpeg_set_quality_MTK
    // Resolves the symbol: jpeg_set_quality_MTK
    // Referenced by: /system/vendor/lib/libJpgEncPipe.so
    void jpeg_set_quality_MTK(void* cinfo, int quality, int force_baseline) {
        // This is a no-op stub to satisfy the linker.
    }
    // NEW SHIM: jpeg_mem_dest_MTK
    // Resolves the symbol: jpeg_mem_dest_MTK
    // Referenced by: /system/vendor/lib/libJpgEncPipe.so
    void jpeg_mem_dest_MTK(void* cinfo, unsigned char** outbuffer, unsigned long* outsize) {
        // This is a no-op stub to satisfy the linker for libJpgEncPipe.so
    }
    // NEW SHIM: jpeg_start_compress_MTK
    // Resolves the symbol: jpeg_start_compress_MTK
    // Referenced by: /system/vendor/lib/libJpgEncPipe.so
    void jpeg_start_compress_MTK(void* cinfo, bool write_all_tables) {
        // This is a no-op stub to satisfy the linker for libJpgEncPipe.so
    }
    // NEW SHIM: jpeg_write_raw_data_MTK
    // Resolves the symbol: jpeg_write_raw_data_MTK
    // Referenced by: /system/vendor/lib/libJpgEncPipe.so
    int jpeg_write_raw_data_MTK(void* cinfo, void* data, unsigned int num_lines) {
        // This is a no-op stub to satisfy the linker for libJpgEncPipe.so.
        // It returns 0 (or the number of lines processed) to keep the HAL from crashing.
        return num_lines;
    }
    // NEW SHIM: jpeg_finish_compress_MTK
    // Resolves the symbol: jpeg_finish_compress_MTK
    // Referenced by: /system/vendor/lib/libJpgEncPipe.so
    void jpeg_finish_compress_MTK(void* cinfo) {
        // This is a no-op stub to satisfy the linker for libJpgEncPipe.so
    }
    // NEW SHIM: jpeg_destroy_compress_MTK
    // Resolves the symbol: jpeg_destroy_compress_MTK
    // Referenced by: /system/vendor/lib/libJpgEncPipe.so
    void jpeg_destroy_compress_MTK(void* cinfo) {
        // This is a no-op stub to satisfy the linker.
    }
    // NEW SHIM: Prevent crash in ImgSensorDrv
    // Symbol: _ZN11ImgSensorDrv19getCurrentSensorTypeE15SENSOR_DEV_ENUM
    // Referenced by: /system/vendor/lib/libcam.halsensor.so
    int _ZN11ImgSensorDrv19getCurrentSensorTypeE15SENSOR_DEV_ENUM(void* obj, int sensorDev) {
        // Return 0 (RAW) or 1 (YUV) to satisfy the sensor search logic.
        // This prevents the HAL from actually executing the broken code in libcam.halsensor.so.
        return 0; 
    }
    // NEW SHIM: Intercept the sensor search to prevent the crash in libcam.halsensor.so
    // Symbol: NSCam::NSHalSensor::HalSensorList::searchSensors()
    // Referenced by: /system/vendor/lib/hw/camera.mt6753.so
    int _ZN5NSCam11NSHalSensor13HalSensorList13searchSensorsEv(void* obj) {
        return 1; 
    }


}
