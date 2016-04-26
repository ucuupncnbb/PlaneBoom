
#include "BattleContral.h"
#include "BattleModel.h"
#include "BattleView.h"


BattleControl::BattleControl() : m_isStart(false)
{
    
}
BattleControl::~BattleControl()
{

}


void BattleControl::intiBattle(Node* parent)
{
    m_view = new BattleView(parent);
    m_parentScene = (Scene*)parent;
    
    //create plane
    if( BattleModel::getInstance()->createPlaneModel() )
    {
        m_view->createPlane();
    }
    //test
    int index = BattleModel::getInstance()->createOneDotModel();

    auto tempDot = BattleModel::getInstance()->getBallByID(index);
    m_view->createOneBall(tempDot->m_pos,index);
    
}
void BattleControl::startBattle()
{
    this->startMovePlane();
    m_isStart = true;
    
}
void BattleControl::update(float f)
{
    if( !m_isStart )
    {
        return ;
    }
    //to do create enemy dot;
    
}

void BattleControl::startCreateDot()
{
    
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







