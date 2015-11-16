﻿#include "GameMainState.h"
#include "Utility/SceneSupport/SceneCreator.h"
#include "Game/Test/TestScene.h"
#include "Game/Object/StageObject/StageMap/StagePanel.h"
#include "../../../Utility/FileIO/CharaReader.h"
#include "Game/Scene/GameMain/Sequence/SequenceManager.h"
#include "Game/Scene/GameMain/Sequence/OperationSequence.h"

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
	SequenceManager::GetInstance()->init();
	SequenceManager::GetInstance()->nextScene(new OperationSequence(mStageManager));

	mUpdateState = UPDATELOOP;
}

void GameMainState::mainLoop(float at){
	mStageManager;

	if (SequenceManager::GetInstance()->update(at)) mUpdateState = UPDATEEND;
}

void GameMainState::mainEnd(float at){
	mUpdateState = UPDATESTART;
	mSceneState = FADEOUT;
}


bool GameMainState::onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event){

	SequenceManager::GetInstance()->onTouchBegan(touch, event);
	
	return true;
}

void GameMainState::onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event){

	SequenceManager::GetInstance()->onTouchEnded(touch, event);
}