#pragma once

#include <base.h>

class Bullet : public Object {
public:
	Bullet(Vector2 pos, Vector2 velo) {
		pos_ = pos;
		velo_ = velo;
		radius_ = 16;
		isActive = true;
	//	textureGH = Novice::LoadTexture("./Resources/Images/object/bullet.png");

	}

	~Bullet() {

	}


	void Update() ;


	void Draw() ;

	void HitAction(int id) override {
		isActive = false;
	}

	bool GetisActive() {
		return isActive;
	}

	int Id() {
		return BULLET_ID;
	}
protected:

	bool isActive = false;
};