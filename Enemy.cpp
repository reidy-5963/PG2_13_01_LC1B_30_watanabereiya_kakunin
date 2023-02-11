#include <Enemy.h>


Enemy::Enemy(Vector2 pos, Vector2 velo, float radius) {
	pos_ = pos;
	velo_ = velo;
	radius_ = radius;
	isActive = true;
}

Enemy:: ~Enemy() {
}

void Enemy::Move() {
	if (pos_.x + radius_ > 1280 || pos_.x - radius_ < 0) {
		velo_.x *= -1;
	}

	if (pos_.y + radius_ > 720 || pos_.y - radius_ < 0) {
		velo_.y *= -1;
	}


	pos_.x += velo_.x;
	pos_.y += velo_.y;
}

void Enemy::Initi(Vector2 pos, Vector2 velo, float radius) {
	pos_ = pos;
	velo_ = velo;
	radius_ = radius;
	isActive = true;
	count = 0;
}

void Enemy::Update() {
	if (isActive) {
		Move();
		if (count > 0) {
			isActive = false;
		}
	}
	
}

bool Enemy::GetisActive() {
	return isActive;
}

void Enemy::Draw() {
	if (isActive) {
		Novice::DrawEllipse(pos_.x, WorldPos(pos_.y, 720), radius_, radius_, 0.0f, 0xFFFFFFFF, kFillModeSolid);
	}
}