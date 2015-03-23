//
//  LwfLayer.cpp
//  LWFProject
//
//  Created by albatrus on 2015/03/24.
//
//

#include "LwfLayer.h"
#include "lwf_cocos2dx.h"

#define WIN_SIZE Director::getInstance()->getVisibleSize()

Scene *LwfLayer::createScene(){
    
    auto _scene = Scene::create();
    auto _lwf = LwfLayer::create();
    _scene->addChild(_lwf);
    
    return _scene;
    
}

LwfLayer::LwfLayer()
:_isPlayLWF(false)
{
    
}

LwfLayer::~LwfLayer(){
    
    
}

bool LwfLayer::init(){
    
    
    if(!Layer::init()){
        
        return false;
    }
    

    auto _winSize = Director::getInstance()->getVisibleSize();

    
    //logo
    auto _logo = Sprite::create("cocos2dx-lwf.png");
    _logo->setScale(1.2f);
    _logo->setPosition(Point(_winSize.width - _logo->getContentSize().width,_winSize.height-_logo->getContentSize().height));
    addChild(_logo);
    
    
    //button
    auto image = Sprite::create("lwf-button.png");
    auto image2hover = Sprite::create("lwf-button-hover.png");
    
    
    
    //戻るボタン
    auto item1 = MenuItemSprite::create(image, image2hover,[this](Ref *sender){
        
        if(!_isPlayLWF){
            
            this->setIsPlayerLwf(true);
            
            //テクスチャアトラスを利用しない場合。
            /*
            const char *path = "LwfTest2/lwftest.lwf";
            auto lwfNode = LWFNode::create(path);
            
            lwfNode->lwf->AddEventHandler("done", [=](LWF::Movie *, LWF::Button *){
                
                log("lwf");
                
                this->setIsPlayerLwf(false);
                lwfNode->lwf->StopMovie("_root");
             　  lwfNode->requestRemoveFromParent();

            });
            
            
            lwfNode->setPosition(WIN_SIZE.width/4,WIN_SIZE.height/4);
            lwfNode->lwf->FitForHeight(WIN_SIZE.width/2, WIN_SIZE.height/2);
            this->addChild(lwfNode);
            */
            
            //テクスチャアトラス利用
           
             const char *path = "LwfTest/lwftest.lwf";
             auto *lwfNode = LWFNode::create(path);
             SpriteBatchNode *batch = SpriteBatchNode::createWithTexture(lwfNode->getTexture());
             batch->addChild(lwfNode);
             
             lwfNode->lwf->AddEventHandler("done", [=](LWF::Movie *, LWF::Button *){
             
             
                 log("lwf");
             
             
                 this->setIsPlayerLwf(false);
             
                 lwfNode->lwf->StopMovie("_root");
                 
                 lwfNode->requestRemoveFromParent();

             });
             
             lwfNode->setPosition(WIN_SIZE.width/4,WIN_SIZE.height/5);
             lwfNode->lwf->FitForHeight(WIN_SIZE.width/2, WIN_SIZE.height/2);
             this->addChild(batch);
            
            
        }
        
       
        
    });
    
    item1->setPosition(WIN_SIZE.width/2,WIN_SIZE.height/4);
    
    
    auto _menu = Menu::create(item1, NULL);
    _menu->setPosition(Point::ZERO);
    addChild(_menu);
    
    
    

    return true;
    
    
    
}


void LwfLayer::actionLwf(){
    
    
}