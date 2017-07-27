#include "Scene_0.h"

using namespace cocos2d;


Scene* Scene_0::createScene()
{
	auto scene = Scene::create();
	auto layer = Scene_0::create();

	scene->addChild(layer);

	return scene;


}


bool Scene_0::init()
{
	
	return true;
}