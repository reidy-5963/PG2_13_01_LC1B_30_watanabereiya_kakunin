#include <Player.h>


Player::Player(Vector2 pos, Vector2 velo, float radius, BulletManager* bulletManager) {
	pos_ = pos;
	velo_ = velo;
	radius_ = radius;
	bulletManager_ = bulletManager;
}

Player::~Player() {
	delete bulletManager_;
}


void Player::Move(char* keys, char* preKeys) {
	if (keys[DIK_W]) {
		if (pos_.y > 720 - radius_) {
			pos_.y;
		}
		else {
			pos_.y += velo_.y;
		}

	}
	if (keys[DIK_S]) {
		if (pos_.y < 0 + radius_) {
			pos_.y;
		}
		else {
			pos_.y -= velo_.y;

		}
	}
	if (keys[DIK_A]) {
		if (pos_.x < 0 + radius_) {
			pos_.x;
		}
		else {
			pos_.x -= velo_.x;

		}
	}
	if (keys[DIK_D]) {
		if (pos_.x > 1280 - radius_) {
			pos_.x;
		}
		else {
			pos_.x += velo_.x;

		}
	}
}


void Player::Initi() {
	pos_ = {500, 200};
	velo_ = { 3, 3 };
	radius_ = 32;
}



void Player::Update(char* keys, char* preKeys) {
	Move(keys, preKeys);
	static int bull = 0;
	static Vector2 bullVelo = { 0, 10 };
	if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {
		bull++;
	}
	else {
		bull = 0;
	}
	if ((bull % 10) == 1) {
		bulletManager_->Shot(pos_, bullVelo);
	}

}

void Player::Draw() {
	Novice::DrawEllipse(pos_.x,WorldPos(pos_.y, 720), radius_, radius_, 0.0f, 0xFFFFFFFF, kFillModeSolid);
}

