#pragma once

#include <Novice.h>

struct Vector2 {
	float x;
	float y;
};

class Object {
public:
	Object() {}

	~Object() {}

	float WorldPos(float posY, const int kWindowHeight) {
		posY = posY * -1 + kWindowHeight;
		return posY;
	}

	Vector2 GetPos() {
		return pos_;
	}
	float GetRange() {
		return radius_;
	}

	virtual int Id() {
		return 0;
	}

	virtual void HitAction(int id) {};

protected:
	Vector2 pos_ = { 0, 0 };
	Vector2 velo_ = { 0, 0 };
	float  radius_ = 0;
	//int textureGH = 0;
};


enum {
	PLAYER_ID,
	ENEMY_ID,
	BULLET_ID
};


