#include <stdio.h>
#include <Windows.h>

/// <summary>
/// エネミークラス
/// </summary>
class Enemy {

public: 
	enum Phase {
		PhaseProximity,
		PhaseShooting,
		PhaseWithdrawal
	};

public: // メンバ関数

	void Initialize();

	void Update();

	void Proximity();

	void Shooting();

	void Withdrawal();

private:

	// メンバ関数ポインタのテーブル
	static void (Enemy::* spFuncTable[])();

	Phase phase_;

};

/// <summary>
/// エネミーのメンバ関数ポインタのテーブル
/// </summary>
void (Enemy::* Enemy::spFuncTable[])() = {
	&Enemy::Proximity, // 近接
	&Enemy::Shooting,  // 射撃
	&Enemy::Withdrawal // 離脱
};

void Enemy::Initialize()
{

	phase_ = Phase::PhaseProximity;

}

void Enemy::Update()
{

	// メンバ関数ポインタに入っている関数を呼び出す
	(this->*spFuncTable[static_cast<size_t>(phase_)])();

}

void Enemy::Proximity()
{

	printf("近接\n");
	phase_ = Phase::PhaseShooting;

}

void Enemy::Shooting()
{

	printf("射撃\n");
	phase_ = Phase::PhaseWithdrawal;

}

void Enemy::Withdrawal()
{

	printf("離脱\n");
	phase_ = Phase::PhaseProximity;

}

int main() {

	// エネミー宣言
	Enemy* enemy = new Enemy();
	enemy->Initialize();
	// 状態遷移回数
	int num = 3;

	for (size_t i = 0; i < num; i++) {
		// エネミー更新
		enemy->Update();
		// 1秒待つ
		Sleep(1000);
	}

	delete enemy;

	return 0;

}
