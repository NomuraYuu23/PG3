#include <stdio.h>

/// <summary>
/// 2つの引数の値を比べて小さい値を返す関数
/// </summary>
/// <typeparam name="T">型</typeparam>
/// <param name="a">数字1</param>
/// <param name="b">数字2</param>
/// <returns>小さい値</returns>
template <typename T>
T Min(T a, T b) {

	if (a <= b) {
		return static_cast<T>(a);
	}
	else {
		return static_cast<T>(b);
	}

}

/// <summary>
/// 2つの引数の値を比べて小さい値を返す関数、char型の場合
/// </summary>
/// <param name="a">数字1</param>
/// <param name="b">数字2</param>
/// <returns>NULL</returns>
template<>
char Min<char>(char a, char b) {

	printf("数字以外は代入できません");

	return NULL;

}

int main() {
	
	//変数
	//int型
	int intA = 10;
	int intB = 20;
	int intResult = 0;
	//float型
	float floatA = 10.5f;
	float floatB = 10.2f;
	float floatResult = 0.0f;
	//double型
	double doubleA = 10.3;
	double doubleB = 10.8;
	double doubleResult = 0.0;
	//char型
	char charA = 'A';
	char charB = 'B';
	char charResult = NULL;

	//関数Min呼び出し
	//int型
	intResult = Min<int>(intA, intB);
	printf("%d\n", intResult);
	//float型
	floatResult = Min<float>(floatA, floatB);
	printf("%f\n", floatResult);
	//double型
	doubleResult = Min<double>(doubleA, doubleB);
	printf("%lf\n", doubleResult);
	//char型
	charResult = Min<char>(charA, charB);
	printf("%c\n", charResult);

	return 0;

}