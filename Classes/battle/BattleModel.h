#ifndef __BATTLE_MODEL_H__
#define __BATTLE_MODEL_H__
#include "../common/Def.h"
#include "cocos2d.h"

using namespace std;
USING_NS_CC;

class BallModel
{
public:
    BallModel();
    ~BallModel();
    void createBall(Vec2 dir,Vec2 speed,Vec2 pos,int tag);
public:
    int m_tag;
    bool m_isCanKill;
    Vec2 m_direVec;
    Vec2 m_speed;
    Vec2 m_pos;
};


class PlaneModel
{
public:
    PlaneModel();
    ~PlaneModel();

};

class BattleModel
{
public:
    CREATE_SINGLE_CLASS(BattleModel);
    void initModel();
    
    bool createPlaneModel();
    void refreshGame(Scene* parentScene);
    int createOneDotModel();
public:
    vector<BallModel*> m_ballVec;
    PlaneModel* m_planeModel;
    
    double m_dotCretePorba;
    double m_dotTotalPorba;
public:
    BallModel* getBallByID(int index);
    
};




#endif