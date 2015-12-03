﻿#include "GameMainState.h"
#include "Utility/SceneSupport/SceneCreator.h"
#include "Game/Test/TestScene.h"
#include "Game/Object/StageObject/StageMap/StagePanel.h"
#include "../../../Utility/FileIO/CharaReader.h"

using namespace cocos2d;

GameMainState* GameMainState::create(Layer* layer){

	auto obj = new GameMainState();
	
	if (obj && obj->init(layer)){
		obj->retain();
		obj->autorelease();
		return obj;
	}

	CC_SAFE_DELETE(obj);
	return nullptr;
}

bool GameMainState::init(Layer* layer){
	mSceneState = FADEIN;
	mUpdateState = UPDATESTART;
	parentLayer = layer;


	mStageManager = StageManager::create();

	parentLayer->addChild(mStageManager);

	mCount = 0;

	camera = new cocos2d::ActionCamera();
	camera->autorelease();
	/*camera->setTarget(layer);
	auto eye = camera->getEye();
	eye.y = -0.0000003;
	camera->setEye(eye);*/
	camera->startWithTarget(layer);

	return true;
}

void GameMainState::update(float at){

	(this->*updateFunc[mSceneState])(at);
}

void GameMainState::fadeIn(float at){
	mSceneState = MAIN;
}

void GameMainState::sceneMain(float at){
	(this->*mainFunc[mUpdateState])(at);
}

void GameMainState::fadeOut(float at){	
	mSceneState = FADEIN;	
}

void GameMainState::mainStart(float at){
	mUpdateState = UPDATELOOP;
}

void GameMainState::mainLoop(float at){
	mStageManager;
}

void GameMainState::mainEnd(float at){
	mUpdateState = UPDATESTART;
	mSceneState = FADEOUT;
}


bool GameMainState::onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event){

	Vec2 touchPoint = touch->getLocation();
	
	mStageManager->onTouchBegan(touch,event);
	
	return true;
}

void GameMainState::onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event){
	mStageManager->onTouchEnd(touch->getLocation());
}