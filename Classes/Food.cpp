//
//  Food.cpp
//  fridge_farm
//
//  Created by 小林 拓 on 2015/12/14.
//
//

#include "Food.hpp"

Food::Food(std::string fileName)
{
    mSprite = cocos2d::Sprite::create(fileName);
    mSprite->setPosition(getRandomPosition());
}

Food::~Food()
{
    delete(mSprite);
}

cocos2d::Vec2 Food::getRandomPosition(){
    auto windowSize = cocos2d::Director::getInstance()->getWinSize();
    auto spriteSize = mSprite->getContentSize();
    return cocos2d::Vec2(rand() % (int)(windowSize.width - spriteSize.width), rand() % (int)(windowSize.height - spriteSize.height));
}

cocos2d::Sprite* Food::getSprite(){
    return mSprite;
}

void Food::executeRandomMove(){
    mSprite->runAction(cocos2d::MoveTo::create(10, getRandomPosition()));
    
    /*
     auto action = MoveTo::create(10, getRandomPosition(sprite));
     // ラムダ式でコールバックを設定する
     auto callback = CallFunc::create(this,callfunc_selector(HelloWorld::setRandomMove(sprite)));
     // アクションとコールバックをシーケンスに設定する
     auto seq = Sequence::create(action, callback, NULL);
     sprite->runAction(seq);
     */
}