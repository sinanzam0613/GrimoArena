#include "CharacterManager.h"
#include "Character.h"
#include "Game/Scene/GameMain/Sequence/SequenceManager.h"
#define MAX_ARRAY  25
using namespace cocos2d;

using namespace cocos2d;

CharacterManager::CharacterManager()
{
	container1.clear();
	container2.clear();
}

CharacterManager::~CharacterManager()
{
	//保持しているキャラクターをすべて削除
	CharacterContainer::iterator i = container1.begin();
	while (i != container1.end())
	{
		CC_SAFE_RELEASE(*i);
		++i;
	}
	CharacterContainer::iterator i2 = container2.begin();
	while (i2 != container2.end())
	{
		CC_SAFE_RELEASE(*i2);
		++i2;
	}
}

bool CharacterManager::init()
{
	return true;
}

void CharacterManager::update(test_FUNC func)
{
	static int i = 0;
	i++;
	//コールバックで移動先のパネルの色を変えます
	/*if (i % 60 == 0){
		std::for_each(container1.begin(), container1.end(), [func](Character* obj){
			obj->setPositionY(obj->getPositionY() + 64);
			
			cocos2d::Vec2 pos = obj->getPosition() - cocos2d::Vec2(0,19);
			int number = (((int)obj->getPositionX() - 32) / 64)  + (((int)obj->getPositionY() - 160) / 64 * 9);
			func(number);
		});
	}*/
}

void CharacterManager::add(Character* character){
	addChild(character);
	if (SequenceManager::GetInstance()->getTurnPlayer() == TURN_PLAYER::PLAYER1) {
		container1.push_back(character);
	} else {
		container2.push_back(character);
	}
}

std::array<int, MAX_ARRAY> CharacterManager::getContainer(int id) {
	//ターンを貰って取ってくるコンテナを変える
	std::array<int, MAX_ARRAY> charavect{};

	if (container1.empty() || container1.size() < id ) return charavect;
	
	for (int i = 0; i < MAX_ARRAY; ++i) {
		//charavect[i] = container[id]->getParameter().vect[i];
		CCLOG("%i", (int)container1[0]->getParameter().vect[i]);
	}
	return charavect;
}

std::vector < Character* > CharacterManager::getContrainer(int count) {
	if (count == 1) {
		return container1;
	}
	return container2;
}

CharacterManager* CharacterManager::create()
{
	auto instance = new CharacterManager();

	if (instance && instance->init())
	{
		instance->autorelease();
		return instance;
	}

	CC_SAFE_DELETE(instance);
	return nullptr;
}

bool CharacterManager::onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event)
{
	if (container.empty())return false;
	for (auto& panel : container)
	{
		if (panel->onTouchBegan(touch, event))
		{
			parameter = panel->getParameter();
			return true;
		}
	}
	return false;
}