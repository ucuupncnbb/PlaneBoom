#include "BattleView.h"


BattleView::BattleView(Node *parent) : parentLayer(parent)
{
    plSprite = Sprite::create(ResourceName::Images::MY_PLANE);
    parent->addChild(plSprite,10);
    LayoutUtil::layoutParentCenter(plSprite);
    
}