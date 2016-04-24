#include "BattleView.h"
//#include "math.h"

BattleView::BattleView(Node *parent) : m_parentLayer(parent)
{
    
}
void BattleView::createPlane()
{
    m_plSprite = Sprite::create(ResourceName::Images::MY_PLANE);
    m_parentLayer->addChild(m_plSprite,10);
    LayoutUtil::layoutParentCenter(m_plSprite);
    
    updataAngle(12,0.1);
}

void BattleView::updataAngle(double x,double y)
{
    double rAngle = atanf(y/x);
    double dAngle = CC_RADIANS_TO_DEGREES(rAngle);
    
    m_plSprite->setRotation(dAngle);
}

void BattleView::updataPosition(Acceleration* acc)
{
    //planeSpr->setPosition(planeSpr->getPosition().x+1,planeSpr->getPosition().y+1);
    auto ballSize  = m_plSprite->getContentSize();
    
    auto ptNow  = m_plSprite->getPosition();
    
    log("acc: x = %lf, y = %lf", acc->x, acc->y);
    
    double speed = 30.00f;
    
    Vec2 movePos = Vec2(ptNow.x + acc->x * speed,ptNow.y + acc->y * speed);
    
    //updating angle
    this->updataAngle(acc->x * speed,acc->y * speed);
    
    FIX_POS(movePos.x, (VisibleRect::left().x+ballSize.width / 2.0), (VisibleRect::right().x - ballSize.width / 2.0));
    FIX_POS(movePos.y, (VisibleRect::bottom().y+ballSize.height / 2.0), (VisibleRect::top().y - ballSize.height / 2.0));
    m_plSprite->setPosition(movePos);
    
}



