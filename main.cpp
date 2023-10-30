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
/// <param name="funcArgument">関数ポインタの引数1</param>
void SetTimeOut(int second, std::function<void(int*)> func, int* funcArgument) {

	Sleep(second * 1000);

	func(funcArgument);

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
	std::function<void(int*)> displayResult = [](int* userInput) {

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

		if (answer == *userInput) {
			printf("あたりです\n");
		}
		else {
			printf("はずれです\n");
		}

	};

	// 三秒待つ
	SetTimeOut(3, displayResult, &userInput);

	return 0;

}
