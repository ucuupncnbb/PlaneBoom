
#include "BattleContral.h"
#include "BattleModel.h"
#include "BattleView.h"


BattleControl::BattleControl()
{
    
}
BattleControl::~BattleControl()
{

}


void BattleControl::intiBattle(Node* parent)
{
    m_model = new BattleModel();
    m_view = new BattleView(parent);
    m_parentScene = (Scene*)parent;
}
void BattleControl::startBattle()
{
    this->startMovePlane();
}

void BattleControl::startMovePlane()
{
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    //Size size = Director::getInstance()->getVisibleSize();
    
    Device::setAccelerometerEnabled(true);
    
    auto planeSpr = m_view->plSprite;
    
    auto listener = EventListenerAcceleration::create([=](Acceleration* acc, Event* event){
        //planeSpr->setPosition(planeSpr->getPosition().x+1,planeSpr->getPosition().y+1);
        auto ballSize  = planeSpr->getContentSize();
        
        auto ptNow  = planeSpr->getPosition();
        
        log("acc: x = %lf, y = %lf", acc->x, acc->y);
        
        ptNow.x += acc->x * 19.81f;
        ptNow.y += acc->y * 19.81f;
        
        FIX_POS(ptNow.x, (VisibleRect::left().x+ballSize.width / 2.0), (VisibleRect::right().x - ballSize.width / 2.0));
        FIX_POS(ptNow.y, (VisibleRect::bottom().y+ballSize.height / 2.0), (VisibleRect::top().y - ballSize.height / 2.0));
        planeSpr->setPosition(ptNow);
    });
    
    m_parentScene->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, planeSpr);
}







