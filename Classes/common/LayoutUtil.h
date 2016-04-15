#ifndef __LayoutUtil__
#define __LayoutUtil__

#include "cocos2d.h"

enum class AlignType {
    CENTER,
    CENTER_TOP,
    CENTER_BOTTOM,
    LEFT_TOP,
    LEFT_CENTER,
    LEFT_BOTTOM,
    RIGHT_TOP,
    RIGHT_CENTER,
    RIGHT_BOTTOM,
};

enum class AlignTypeVertical {
    CENTER,
    TOP,
    BOTTOM,
};

enum class AlignTypeHorizontal {
    CENTER,
    LEFT,
    RIGHT,
};

class LayoutUtil {
private:
    static const float DESIGN_WIDTH_2;
public:
    static const float DESIGN_WIDTH;
    static const float DESIGN_HEIGHT;
    static const float COMPATIBLE_WIDTH;
    static const float COMPATIBLE_HEIGHT;
    
    static void init(float cWidth,float cHeight);
    
    static inline float getWidth() {return _width;};
    static inline float getHeight() {return _height;};
    
    static inline float getScale() {return _scale;};
    
    static inline float getOffsetY() {return _extraY/2;};
    static inline float getExtraY() {return _extraY;};
    static inline bool hasExtraY() {return _extraY > 0.01f;};
    
    static inline float getUIWidth() {return DESIGN_WIDTH+_extraXUI;};
    static inline float getExtraXUI() {return _extraXUI;};
    static inline float getOffsetXUI() {return _extraXUI/2;};
    static inline bool hasExtraXUI() {return _extraXUI > 0.01f;};

    static inline float getExtraXOutOfUI() {return _extraXScreen;};
    static inline float getOffsetXOutOfUI() {return _extraXScreen/2;};
    static inline bool hasExtraXOutOfUI() {return _extraXScreen > 0.01f;};
    
    static inline bool isMostSquare() {return fabs(_width - COMPATIBLE_WIDTH )<0.01f;};
    
    static float subtractHeight(cocos2d::Node* node,...);
    static float subtractHeight(float totalHeight,cocos2d::Node* node,...);
    static void layoutAsCenterGroup(cocos2d::Node* parent,float offsetY,AlignTypeVertical alignType, float spacing, cocos2d::Node* item,...);
    static void layoutAsSplitGroup(cocos2d::Node* parent,float offsetY,AlignTypeVertical alignType,float marginInBothSide, cocos2d::Node* item,...);
    
private:
    static float subtractHeight(float totalHeight,cocos2d::Node* firstNode, va_list args);
    static void layoutAsHorizontalGroup(cocos2d::Node* parent,float offsetY,AlignTypeVertical alignType,float spacingBetweenItem,float marginInBothSide, cocos2d::Node* firstNode, va_list args,bool closeInCenter);
    
    static float _width;
    static float _height;
    static float _scale;
    static float _extraXScreen;
    static float _extraXUI;
    static float _extraY;
//copied from Framework layout
public:
    static cocos2d::Vec2 alignTypeToPoint(AlignType type);
    
    static void layoutLeft(cocos2d::Node* view, cocos2d::Node* target, float offsetX = 0.0, float offsetY = 0.0);
    static void layoutRight(cocos2d::Node* view, cocos2d::Node* target, float offsetX = 0.0, float offsetY = 0.0);
    static void layoutTop(cocos2d::Node* view, cocos2d::Node* target, float offsetX = 0.0, float offsetY = 0.0);
    static void layoutBottom(cocos2d::Node* view, cocos2d::Node* target, float offsetX = 0.0, float offsetY = 0.0);
    static void layoutCenter(cocos2d::Node* view, cocos2d::Node* target, float offsetX = 0.0, float offsetY = 0.0);
    static void layoutLeftTop(cocos2d::Node* view, cocos2d::Node* target, float offsetX = 0.0, float offsetY = 0.0);
    static void layoutRightTop(cocos2d::Node* view, cocos2d::Node* target, float offsetX = 0.0, float offsetY = 0.0);
    static void layoutLeftBottom(cocos2d::Node* view, cocos2d::Node* target, float offsetX = 0.0, float offsetY = 0.0);
    static void layoutRightBottom(cocos2d::Node* view, cocos2d::Node* target, float offsetX = 0.0, float offsetY = 0.0);
    static void layoutTopLeft(cocos2d::Node* view, cocos2d::Node* target, float offsetX = 0.0, float offsetY = 0.0);
    static void layoutTopRight(cocos2d::Node* view, cocos2d::Node* target, float offsetX = 0.0, float offsetY = 0.0);
    static void layoutBottomLeft(cocos2d::Node* view, cocos2d::Node* target, float offsetX = 0.0, float offsetY = 0.0);
    static void layoutBottomRight(cocos2d::Node* view, cocos2d::Node* target, float offsetX = 0.0, float offsetY = 0.0);
    static void layoutLeftTopInside(cocos2d::Node* view, cocos2d::Node* target, float offsetX = 0.0, float offsetY = 0.0);
    static void layoutRightTopInside(cocos2d::Node* view, cocos2d::Node* target, float offsetX = 0.0, float offsetY = 0.0);
    static void layoutLeftBottomInside(cocos2d::Node* view, cocos2d::Node* target, float offsetX = 0.0, float offsetY = 0.0);
    static void layoutRightBottomInside(cocos2d::Node* view, cocos2d::Node* target, float offsetX = 0.0, float offsetY = 0.0);
    static void layoutLeftInside(cocos2d::Node* view, cocos2d::Node* target, float offsetX = 0.0, float offsetY = 0.0);
    static void layoutRightInside(cocos2d::Node* view, cocos2d::Node* target, float offsetX = 0.0, float offsetY = 0.0);
    static void layoutTopInside(cocos2d::Node* view, cocos2d::Node* target, float offsetX = 0.0, float offsetY = 0.0);
    static void layoutBottomInside(cocos2d::Node* view, cocos2d::Node* target, float offsetX = 0.0, float offsetY = 0.0);
    
    static void layoutParentLeft(cocos2d::Node* view, float offsetX = 0.0, float offsetY = 0.0);
    static void layoutParentRight(cocos2d::Node* view, float offsetX = 0.0, float offsetY = 0.0);
    static void layoutParentTop(cocos2d::Node* view, float offsetX = 0.0, float offsetY = 0.0);
    static void layoutParentBottom(cocos2d::Node* view, float offsetX = 0.0, float offsetY = 0.0);
    static void layoutParentCenter(cocos2d::Node* view, float offsetX = 0.0, float offsetY = 0.0);
    static void layoutParentLeftTop(cocos2d::Node* view, float offsetX = 0.0, float offsetY = 0.0);
    static void layoutParentRightTop(cocos2d::Node* view, float offsetX = 0.0, float offsetY = 0.0);
    static void layoutParentLeftBottom(cocos2d::Node* view, float offsetX = 0.0, float offsetY = 0.0);
    static void layoutParentRightBottom(cocos2d::Node* view, float offsetX = 0.0, float offsetY = 0.0);
    
    static void layout(cocos2d::Node* view, AlignType from, cocos2d::Node* target, AlignType to, bool targetIsParent = false, float offsetx = 0.0, float offsetY = 0.0);
    static void layoutParent(cocos2d::Node* view, AlignType from, AlignType to, float offsetx = 0.0, float offsetY = 0.0);
    
    static void layout(cocos2d::Node* view, float viewAlignX, float viewAlignY, cocos2d::Node* target,
                float targetAlignX, float targetAlignY, bool targetIsParent = false, float offsetX = 0.0, float offsetY = 0.0);
    
    static float workaroundWithLabelTTFInAndroid(cocos2d::Node* view,float viewAlignY);
    static void matchParent(cocos2d::Node* view);
    
};

#endif /* defined(__LayoutUtil__) */
