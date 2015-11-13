#ifndef _COLOR_CHANGE_H_
#define _COLOR_CHENGE_H_

#include "cocos2d.h"
#include "../PanelCore.h"
#include <array>

class ColorChange{
public:
	ColorChange();
	~ColorChange();
public:
	void changeColor(cocos2d::Node* node, int value, PanelContainer container);
	void setPanel(cocos2d::Node* node, int value, PanelContainer container);
	void posCast(cocos2d::Node* node, int value, PanelContainer container);
	//色変え実行
	void checkColor(cocos2d::Node* node, int value, PanelContainer container);
	void setColor(StagePanel* node, int value);
	void allClear();
public:
	int mCount;
	int mChangePanelNum;
	cocos2d::Vec2 mBaseLine;
	cocos2d::Vec2 mCharaLine;
	cocos2d::Vec2 mPanelLine;
	std::array<int, 25> mTestArray;
};

#endif