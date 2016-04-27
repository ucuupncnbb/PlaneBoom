
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
    
    BattleModel::getInstance()->initModel();
    //create plane
    if( BattleModel::getInstance()->createPlaneModel() )
    {
        m_view->createPlane();
    }
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
    this->startCreateDot();
}

void BattleControl::startCreateDot()
{
    timeval t_rand;
    gettimeofday(&t_rand, NULL);
    long i_rand = t_rand.tv_sec * 1000+ t_rand.tv_usec/1000;
    srand((int)i_rand);
    int randCreate = (int)rand() % (int)BattleModel::getInstance()->m_dotTotalPorba;
    
    if(randCreate < BattleModel::getInstance()->m_dotCretePorba)
    {
        int index = BattleModel::getInstance()->createOneDotModel();
        auto tempDot = BattleModel::getInstance()->getBallByID(index);
        m_view->createOneBall(tempDot->m_pos,index);
    }
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







