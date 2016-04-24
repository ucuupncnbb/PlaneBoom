
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
    
    
    m_view->createPlane();
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
    
    auto planeSpr = m_view->m_plSprite;
    
    auto listener = EventListenerAcceleration::create([=](Acceleration* acc, Event* event){
        
        m_view->updataPosition(acc);
        
    });
    
    m_parentScene->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, planeSpr);
}







