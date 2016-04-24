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
    void createPlane();
    void createOneBall();
    
    void updataAngle(double x,double y);
    void updataPosition(Acceleration* acc);
public:
    //Layer* m_MainLayer;
    Node* m_parentLayer;
    Sprite* m_plSprite;
};



#endif