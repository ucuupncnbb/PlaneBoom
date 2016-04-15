#include "GameScene.h"
#include "HomeScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "Def.h"

USING_NS_CC;

using namespace cocostudio::timeline;

Scene* GameScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = GameScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool GameScene::init()
{
        //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    //add bg
    auto bgCover = Sprite::create(ResourceName::Images::GAME_BG);
    this->addChild(bgCover,10);
    LayoutUtil::layoutParentCenter(bgCover);
    
    auto label = Label::createWithTTF("Game Scene", "fonts/Marker Felt.ttf", 44);
    this->addChild(label,20);
    LayoutUtil::layoutParentTop(label,0,-150);
    
    //add menu
    auto stopItem = MenuItemImage::create(ResourceName::Images::START_SELE
                                          ,ResourceName::Images::START_NULL
                                          ,CC_CALLBACK_1(GameScene::stopMenuCallBack,this));
    auto menu = Menu::create(stopItem, nullptr);
    this->addChild(menu,20);
    LayoutUtil::layoutParentCenter(menu,0,0);

    LayoutUtil::layoutParentCenter(stopItem,0,-100);
    


    return true;
}

void GameScene::stopMenuCallBack(Ref* pSender)
{
    auto scene = HomeScene::createScene();
    // run
    Director::getInstance()->replaceScene( TransitionSlideInL::create(1, scene));
    
    return ;
}









