#include "SkillBase.h"

void SkillBase::createOneSkill(const std::string& filename,int type)
{
    m_skillSpr = Sprite::create(filename);
    m_skillType = type;
}
