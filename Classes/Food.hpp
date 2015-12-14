//
//  Food.hpp
//  fridge_farm
//
//  Created by 小林 拓 on 2015/12/14.
//
//

#ifndef Food_hpp
#define Food_hpp

#include "cocos2d.h"

class Food{
public:
    Food(std::string fileName); //コンストラクタ
    virtual ~Food();
    cocos2d::Sprite* getSprite();
    void executeRandomMove();
private:
    cocos2d::Sprite* mSprite;
    cocos2d::Vec2 getRandomPosition();
};

#endif /* Food_hpp */
