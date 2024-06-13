#define LOG_TAG "FanSpeedControl"

#include <utils/Log.h>
#include <iostream>
#include <fstream>
#include "FanSpeedControl.h"

namespace aidl {
    namespace android {
        namespace hardware {
            namespace fancontroller {
                ndk::ScopedAStatus FanSpeedControl::turnFanOnHAL(std::bool* _aidl_return ) {
                    if(!isFanOn){
                        isFanOn = true;//turn on the fan
                        fanSpeed = 1;//set the speed to 1
                        *_aidl_return = true;//return value on success
                        ALOGD("Fan turned ON");//log statement
                        return ndk::ScopedAStatus::ok();//return status
                    }
                    *_aidl_return = false;//return value on failure
                    ALOGE("Fan is already ON");//log statement
                    return ndk::ScopedAStatus::fromServiceSpecificError(-1);//return status
                }
                ndk::ScopedAStatus FanSpeedControl::turnFanOffHal(std::bool* _aidl_return) {
                    if(isFanOn){
                        isFanOn = false;//turn off the fan
                        fanSpeed = 0;//set the fan speed to zero
                        *_aidl_return = true;//return value on success
                        ALOGD("Fan turned OFF");//log statement
                        return ndk::ScopedAStatus::ok();//return status
                    }
                    *_aidl_return = false;//return value on failure
                    ALOGE("Fan is already OFF");//log statement
                    return ndk::ScopedAStatus::fromServiceSpecificError(-1);//return status
                }
                ndk::ScopedAStatus FanSpeedControl::isFanOnHal(std::bool* _aidl_return) {
                    if (isFanOn){
                        *_aidl_return = true;//return value on success
                        ALOGD("Fan is ON");//log statement
                        return ndk::ScopedAStatus::ok();//return status
                    }
                    *_aidl_return = false;//return value on failure
                    ALOGE("Fan is OFF");//log statement
                    return ndk::ScopedAStatus::fromServiceSpecificError(-1);//return status
                }
                ndk::ScopedAStatus FanSpeedControl::increaseFanSpeedHAL(std::bool* _aidl_return {
                    if(fanSpeed <5){
                        fanSpeed++;//increase fan speed
                        *_aidl_return = true;//return value on success
                        ALOGD("Increased Fan Speed");//log statement
                        return ndk::ScopedAStatus::ok();//return status
                    }
                    *_aidl_return = false;//return value on failure
                    ALOGE("Fan Speed is already at maximum");//log statement
                    return ndk::ScopedAStatus::fromServiceSpecificError(-1);//return status
                }
                ndk::ScopedAStatus FanSpeedControl::decreaseFanSpeedHAL() {
                    if(fanSpeed >= 0){
                        fanSpeed--;//decrease fan speed
                        *_aidl_return = true;//return value on success
                        ALOGD("Decreased Fan Speed");//log statement
                        return ndk::ScopedAStatus::ok();//return status
                    }
                    *_aidl_return = false;//return value on failure
                    ALOGE("Fan Speed is already at minimum");//log statement
                    return ndk::ScopedAStatus::fromServiceSpecificError(-1);//return status
                }
                ndk::ScopedAStatus FanSpeedControl::getFanSpeedHal(std::int* _aidl_return) {
                    if(isFanOn){
                        *_aidl_return = fanSpeed;//return value on success
                        ALOGD("Fan speed returned successfully");//log statement
                        return ndk::ScopedAStatus::ok();//return status
                    }
                    *_aidl_return = 0;//return value on failure
                    ALOGE("Fan is off, so returned 0");//log statement
                    return ndk::ScopedAStatus::fromServiceSpecificError(-1);//return status
                }
            }
        }
    }
}