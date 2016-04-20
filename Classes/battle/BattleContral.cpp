#include "BattleContral.h"
#include "BattleModel.h"
#include "BattleView.h"


//BattleContral::BattleContral() 
//{
//}
//BattleContral::~BattleContral()
//{
//
//}

void BattleControl::intiBattle(Node* parent)
{
    m_model =  new BattleModel();
    m_view = new BattleView(parent);
}
void BattleControl::startBattle()
{

}