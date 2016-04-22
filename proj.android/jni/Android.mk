LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

$(call import-add-path,$(LOCAL_PATH)/../../cocos2d)
$(call import-add-path,$(LOCAL_PATH)/../../cocos2d/external)
$(call import-add-path,$(LOCAL_PATH)/../../cocos2d/cocos)


LOCAL_MODULE := cocos2dcpp_shared

LOCAL_MODULE_FILENAME := libcocos2dcpp

LOCAL_SRC_FILES := hellocpp/main.cpp\
../../Classes/AppDelegate.cpp\
../../Classes/battle/BattleContral.cpp\
../../Classes/battle/BattleModel.cpp\
../../Classes/battle/BattleView.cpp\
../../Classes/common/LayoutUtil.cpp\
../../Classes/common/ResourceName.cpp\
../../Classes/common/StrConstMgr.cpp\
../../Classes/common/VisibleRect.cpp\
../../Classes/ui/CoverScene.cpp\
../../Classes/ui/GameScene.cpp\
 ../../Classes/ui/HomeScene.cpp\
../../Classes/ui/ReadyScene.cpp

LOCAL_C_INCLUDES := $(LOCAL_PATH)/../../Classes


# _COCOS_HEADER_ANDROID_BEGIN
# _COCOS_HEADER_ANDROID_END


LOCAL_STATIC_LIBRARIES := cocos2dx_static

# _COCOS_LIB_ANDROID_BEGIN
# _COCOS_LIB_ANDROID_END

include $(BUILD_SHARED_LIBRARY)

$(call import-module,.)

# _COCOS_LIB_IMPORT_ANDROID_BEGIN
# _COCOS_LIB_IMPORT_ANDROID_END
