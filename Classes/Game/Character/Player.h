#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "Character.h"
/************************************************

 Player.h
 �쐬��:���їE�P

*************************************************/
class Player : public Character
{
public:
	//�R���X�g���N�^
	Player();

	//�f�X�g���N�^
	~Player();

	//������
	bool init(const cocos2d::Vec2& position)override;

	//�C���X�^���X�̐���
	static Player* create(const cocos2d::Vec2& position, int number);

	void setPosition(const cocos2d::Vec2& position);

	const cocos2d::Vec2& getPosition() const override;

	cocos2d::Rect getBoundingBox() const override;

private:
	
};

#endif