#include "LayoutUtil.h"
USING_NS_CC;

//最方的设备是1024*768,最长的设备是1092*614
//在此范围内，游戏保证各元素的长宽比例，并在合适的地方留白，尽量保持视觉效果
//在此范围以外的设备，游戏各元素将会被不等比拉伸

const float LayoutUtil::DESIGN_WIDTH = 614.0f;
const float LayoutUtil::DESIGN_WIDTH_2 = 682.0f; //682.667
const float LayoutUtil::DESIGN_HEIGHT = 1024.0f;

const float LayoutUtil::COMPATIBLE_HEIGHT = 1092.0f;
//const float LayoutUtil::COMPATIBLE_WIDTH=768.0f;
const float LayoutUtil::COMPATIBLE_WIDTH=682.0f;

float LayoutUtil::_width = 0;
float LayoutUtil::_height = 0;
float LayoutUtil::_scale = 0;
float LayoutUtil::_extraXScreen = 0;
float LayoutUtil::_extraXUI = 0;
float LayoutUtil::_extraY = 0;

void LayoutUtil::init(float cWidth,float cHeight){
    if(cWidth/cHeight > DESIGN_WIDTH/DESIGN_HEIGHT) {
        _scale = cHeight/DESIGN_HEIGHT;
        _height = DESIGN_HEIGHT;
        _width = cWidth / _scale;
        if(_width > COMPATIBLE_WIDTH) {
            _width = COMPATIBLE_WIDTH;
        }
        if(_width>DESIGN_WIDTH_2) {
            _extraXScreen = _width-DESIGN_WIDTH_2;
            _extraXUI = DESIGN_WIDTH_2 - DESIGN_WIDTH;
        } else {
            _extraXScreen = 0;\
            _extraXUI = _width-DESIGN_WIDTH;
        }
        //temp func here
//        _extraXUI = 0;
//        _extraXScreen = _width - DESIGN_WIDTH;
        //==============
        _extraY = 0;
    } else {
        _scale = cWidth / DESIGN_WIDTH;
        _width = DESIGN_WIDTH;
        _height = cHeight / _scale;
        if(_height > COMPATIBLE_HEIGHT) {
            _height = COMPATIBLE_HEIGHT;
        }
        _extraXUI = _extraXScreen = 0;
        _extraY = _height - DESIGN_HEIGHT;
    }
    CCLOG("w=%f,h=%f",_width,_height);
};
float LayoutUtil::subtractHeight(float totalHeight, Node *node, ...) {
    va_list arg_ptr;
    va_start(arg_ptr, node);
    float height = subtractHeight(totalHeight,node,arg_ptr);
    va_end(arg_ptr);
    return height;
}

float LayoutUtil::subtractHeight(cocos2d::Node *node, ...) {
    va_list arg_ptr;
    va_start(arg_ptr, node);
    float height = subtractHeight(getHeight(),node,arg_ptr);
    va_end(arg_ptr);
    return height;
}

float LayoutUtil::subtractHeight(float totalHeight,cocos2d::Node* firstNode, va_list args){
    Node* now = NULL;
    if(firstNode) {
        totalHeight -= firstNode->getContentSize().height;
        while(true) {
            now=va_arg(args, Node*);
            if(now) {
                totalHeight -= now->getContentSize().height;
            }else {
                break;
            }

        }
    }
    return totalHeight;
}

//将一堆item排成一排，彼此靠拢，空隙为spacing，并且整体在parent中居中
void LayoutUtil::layoutAsCenterGroup(cocos2d::Node* parent,float offsetY,AlignTypeVertical alignType,float spacing, cocos2d::Node* item,...) {
    va_list arg_ptr;
    va_start(arg_ptr, item);
    layoutAsHorizontalGroup(parent, offsetY,alignType, spacing,-1, item,arg_ptr,true);
    va_end(arg_ptr);
}
//将一堆item排成一排，在parent中，先在最左最后预留margin个像素，然后将剩余像素平均分配在这堆item的中间
void LayoutUtil::layoutAsSplitGroup(cocos2d::Node* parent,float offsetY,AlignTypeVertical alignType,float marginInBothSide, cocos2d::Node* item,...) {
    va_list arg_ptr;
    va_start(arg_ptr, item);
    layoutAsHorizontalGroup(parent, offsetY,alignType,-1, marginInBothSide, item,arg_ptr,false);
    va_end(arg_ptr);
}

void LayoutUtil::layoutAsHorizontalGroup(cocos2d::Node* parent,float offsetY,AlignTypeVertical alignType,float spacingBetweenItem,float marginInBothSide, cocos2d::Node* firstNode, va_list args,bool closeInCenter) {
    Node* now = NULL;
    if(firstNode) {
        float totalWidth = firstNode->getContentSize().width;
        std::vector<cocos2d::Node*> children;
        children.push_back(firstNode);
        while(true) {
            now=va_arg(args, Node*);
            if(now) {
                children.push_back(now);
                totalWidth += now->getContentSize().width;
            }else {
                break;
            }
        }
        float actualLeftMargin = marginInBothSide;
        if(closeInCenter) {
            actualLeftMargin = (parent->getContentSize().width - totalWidth - (children.size() -1)*spacingBetweenItem)/2;
        }
        float actualSpacingBetweenItem = spacingBetweenItem;
        if(!closeInCenter) {
            actualSpacingBetweenItem = (parent->getContentSize().width - totalWidth - marginInBothSide*2 )/(children.size()+1);
            actualLeftMargin += actualSpacingBetweenItem;
        }
        
        for(int i=0; i<children.size() ; i++) {
            cocos2d::Node* child = children[i];
            if(i==0) {
                switch (alignType) {
                    case AlignTypeVertical::TOP:
                        layoutParentLeftTop(child,actualLeftMargin,offsetY);
                        break;
                    case AlignTypeVertical::CENTER:
                        layoutParentLeft(child,actualLeftMargin,offsetY);
                        break;
                    case AlignTypeVertical::BOTTOM:
                        layoutParentLeftBottom(child,actualLeftMargin,offsetY);
                        break;
                }
            } else {
                layoutRight(child, children[i-1],actualSpacingBetweenItem);
            }
        }
    }
}

Vec2 LayoutUtil::alignTypeToPoint(AlignType type) {
    switch (type) {
        case AlignType::CENTER:
            return Vec2(0.5, 0.5);
            break;
        case AlignType::CENTER_TOP:
            return Vec2(0.5, 1.0);
            break;
        case AlignType::CENTER_BOTTOM:
            return Vec2(0.5, 0.0);
            break;
        case AlignType::LEFT_TOP:
            return Vec2(0.0, 1.0);
            break;
        case AlignType::LEFT_CENTER:
            return Vec2(0.0, 0.5);
            break;
        case AlignType::LEFT_BOTTOM:
            return Vec2(0.0, 0.0);
            break;
        case AlignType::RIGHT_TOP:
            return Vec2(1.0, 1.0);
            break;
        case AlignType::RIGHT_CENTER:
            return Vec2(1.0, 0.5);
            break;
        case AlignType::RIGHT_BOTTOM:
            return Vec2(1.0, 0.0);
            break;
    }
}

void LayoutUtil::layoutLeft(cocos2d::Node* view, cocos2d::Node* target, float offsetX /* = 0.0 */, float offsetY /* = 0.0 */) {
    layout(view, 1, 0.5, target, 0, 0.5, false, offsetX, offsetY);
}

void LayoutUtil::layoutRight(cocos2d::Node* view, cocos2d::Node* target, float offsetX /* = 0.0 */, float offsetY /* = 0.0 */) {
    layout(view, 0, 0.5, target, 1, 0.5, false, offsetX, offsetY);
}

void LayoutUtil::layoutTop(cocos2d::Node* view, cocos2d::Node* target, float offsetX /* = 0.0 */, float offsetY /* = 0.0 */) {
    layout(view, 0.5, 0, target, 0.5, 1, false, offsetX, offsetY);
}

void LayoutUtil::layoutBottom(cocos2d::Node* view, cocos2d::Node* target, float offsetX /* = 0.0 */, float offsetY /* = 0.0 */) {
    layout(view, 0.5, 1, target, 0.5, 0, false, offsetX, offsetY);
}

void LayoutUtil::layoutCenter(cocos2d::Node* view, cocos2d::Node* target, float offsetX /* = 0.0 */, float offsetY /* = 0.0 */) {
    layout(view, 0.5, 0.5, target, 0.5, 0.5, false, offsetX, offsetY);
}

void LayoutUtil::layoutLeftTop(cocos2d::Node* view, cocos2d::Node* target, float offsetX /* = 0.0 */, float offsetY /* = 0.0 */) {
    layout(view, 1, 1, target, 0, 1, false, offsetX, offsetY);
}

void LayoutUtil::layoutRightTop(cocos2d::Node* view, cocos2d::Node* target, float offsetX /* = 0.0 */, float offsetY /* = 0.0 */) {
    layout(view, 0, 1, target, 1, 1, false, offsetX, offsetY);
}

void LayoutUtil::layoutLeftBottom(cocos2d::Node* view, cocos2d::Node* target, float offsetX /* = 0.0 */, float offsetY /* = 0.0 */) {
    layout(view, 1, 0, target, 0, 0, false, offsetX, offsetY);
}

void LayoutUtil::layoutRightBottom(cocos2d::Node* view, cocos2d::Node* target, float offsetX /* = 0.0 */, float offsetY /* = 0.0 */) {
    layout(view, 0, 0, target, 1, 0, false, offsetX, offsetY);
}

void LayoutUtil::layoutTopLeft(cocos2d::Node* view, cocos2d::Node* target, float offsetX, float offsetY) {
    layout(view, 0, 0, target, 0, 1, false, offsetX, offsetY);
}

void LayoutUtil::layoutTopRight(cocos2d::Node* view, cocos2d::Node* target, float offsetX, float offsetY) {
    layout(view, 1, 0, target, 1, 1, false, offsetX, offsetY);
}

void LayoutUtil::layoutBottomLeft(cocos2d::Node* view, cocos2d::Node* target, float offsetX, float offsetY) {
    layout(view, 0, 1, target, 0, 0, false, offsetX, offsetY);
}

void LayoutUtil::layoutBottomRight(cocos2d::Node* view, cocos2d::Node* target, float offsetX, float offsetY) {
    layout(view, 1, 1, target, 1, 0, false, offsetX, offsetY);
}

void LayoutUtil::layoutLeftTopInside(cocos2d::Node* view, cocos2d::Node* target, float offsetX, float offsetY) {
    layout(view, 0, 1, target, 0, 1, false, offsetX, offsetY);
}

void LayoutUtil::layoutRightTopInside(cocos2d::Node* view, cocos2d::Node* target, float offsetX, float offsetY) {
    layout(view, 1, 1, target, 1, 1, false, offsetX, offsetY);
}

void LayoutUtil::layoutLeftBottomInside(cocos2d::Node* view, cocos2d::Node* target, float offsetX, float offsetY) {
    layout(view, 0, 0, target, 0, 0, false, offsetX, offsetY);
}

void LayoutUtil::layoutRightBottomInside(cocos2d::Node* view, cocos2d::Node* target, float offsetX, float offsetY) {
    layout(view, 1, 0, target, 1, 0, false, offsetX, offsetY);
}

void LayoutUtil::layoutLeftInside(cocos2d::Node* view, cocos2d::Node* target, float offsetX /* = 0.0 */, float offsetY /* = 0.0 */) {
    layout(view, 0, 0.5, target, 0, 0.5, false, offsetX, offsetY);
}

void LayoutUtil::layoutRightInside(cocos2d::Node* view, cocos2d::Node* target, float offsetX /* = 0.0 */, float offsetY /* = 0.0 */) {
    layout(view, 1, 0.5, target, 1, 0.5, false, offsetX, offsetY);
}

void LayoutUtil::layoutTopInside(cocos2d::Node* view, cocos2d::Node* target, float offsetX /* = 0.0 */, float offsetY /* = 0.0 */) {
    layout(view, 0.5, 1, target, 0.5, 1, false, offsetX, offsetY);
}

void LayoutUtil::layoutBottomInside(cocos2d::Node* view, cocos2d::Node* target, float offsetX /* = 0.0 */, float offsetY /* = 0.0 */) {
    layout(view, 0.5, 0, target, 0.5, 0, false, offsetX, offsetY);
}

void LayoutUtil::layoutParentLeft(cocos2d::Node* view, float offsetX /* = 0.0 */, float offsetY /* = 0.0 */) {
    layout(view, 0, 0.5, view->getParent(), 0, 0.5, true, offsetX, offsetY);
}

void LayoutUtil::layoutParentRight(cocos2d::Node* view, float offsetX /* = 0.0 */, float offsetY /* = 0.0 */) {
    layout(view, 1, 0.5, view->getParent(), 1, 0.5, true, offsetX, offsetY);
}

void LayoutUtil::layoutParentTop(cocos2d::Node* view, float offsetX /* = 0.0 */, float offsetY /* = 0.0 */) {
    layout(view, 0.5, 1, view->getParent(), 0.5, 1, true, offsetX, offsetY);
}

void LayoutUtil::layoutParentBottom(cocos2d::Node* view, float offsetX /* = 0.0 */, float offsetY /* = 0.0 */) {
    layout(view, 0.5, 0, view->getParent(), 0.5, 0, true, offsetX, offsetY);
}

void LayoutUtil::layoutParentCenter(cocos2d::Node* view, float offsetX /* = 0.0 */, float offsetY /* = 0.0 */) {
    layout(view, 0.5, 0.5, view->getParent(), 0.5, 0.5, true, offsetX, offsetY);
}

void LayoutUtil::layoutParentLeftTop(cocos2d::Node* view, float offsetX /* = 0.0 */, float offsetY /* = 0.0 */) {
    layout(view, 0, 1, view->getParent(), 0, 1, true, offsetX, offsetY);
}

void LayoutUtil::layoutParentRightTop(cocos2d::Node* view, float offsetX /* = 0.0 */, float offsetY /* = 0.0 */) {
    layout(view, 1, 1, view->getParent(), 1, 1, true, offsetX, offsetY);
}

void LayoutUtil::layoutParentLeftBottom(cocos2d::Node* view, float offsetX /* = 0.0 */, float offsetY /* = 0.0 */) {
    layout(view, 0, 0, view->getParent(), 0, 0, true, offsetX, offsetY);
}

void LayoutUtil::layoutParentRightBottom(cocos2d::Node* view, float offsetX /* = 0.0 */, float offsetY /* = 0.0 */) {
    layout(view, 1, 0, view->getParent(), 1, 0, true, offsetX, offsetY);
}

void LayoutUtil::layout(cocos2d::Node *view, AlignType from, cocos2d::Node *target, AlignType to, bool targetIsParent, float offsetX, float offsetY) {
    Vec2 fromV = alignTypeToPoint(from);
    Vec2 toV = alignTypeToPoint(to);
    
    layout(view, fromV.x, fromV.y, target, toV.x, toV.y, targetIsParent, offsetX, offsetY);
}

void LayoutUtil::layoutParent(cocos2d::Node *view, AlignType from, AlignType to, float offsetx, float offsetY) {
    layout(view, from, view->getParent(), to, true, offsetx, offsetY);
}

void LayoutUtil::layout(cocos2d::Node* src, float srcAlignX, float srcAlignY, cocos2d::Node* target,
                        float targetAlignX, float targetAlignY, bool targetIsParent /* = false */, float offsetX /* = 0.0 */, float offsetY /* = 0.0 */) {
    const Vec2& srcAnchorPoint = src->isIgnoreAnchorPointForPosition() ? Vec2::ANCHOR_BOTTOM_LEFT : src->getAnchorPoint();
    const Vec2& anchorPointDiff = Vec2(srcAlignX - srcAnchorPoint.x, srcAlignY - srcAnchorPoint.y);
    const Vec2& targetAnchorPoint = target->isIgnoreAnchorPointForPosition() ? Vec2::ANCHOR_BOTTOM_LEFT : target->getAnchorPoint();
    float targetAlignXPosition,targetAlignYPosition;
    if (targetIsParent) {
        targetAlignXPosition = target->getContentSize().width * targetAlignX;
        targetAlignYPosition = target->getContentSize().height * targetAlignY;
    } else {
        targetAlignXPosition = target->getPositionX() + target->getBoundingBox().size.width * (targetAlignX - targetAnchorPoint.x);
        targetAlignYPosition = target->getPositionY() + target->getBoundingBox().size.height * (targetAlignY - targetAnchorPoint.y);
    }
#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
    offsetY += workaroundWithLabelTTFInAndroid(src,srcAlignY);
#endif
    src->setPosition(Vec2(targetAlignXPosition - anchorPointDiff.x * src->getBoundingBox().size.width + offsetX,
                         targetAlignYPosition - anchorPointDiff.y * src->getBoundingBox().size.height + offsetY));
    
}
float LayoutUtil::workaroundWithLabelTTFInAndroid(cocos2d::Node* view,float viewAlignY) {
    LabelTTF* label = dynamic_cast<LabelTTF*>(view);
    if(label == NULL) {
        return 0;
    }
    float height = label->getContentSize().height;
    if(height >= 40) {
        return 0;
    }
    //依据的案例是，字号为32时，ios7上高度为34，ios6上高度为35，android上高度43
    //ios7上，文字高32，文字下空2
    //android上，文字上空7，文字高32，文字下空4
    if(viewAlignY ==1) {
        return  height * 3/43.0;
    } else if(viewAlignY == 0.5) {
        return  height * 1/43.0;
    }else if(viewAlignY == 0) {
        return -2 * height / 43.0;
    }else {
        return 0;
    }
}
void LayoutUtil::matchParent(cocos2d::Node *view) {
    Node* parent = view->getParent();
    view->setContentSize(parent->getContentSize());
    layoutParentCenter(view);
}