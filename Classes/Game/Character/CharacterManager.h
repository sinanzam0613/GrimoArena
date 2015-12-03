#ifndef _CHARACTERMANAGER_H_
#define _CHARACTERMANAGER_H_

#include "cocos2d.h"
#include "Player.h"
#include <array>

class Character;

class CharacterManager : public cocos2d::Node
{
public:
	typedef std::function<void(int i)> test_FUNC;

	CharacterManager();
	~CharacterManager();
	bool init()override;
	void update(test_FUNC func);
	void add(Character* character);
	void findPara(int id);
	static CharacterManager* create();
	std::array<int, 25> getContainer(int id);
	std::vector < Character* > getContrainer(int mCount);

private:
	using CharacterContainer = std::vector < Character* > ;
	CharacterContainer container1;
	using CharacterContainer = std::vector < Character* >;
	CharacterContainer container2;
	Player* player;

};



#endif