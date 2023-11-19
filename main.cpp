#include <stdio.h>
#include <Windows.h>
#include <ctime>
#include <cstdlib>
#include <functional>

typedef void (*PFunc)(int*);

/// <summary>
/// コールバック関数
/// </summary>
/// <param name="second">秒数</param>
/// <param name="p">関数ポインタ</param>
void SetTimeOut(int second, std::function<void()> func) {

	Sleep(second * 1000);

	func();

}

/// <summary>
/// メイン関数
/// </summary>
int main() {

	// 変数
	int userInput = 0;

	// 奇数か偶数入力受付
	printf("偶数なら0、奇数なら1を入力\n");
	do {
		scanf_s("%d", &userInput);
	} while (userInput != 0 && userInput != 1);

	// 結果表示
	printf("結果は");
	std::function<void()> displayResult = [=]() {

		int result = 0;
		int answer = 0;

		// ランダムで結果を決める
		std::srand(static_cast<unsigned int>(time(NULL)));
		result = rand() % 6 + 1;
		answer = result % 2;

		// 結果表示
		if (answer == 1) {
			printf("%d。奇数でした。\n", result);
		}
		else {
			printf("%d。偶数でした。\n", result);
		}

		if (answer == userInput) {
			printf("あたりです\n");
		}
		else {
			printf("はずれです\n");
		}

	};

	// 三秒待つ
	SetTimeOut(3, displayResult);

	return 0;

}
