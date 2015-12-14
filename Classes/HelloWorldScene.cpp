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
    
    std::vector<cocos2d::Sprite*> sprites;
    sprites.push_back(createRandomSprite("caw1.png"));
    sprites.push_back(createRandomSprite("fish1.png"));
    sprites.push_back(createRandomSprite("pmang1.png"));
    sprites.push_back(createRandomSprite("carrot1.png"));
    sprites.push_back(createRandomSprite("cook1.png"));
    sprites.push_back(createRandomSprite("egg1.png"));
    sprites.push_back(createRandomSprite("leaf1.png"));
    sprites.push_back(createRandomSprite("pig1.png"));
    sprites.push_back(createRandomSprite("tomato1.png"));
    
    //位置を設定

    //画面に追加をしています。
    for(auto s : sprites){
       addChild(s);
    }

    //auto rootNode = CSLoader::createNode("MainScene.csb");

    //addChild(rootNode);

    return true;
}

cocos2d::Sprite* HelloWorld::createRandomSprite(std::string fileName){
    auto windowSize = Director::getInstance()->getWinSize();
    auto sprite = Sprite::create(fileName);
    sprite->setPosition(getRandomPosition(sprite));
    sprite->runAction(MoveTo::create(10, getRandomPosition(sprite)));
    return sprite;
}

cocos2d::Vec2 HelloWorld::getRandomPosition(cocos2d::Sprite* sprite){
    auto windowSize = Director::getInstance()->getWinSize();
    auto spriteSize = sprite->getContentSize();
    return Vec2(rand() % (int)(windowSize.width - spriteSize.width), rand() % (int)(windowSize.height - sprite->getContentSize().height));
}

