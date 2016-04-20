#ifndef __BATTLE_CONTROL_H_
#define __BATTLE_CONTROL_H_

#include "def.h"
#include "BattleView.h"
#include "BattleModel.h"

class BattleControl
{
public:
    CREATE_SINGLE_CLASS(BattleControl);
public:
    void intiBattle(Node *parent);
    void startBattle();
    
private:
    BattleView* m_view;
    BattleModel* m_model;
};


#endif
