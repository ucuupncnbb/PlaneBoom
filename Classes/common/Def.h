#ifndef __DEF_FILE__
#define __DEF_FILE__

#include "cocos2d.h"

#include "LayoutUtil.h"
#include "VisibleRect.h"
//#include "StrConstMgr.h"


//def single class
#define CREATE_SINGLE_CLASS(clazz) \
private: \
clazz(); \
clazz(const clazz&); \
clazz& operator=(const clazz&); \
public: \
static clazz* getInstance() { static clazz instance; return &instance; } \



//Def String
#define DEL_CONST_STRING(key) extern const char* key;

#define DEF_CONST_STRING(key,value) const char* key = value;

#define GET_CONST_STRING(key)  StringRes::key

//Def Object
#define DEL_READ_ONLY_OBJ(Type,Value,FunName) \
protected: Type Value;\
public: Type get##FunName(){return Value;}

#define DEL_WRITE_READ_OBJ(Type,Value,FunName) \
protected: Type Value;\
public: Type get##FunName(){return Value;}\
public: void set##FunName(Type temp){Value = temp;}

//fix pos
#define FIX_POS(_pos, _min, _max) \
if (_pos < _min)        \
_pos = _min;        \
else if (_pos > _max)   \
_pos = _max;        \

#include "StrConstMgr.h"
#include "ResourceName.h"
//using namespace ResourceName;

#endif