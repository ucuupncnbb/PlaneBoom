#ifndef __DEF_FILE__
#define __DEF_FILE__

#include "cocos2d.h"

#include "LayoutUtil.h"
//#include "StrConstMgr.h"


//def single class
#define CREATE_SINGLE_CLASS(AAA) \
private:\
AAA(){}\
AAA(const AAA&){}\
AAA& operator=(const AAA&){}\
public: static AAA* getInstance()\
{   static AAA* instance;\
    return instance;\
}\


//Def String
#define DEL_CONST_STRING(key) extern const char* key;

#define DEF_CONST_STRING(key,value) const char* key = value;

#define GET_CONST_STRING(key)  StringRes::key

//Def Object
#define DEL_READ_ONLY_OBJ(Type,Value,FunName) \
protected: Type Value;\
public: Type get#FunName(){return Value;}

#define DEL_WRITE_READ_OBJ(Type,Value,FunName) \
protected: Type Value;\
public: Type get#FunName(){return Value;}\
public: void set#FunName(Type temp){Value = temp;}


#include "StrConstMgr.h"
#include "ResourceName.h"
//using namespace ResourceName;

#endif