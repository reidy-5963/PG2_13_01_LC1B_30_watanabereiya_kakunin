#include <Bullet.h>




void Bullet::Update() {
	if (pos_.y > 720 - radius_) {
		isActive = false;
	}


	if (isActive) {
		pos_.y += velo_.y;
	}
}
void Bullet::Draw() {

	Novice::DrawEllipse(pos_.x, WorldPos(pos_.y, 720), radius_, radius_, 0.0f, 0x0000FFFF, kFillModeSolid);
}