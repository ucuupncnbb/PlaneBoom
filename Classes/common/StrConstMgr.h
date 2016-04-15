#ifndef __CONST_STRING__
#define __CONST_STRING__

#include "cocos2d.h"
#include "Def.h"

#import<Def.h>

using namespace std;


namespace StringRes
{
    DEL_CONST_STRING(COVER_GAME_NAME);

};



//class StrConstMgr
//{
//public:
//    CREATE_SINGLE_CLASS(StrConstMgr);
//    
//public:
//    static map<string,string> m_strMap;
//    
//    static string getConstStr(string key)
//    {
//        if(m_strMap.find(key) != m_strMap.end())
//        {
//            return m_strMap[key];
//        }
//        else
//        {
//            return "";
//        }
//    }
//    static void setMapValue(string key,string value)
//    {
//        m_strMap[key] = value;
//    }
//};

#endif


