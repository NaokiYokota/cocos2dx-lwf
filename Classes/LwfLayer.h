//
//  LwfLayer.h
//  LWFProject
//
//  Created by albatrus on 2015/02/24.
//
//

#ifndef __LWFProject__LwfLayer__
#define __LWFProject__LwfLayer__

#include "cocos2d.h"

USING_NS_CC;

class LwfLayer : public Layer{
    
protected:
    
    void actionLwf();
    
    
    
public:
    LwfLayer();
    ~LwfLayer();
    
    
    virtual bool init();
    static Scene *createScene();
    CREATE_FUNC(LwfLayer);
    
    CC_SYNTHESIZE(bool, _isPlayLWF, IsPlayerLwf);
    
};

#endif /* defined(__LWFProject__LwfLayer__) */
