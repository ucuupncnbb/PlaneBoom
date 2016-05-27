#ifndef __SKILL_BASE_H__
#define __SKILL_BASE_H__

#include "cocos2d.h"

#include "../common/Def.h"

USING_NS_CC;

class SkillBase
{
public:
    void createOneSkill(const std::string& filename,int type);
public:
    int m_skillType;
    Sprite *m_skillSpr;
};



#endif