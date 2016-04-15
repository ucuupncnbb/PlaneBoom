#ifndef __DEF_FILE__
#define __DEF_FILE__

#include "cocos2d.h"

#include "LayoutUtil.h"
//#include "StrConstMgr.h"


//def single class
#define CREATE_SINGLE_CLASS(AAA) public: \
static AAA* getInstance()\
{   if (instance == NULL) {instance = new AAA();return instance;}\
    else {return instance;}\
}\
private:\
AAA();\
AAA(const AAA&);\
AAA& operator=(const AAA&);\
static AAA* instance;\


//Def String
#define DEL_CONST_STRING(key) extern const char* key;

#define DEF_CONST_STRING(key,value) const char* key = value;

#define GET_CONST_STRING(key)  StringRes::key



#include "StrConstMgr.h"
#include "ResourceName.h"
//using namespace ResourceName;

#endif