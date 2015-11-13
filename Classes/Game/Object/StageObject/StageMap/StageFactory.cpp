#include "StageFactory.h"
#include "StagePanel.h"

namespace {
#define MAXSTAGEX 9
#define MAXSTAGEY 11
}

using namespace cocos2d;

StageFactory::StageFactory(){}

StageFactory::~StageFactory(){}

void StageFactory::createPanel(PanelContainer* container,cocos2d::Node* node) {

	Vec2 createPosCount(0,0);
	//縦横枚数　そのうち外部から
	Vec2 createSize(MAXSTAGEX, MAXSTAGEY);
	Vec2 createPos(0,0);
	int panelSize = PANELSIZE;
	int createCount = createSize.x * createSize.y;
	int changeCount = 0;
	int count = 0;

	for (int i = 0; i < createCount; ++i) {
		auto panel = StagePanel::create("StagePanel" + std::to_string(i));
		panel->setContentSize(Size(panelSize, panelSize));
		node->addChild(panel);
		container->push_back(panel);
		//ビルボード
		/*auto camera = new cocos2d::ActionCamera();

		camera->autorelease();
		camera->setTarget(block);
		auto eye = camera->getEye();
		eye.y = 0.00000003;
		camera->setEye(eye);*/

		if (changeCount == createSize.x) {
			++createPosCount.y;
			changeCount = 0;
		}
		createPosCount.x = i % (int)createSize.x;
		++changeCount;
		++count;

		createPos.x = createPosCount.x * panelSize + 16;
		createPos.y = createPosCount.y * panelSize + 124;
		panel->setPosition(Vec2(
			createPos.x + panelSize, createPos.y + panelSize));

		CCLOG("%i", i);
	}
}
