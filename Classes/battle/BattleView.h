#ifndef __BATTLE_VIEW_H__
#define __BATTLE_VIEW_H__

#include "cocos2d.h"

#include "../common/Def.h"

USING_NS_CC;

class BattleView
{
public:
    BattleView(Node *parent);
    ~BattleView();
public:
    void createOneBall();
private:
    //Layer* m_MainLayer;
    Node* parentLayer;
    Sprite* plSprite;
};



#endif