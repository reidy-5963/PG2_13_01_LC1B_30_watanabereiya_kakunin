#pragma once
#include <base.h>
#include <BulletManager.h>

class BulletManager;

void CheckHitDistance(Object* obj1, Object* obj2);

class Player : public Object {
public:
	Player(Vector2 pos, Vector2 velo, float radius, BulletManager* bulletManager);
	~Player();




	void Move(char* keys, char* preKeys);


	void Initi();

	void Update(char* keys, char* preKeys);

	void Draw();

	void HitAction(int id) override {
		
	}


	int Id() override{
		return PLAYER_ID;
	}
private:
	BulletManager* bulletManager_;

};