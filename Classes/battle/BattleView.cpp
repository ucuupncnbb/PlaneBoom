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
}

void BattleView::updataAngle(double x,double y)
{
    double rAngle = atanf(y/x);
    double dAngle = CC_RADIANS_TO_DEGREES(rAngle);
    if(x>0 && y>0)
    {
        dAngle = 90 - dAngle;
    }
    else if(x>0 && y<0)
    {
        dAngle = 90 - dAngle;
    }
    else if(x<0 && y<0)
    {
        dAngle = -90 - dAngle;
    }
    else if(x<0 && y>0)
    {
        dAngle = -90 - dAngle;
    }
    //set rotation
    auto actRota = RotateTo::create(0.02,dAngle);
    m_plSprite->runAction(actRota);
}

void BattleView::updataPosition(Acceleration* acc)
{
    auto ballSize  = m_plSprite->getContentSize();
    
    auto ptNow  = m_plSprite->getPosition();
    
    log("acc: x = %lf, y = %lf", acc->x, acc->y);
    
    double speed = 30.00f;
    
    Vec2 movePos = Vec2(ptNow.x + acc->x * speed,ptNow.y + acc->y * speed);
    
    //updating angle and pos
    double offsetX = acc->x * speed;
    double offsetY = acc->y * speed;
    
    if(offsetX*offsetX > 0.1 && offsetY*offsetY > 0.1)
    {
        this->updataAngle(offsetX,offsetY);
    }

    FIX_POS(movePos.x, (VisibleRect::left().x+ballSize.width / 2.0), (VisibleRect::right().x - ballSize.width / 2.0));
    FIX_POS(movePos.y, (VisibleRect::bottom().y+ballSize.height / 2.0), (VisibleRect::top().y - ballSize.height / 2.0));
    m_plSprite->setPosition(movePos);
    
}



