#ifndef __BATTLE_MODEL_H__
#define __BATTLE_MODEL_H__
#include "../common/Def.h"
#include "SkillBase.h"
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
    void createOneSkill(Scene* parentScene);
    int createOneDotModel();
public:
    vector<BallModel*> m_ballVec;
     vector<SkillBase*> m_skillVec;
    PlaneModel* m_planeModel;
    
    //创建小球概率计算
    double m_dotCretePorba;
    double m_dotTotalPorba;
    
    //创建技能概率计算
    double m_skillCreate;
    double m_skillTotal;
public:
    BallModel* getBallByID(int index);
    
};




#endif