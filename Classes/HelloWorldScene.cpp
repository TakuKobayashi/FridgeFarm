#include "HelloWorldScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

USING_NS_CC;

using namespace cocostudio::timeline;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    sprites.push_back(new Food("caw1.png"));
    sprites.push_back(new Food("fish1.png"));
    sprites.push_back(new Food("pmang1.png"));
    sprites.push_back(new Food("carrot1.png"));
    sprites.push_back(new Food("cook1.png"));
    sprites.push_back(new Food("egg1.png"));
    sprites.push_back(new Food("leaf1.png"));
    sprites.push_back(new Food("pig1.png"));
    sprites.push_back(new Food("tomato1.png"));
    
    //位置を設定

    //画面に追加をしています。
    for(auto f : sprites){
       f->executeRandomMove();
       addChild(f->getSprite());
    }

    //auto rootNode = CSLoader::createNode("MainScene.csb");

    //addChild(rootNode);

    scheduleUpdate();
    return true;
}

void HelloWorld::update(float dt){
    executeTime += dt;
    if(30 < executeTime){
        for(auto f : sprites){
            f->spoil();
        }
    }
}

/*
cocos2d::Sprite* HelloWorld::createRandomSprite(std::string fileName){
    auto windowSize = Director::getInstance()->getWinSize();
    auto sprite = Sprite::create(fileName);
    sprite->setPosition(getRandomPosition(sprite));
    sprite->runAction(MoveTo::create(10, getRandomPosition(sprite)));
    //setRandomMove(sprite);
    return sprite;
}

cocos2d::Vec2 HelloWorld::getRandomPosition(cocos2d::Sprite* sprite){
    auto windowSize = Director::getInstance()->getWinSize();
    auto spriteSize = sprite->getContentSize();
    return Vec2(rand() % (int)(windowSize.width - spriteSize.width), rand() % (int)(windowSize.height - sprite->getContentSize().height));
}

void HelloWorld::setRandomMove(cocos2d::Sprite* sprite){
}
 */
