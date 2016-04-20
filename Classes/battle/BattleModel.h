#ifndef __BATTLE_MODEL_H__
#define __BATTLE_MODEL_H__
#include "Def.h"
#include "cocos2d.h"

USING_NS_CC;

class BallModel
{
    
};


class PlaneModel
{
    //DEL_WRITE_READ_OBJ(float,speedX,SpeedX);
    //DEL_WRITE_READ_OBJ(float,speedY,SpeedY);

};

class BattleModel
{
public:
    BattleModel();
    ~BattleModel();
public:
    vector<BallModel*> ballVec;
    PlaneModel* m_planeModel;
    

};




#endif