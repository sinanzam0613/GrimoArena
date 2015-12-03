#ifndef BATTLESEQUENCE_H
#define BATTLESEQUENCE_H

#include "ISequence.h"
#include <vector>
#include "../../../Character/CharacterFactory.h"
#include "../../../Character/CharacterManager.h"

class BattelSequence : public ISequence
{
public:
	BattelSequence(StageManager* stageManager);
	~BattelSequence();

	S_STATUS update(float at) override;					//更新

	void main(float at) override;						//メイン更新

	void start(float at) override;						//シークエンス初め

	void end(float at) override;						//シークエンス終わり

	void onEndSequence() override;

	/*----------------------------------------------------------------------
	|	・タッチ始め
	----------------------------------------------------------------------*/
	bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event) override;

	/*----------------------------------------------------------------------
	|	・タッチ終わり
	----------------------------------------------------------------------*/
	bool onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event) override;

	void speedCheck();
private:
	using CharacterContainer = std::vector < Character* >;
	CharacterContainer container1;
	using CharacterContainer = std::vector < Character* >;
	CharacterContainer container2;
};

#endif