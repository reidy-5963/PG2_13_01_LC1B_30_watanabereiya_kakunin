#pragma once
#include <base.h>

void CheckHitDistance(Object* obj1, Object* obj2);


class Enemy : public Object {
public:
	static int count;

	Enemy(Vector2 pos, Vector2 velo, float radius);
	~Enemy();

	void Initi(Vector2 pos, Vector2 velo, float radius);

	void Move();

	void Update();

	void Draw();

	void HitAction(int id) override {
		if (id == BULLET_ID) {
			count++;
		}
	}


	int Id() override {
		return ENEMY_ID;
	}

	bool GetisActive();

private:
	bool isActive;
};;