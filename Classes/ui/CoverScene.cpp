#include "CoverScene.h"
#include "ReadyScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "../common/Def.h"

USING_NS_CC;

using namespace cocostudio::timeline;

Scene* CoverScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = CoverScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool CoverScene::init()
{
    /**  you can create scene with following comment code instead of using csb file.
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(CoverScene::menuCloseCallback, this));
    
	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    
    auto label = Label::createWithTTF("Hello World", "fonts/Marker Felt.ttf", 24);
    
    // position the label on the center of the screen
    label->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height));

    // add the label as a child to this layer
    this->addChild(label, 1);

    // add "CoverScene" splash screen"
    auto sprite = Sprite::create("CoverScene.png");

    // position the sprite on the center of the screen
    sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

    // add the sprite as a child to this layer
    this->addChild(sprite, 0);
    **/
    
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    //add bg
    auto bgCover = Sprite::create(ResourceName::Images::COVER_BG);
    this->addChild(bgCover,10);
    LayoutUtil::layoutParentCenter(bgCover);
    
    auto label = Label::createWithTTF(GET_CONST_STRING(COVER_GAME_NAME), "fonts/Marker Felt.ttf", 84);
    this->addChild(label,20);
    LayoutUtil::layoutParentTop(label,0,-150);
    
    //add menu
    auto startItem = MenuItemImage::create(ResourceName::Images::START_SELE
                                          ,ResourceName::Images::START_NULL
                                          ,CC_CALLBACK_1(CoverScene::startMenuCallBack,this));
    auto menu = Menu::create(startItem, nullptr);
    this->addChild(menu,20);
    LayoutUtil::layoutParentCenter(menu,0,0);

    LayoutUtil::layoutParentCenter(startItem,0,-100);
    


    return true;
}

void CoverScene::startMenuCallBack(Ref* pSender)
{
    auto scene = ReadyScene::createScene();
    // run
    Director::getInstance()->replaceScene( TransitionSlideInT::create(1, scene));
    
    return ;
}









