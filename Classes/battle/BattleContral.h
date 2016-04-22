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
    
private:
    EventDispatcher* _eventDispatcher;
    BattleView* m_view;
    BattleModel* m_model;
    Scene* m_parentScene;
private:
    void startMovePlane();
};


#endif
