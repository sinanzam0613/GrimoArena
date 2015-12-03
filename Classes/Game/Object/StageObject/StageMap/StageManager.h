﻿#ifndef _STAGE_MANAGER_H_
#define _STAGE_MANAGER_H_

#include "cocos2d.h"
#include <vector>
#include <string>
#include <array>
#include "StageFactory.h"
#include "../../../Character/CharacterFactory.h"
#include "../../../Character/CharacterManager.h"
#include "../../../Character/Player.h"
#include "../../../Character/PlayerManager.h"

class StagePanel;

class StageManager : public cocos2d::Node {
	
protected:
	
	StageManager() = default;
	
	~StageManager();
	
public:
	
	static StageManager* create();
	
	virtual bool init() override;

	void update(float at) override;

	void touchStage();

	int onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);

	void onTouchMove(cocos2d::Point pos);

	void onTouchEnd(cocos2d::Point pos);

	void reset();

	void changeColor(cocos2d::Node* node);

	void focusPanel(cocos2d::Node* node);

	StagePanel* getPanel(int number);

	int touchPos(cocos2d::Point pos);
	
	std::vector < Character* > getCharaContainer(int count);

	Player* getTurnPlayer();
private:
	PanelContainer m_Container;
	CharacterFactory factory;
	CharacterManager* manager;
	PlayerManager* playerManager;
	Player*            player;
	Parameter mParam;
	CharacterID mId;
	int mTestTrun;
	std::array<int, 25> mTestArray;
	using CharacterContainer = std::vector < Character* >;
	CharacterContainer container;

public:
	int				   mCount;
	int				   touchIdx;
	bool mIsChengeColor;

};

#endif