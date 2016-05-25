#include "SkillBase.h"



SkillBase::SkillBase(const std::string& filename,int type)
{
    this->create(filename);
    m_skillType = type;

}