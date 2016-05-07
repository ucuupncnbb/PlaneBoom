#ifndef __BATTLE_CONTROL_H_
#define __BATTLE_CONTROL_H_

#include "../common/Def.h"
#include "BattleView.h"
#include "BattleModel.h"

class BattleControl
{
public:
    CREATE_SINGLE_CLASS(BattleControl);
    ~BattleControl();
public:
    void intiBattle(Node *parent);
    void startBattle();
    void update(float f);
    
private:
    constexpr static float BALL_MOVE_SPEED = 10;
    int _moveBallTime;
    EventDispatcher* _eventDispatcher;
    BattleView* m_view;
    BattleModel* m_model;
    Scene* m_parentScene;
    bool m_isStart;
    int m_moveTime;
    int m_moveDistan;
private:
    void startMovePlane();
    void startCreateDot();
    void moveBall();
    
};


#endif
