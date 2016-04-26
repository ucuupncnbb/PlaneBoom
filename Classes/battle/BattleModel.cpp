#include "BattleModel.h"

//-----------------------------BallModel----------------------------
BallModel::BallModel()
{

}
BallModel::~BallModel()
{

}
void BallModel::createBall(Vec2 dir,Vec2 speed,Vec2 pos)
{
    m_direVec = dir;
    m_speed = speed;
    m_pos = pos;
}
//-----------------------------BallModel----------------------------
PlaneModel::PlaneModel()
{

}
PlaneModel::~PlaneModel()
{

}


//-----------------------------BattleModel----------------------------
BattleModel::BattleModel()
{

}
void BattleModel::initModel()
{

}
bool BattleModel::createPlaneModel()
{
    return true;
}
BallModel* BattleModel::getBallByID(int index)
{
    if(m_ballMap.find(index) != m_ballMap.end())
    {
        return m_ballMap[index];
    }
    else
    {
        return nullptr;
    }
}

int BattleModel::createOneDotModel()
{
    int index = m_ballMap.size();
    BallModel *dotTemp = new BallModel();
    
    m_ballMap[index] = dotTemp;
    
    //rand num
    Vec2 dir = Vec2(100,100);
    Vec2 speed = Vec2(100,100);
    Vec2 pos= Vec2(100,100);
    
    dotTemp->createBall(dir,speed,pos);
    
    return index;
}





