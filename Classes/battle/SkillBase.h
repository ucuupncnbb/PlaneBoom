#ifndef __SKILL_BASE_H__
#define __SKILL_BASE_H__

#include "cocos2d.h"

#include "../common/Def.h"

USING_NS_CC;

class SkillBase : Sprite
{
public:
    SkillBase(const std::string& filename,int type);
public:
    int m_skillType;

};



#endif