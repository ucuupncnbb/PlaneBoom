
#include "BattleContral.h"
#include "BattleModel.h"
#include "BattleView.h"
#include "SkillBase.h"
#include "../ui/HomeScene.h"

BattleControl::BattleControl() : m_isStart(false),m_isDead(false)
{
    
}
BattleControl::~BattleControl()
{

}


void BattleControl::intiBattle(Node* parent)
{
    m_view = new BattleView(parent);
    m_parentScene = (Scene*)parent;
    m_moveTime = 30;
    m_moveDistan = 5;
    _moveBallTime = 0;
    
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
    m_isDead = false;
}
void BattleControl::update(float f)
{
    if( !m_isStart || m_isDead)
    {
        return ;
    }
    this->startCreateDot();
    this->startCreateSkill();
    
    if(_moveBallTime < 10)
    {
        _moveBallTime++;
    }
    else
    {
        this->moveBall();
        _moveBallTime = 0;
    }
    
    checkDead();
}

//碰撞检测  to do 点对点的碰撞
void BattleControl::checkDead()
{
    auto planeSpr = m_view->m_plSprite;
    Rect rectPlane =  planeSpr->getBoundingBox();
    
    auto ballMap = BattleModel::getInstance()->m_ballVec;
    
    for(auto iter=ballMap.begin(); iter!=ballMap.end(); ++iter)
    {
        int tag = (*iter)->m_tag;
        
        auto ball = m_parentScene->getChildByTag(tag);
        if(ball->getBoundingBox().intersectsRect(rectPlane) && (*iter)->m_isCanKill == true)
        {
            m_isDead = true;
            BattleModel::getInstance()->refreshGame(m_parentScene);
            //hit ,to do...
            auto scene = HomeScene::createScene();
            Director::getInstance()->replaceScene( TransitionSlideInT::create(1, scene));
            break;
        }
    }
}
void BattleControl::startCreateSkill()
{
    timeval t_rand;
    gettimeofday(&t_rand, NULL);
    long i_rand = t_rand.tv_sec * 1000+ t_rand.tv_usec/1000;
    srand((int)i_rand);
    int randCreate = (int)rand() % (int)BattleModel::getInstance()->m_skillTotal;
    
    if(randCreate < BattleModel::getInstance()->m_skillCreate)
    {
        BattleModel::getInstance()->createOneSkill(m_parentScene);
    }
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
void BattleControl::moveBall()
{
    auto ballMap = BattleModel::getInstance()->m_ballVec;
    Vec2 pPosVec = m_view->m_plSprite->getPosition();
    
    for(auto iter=ballMap.begin(); iter!=ballMap.end(); ++iter)
    {
        int tag = (*iter)->m_tag;
        
        auto ball = m_parentScene->getChildByTag(tag);
        Vec2 bPosVec = ball->getPosition();
        
        // move ball to plane
        ball->stopAllActions();
        double distance = pPosVec.distance(bPosVec);
        auto act = MoveTo::create(distance/BALL_MOVE_SPEED, pPosVec);
        ball->runAction(act);
    }
}







