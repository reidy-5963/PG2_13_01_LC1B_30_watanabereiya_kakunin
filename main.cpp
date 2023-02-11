#include <Novice.h>
#include <Player.h>
#include <Enemy.h>

const char kWindowTitle[] = "学籍番号";

void CheckHitDistance(Object* obj1, Object* obj2) {
	float XDis = obj1->GetPos().x - obj2->GetPos().x;
	float YDis = obj1->GetPos().y - obj2->GetPos().y;
	float range = (obj1->GetRange()) + (obj2->GetRange());

	float distance = XDis * XDis + YDis * YDis;
	float ranDis = range * range;
	if (distance < ranDis) {
		obj1->HitAction(obj2->Id());
		obj2->HitAction(obj1->Id());
	}
}

int Enemy::count;

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};


	Enemy* enemy1 = new Enemy({ 500, 600 }, { -5, 0 }, 32);
	Enemy* enemy2 = new Enemy({ 500, 500 }, { 3, 0 }, 32);
	BulletManager* bullet = new BulletManager();;
	Player* player = new Player({ 500, 200 }, { 3, 3 }, 32, bullet);

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///
		
		if (keys[DIK_R] && !preKeys[DIK_R]) {
			//player->Initi();
			//bullet->Initi();
			enemy1->Initi({ 500, 600 }, { -5, 0 }, 32);
			enemy2->Initi({ 500, 500 }, { 3, 0 }, 32);
		}

		player->Update(keys, preKeys);
		bullet->Update(keys, preKeys);

		enemy1->Update();
		enemy2->Update();


		CheckHitDistance(player, enemy1);
		CheckHitDistance(player, enemy2);

		for (int i = 0; i < 50; i++) {
			if (enemy1->GetisActive()) {
				if (bullet->GetBullet(i) != NULL) {
					CheckHitDistance(enemy1, bullet->GetBullet(i));
				}
			}
			if (enemy2->GetisActive()) {
				if (bullet->GetBullet(i) != NULL) {

					CheckHitDistance(enemy2, bullet->GetBullet(i));
				}
			}
		}


		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///
		
		Novice::ScreenPrintf(0, 0, "%d", Enemy::count);
		
		player->Draw();
		bullet->Draw();

		enemy1->Draw();
		enemy2->Draw();

		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
