//
// cocos2d
//
#ifndef __CHIPMUNKTEST_H__
#define __CHIPMUNKTEST_H__

#include "cocos2d.h"
#include "chipmunk.h"
#include "../testBasic.h"
#include "extensions/cocos-ext.h"

USING_NS_CC_EXT;

class ChipmunkTestLayer : public Layer
{
public:
    ChipmunkTestLayer();
    ~ChipmunkTestLayer();
    void onEnter();
    void initPhysics();
    void createResetButton();
    void reset(Object* sender);

    void addNewSpriteAtPosition(Point p);
    void update(float dt);
    void toggleDebugCallback(Object* sender);
    void onTouchesEnded(const std::vector<Touch*>& touches, Event* event);
    virtual void onAcceleration(Acceleration* acc, Event* event);

private:
    Texture2D* _spriteTexture; // weak ref
#if CC_ENABLE_CHIPMUNK_INTEGRATION    
    PhysicsDebugNode* _debugLayer; // weak ref
#endif
    cpSpace* _space; // strong ref
    cpShape* _walls[4];
};

class ChipmunkAccelTouchTestScene : public TestScene
{
public:
    virtual void runThisTest();
};

#endif /* __CHIPMUNKACCELTOUCHTEST_H__ */
