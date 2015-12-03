#include "BattleSequence.h"
#include "SequenceManager.h"
#include "EndSequence.h"
#include "Game\Object\StageObject\StageMap/StageManager.h"


BattelSequence::BattelSequence(StageManager* stageManager) :ISequence(stageManager)
{
	mState = S_START;
}


BattelSequence::~BattelSequence()
{
}

S_STATUS BattelSequence::update(float at){

	if (mState < S_NULL){
		(this->*updateFunc[mState])(at);
	}

	return mState;
}

void BattelSequence::start(float at){
	CCLOG("BattleStart" + 0);
	container1 = mStageManager->getCharaContainer(1);
	container2 = mStageManager->getCharaContainer(2);
	mState = S_MAIN;
}

void BattelSequence::main(float at){
	CCLOG("BattleMain" + 0);
	container1.at(1)->getParameter();
	mState = S_END;
}

void BattelSequence::end(float at){
	CCLOG("BattleEnd" + 0);

	SequenceManager::GetInstance()->nextScene(new EndSequence(mStageManager));
	mState = S_NULL;
}

bool BattelSequence::onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event){

	cocos2d::Vec2 touchPoint = touch->getLocation();

	mStageManager->onTouchBegan(touchPoint);

	return true;
}

bool BattelSequence::onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event){

	return true;
}

void BattelSequence::onEndSequence(){

}

void BattelSequence::speedCheck() {
	for (int i = 0; i < container1.size(); ++i) {
		container1.at(i)->getParameter().speed;
	}
}