#include "BattleModel.h"

//-----------------------------BallModel----------------------------
BallModel::BallModel()
{

}
BallModel::~BallModel()
{

}
void BallModel::createBall(Vec2 dir,Vec2 speed,Vec2 pos,int tag)
{
    m_direVec = dir;
    m_speed = speed;
    m_pos = pos;
    m_tag = tag;
    m_isCanKill = true;
}
//-----------------------------BallModel----------------------------
PlaneModel::PlaneModel()
{

}
PlaneModel::~PlaneModel()
{

}


//-----------------------------BattleModel----------------------------
BattleModel::BattleModel()
{

}
void BattleModel::initModel()
{
    // 创建敌人的概率
    m_dotCretePorba = 15;
    m_dotTotalPorba = 1000;
    
    //创建技能的概率
    m_skillCreate = 15;
    m_skillTotal = 1000;
}
bool BattleModel::createPlaneModel()
{
    return true;
}
BallModel* BattleModel::getBallByID(int index)
{
    int size = m_ballVec.size();
    for(int i=0; i<size; i++)
    {
        if(index == m_ballVec.at(i)->m_tag - OBJ_TAG_COUNT)
        {
            return m_ballVec.at(i);
        }
    }
    return nullptr;
}
void BattleModel::createOneSkill(Scene* parentScene)
{
    //随即常见不同类型技能
    auto skillTemp = new SkillBase();
    skillTemp->SkillBase::createOneSkill(ResourceName::Images::SKILL_1,0);
    parentScene->addChild(skillTemp->m_skillSpr,20);
    timeval t_rand;
    gettimeofday(&t_rand, NULL);
    long i_rand = t_rand.tv_sec * 1000+ t_rand.tv_usec/1000;
    srand((int)i_rand);
    int pos_X = (int)rand() % (int)LayoutUtil::getWidth();
    int pos_Y = (int)rand() % (int)LayoutUtil::getHeight();

    LayoutUtil::layoutParentLeftBottom(skillTemp->m_skillSpr,pos_X,pos_Y);
    
    m_skillVec.push_back(skillTemp);
}
int BattleModel::createOneDotModel()
{
    int index = m_ballVec.size();
    BallModel *dotTemp = new BallModel();
    
    m_ballVec.push_back(dotTemp);
    
    //rand to init data
    timeval t_rand;
    gettimeofday(&t_rand, NULL);
    long i_rand = t_rand.tv_sec * 1000+ t_rand.tv_usec/1000;
    srand((int)i_rand);
    int rX = (int)rand() % (int)LayoutUtil::DESIGN_HEIGHT;
    int rY = (int)rand() % (int)LayoutUtil::DESIGN_WIDTH;
    Vec2 pos= Vec2(rX,rY);
    
    Vec2 dir = Vec2(100,100);
    Vec2 speed = Vec2(100,100);
    
    dotTemp->createBall(dir,speed,pos,index + OBJ_TAG_COUNT);
    
    return index;
}
void BattleModel::refreshGame(Scene* parentScene)
{
    for(auto iter=m_ballVec.begin(); iter!=m_ballVec.end(); ++iter)
    {
        int tag = (*iter)->m_tag;
        
        auto ball = parentScene->getChildByTag(tag);
        ball->removeFromParent();
    }
    m_ballVec.clear();
    
    for(auto iter=m_skillVec.begin(); iter!=m_skillVec.end(); ++iter)
    {
        (*iter)->m_skillSpr->removeFromParent();
    }
    m_skillVec.clear();
}





