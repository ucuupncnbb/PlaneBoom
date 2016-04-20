#ifndef __BATTLE_CONTRAL_H_
#define __BATTLE_CONTRAL_H_

#include "def.h"
#include "BattleView.h"
#include "BattleModel.h"

class BattleContral
{
public:
    BattleContral();
    ~BattleContral();
    
private:
    BattleView _view;
    BattleModel _model;
};


#endif
