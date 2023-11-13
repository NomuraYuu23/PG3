#include <stdio.h>

/// <summary>
/// 数学関数
/// </summary>
/// <typeparam name="T1"></typeparam>
/// <typeparam name="T2"></typeparam>
template <typename T1, typename T2>
class MyMath {
public:

	static T1 Min(T1 a, T2 b);

};

/// <summary>
/// 最小比較関数
/// </summary>
/// <typeparam name="T1"></typeparam>
/// <typeparam name="T2"></typeparam>
/// <param name="a"></param>
/// <param name="b"></param>
/// <returns></returns>
template<typename T1, typename T2>
T1  MyMath<T1, T2>::Min(T1 a, T2 b)
{

	if (static_cast<T1>(a) < static_cast<T1>(b)) {
		return static_cast<T1>(a);
	}

	return static_cast<T1>(b);

}

/// <summary>
/// メイン関数
/// </summary>
/// <returns></returns>
int main() {

	// 結果用変数
	int resultInt = 0;
	float resultFloat = 0.0f;
	double resultDouble = 0.0;

	// int, int
	resultInt = MyMath<int, int>::Min(10, 20);
	printf("%d\n", resultInt);

	// float, float
	resultFloat = MyMath<float, float>::Min(0.1f, 0.2f);
	printf("%f\n", resultFloat);

	// double, double
	resultDouble = MyMath<double, double>::Min(10.1, 0.1);
	printf("%lf\n", resultDouble);

	// int, float
	resultInt = MyMath<int, float>::Min(10, 20.0f);
	printf("%d\n", resultInt);

	// int, double
	resultInt = MyMath<int, double>::Min(10, 10.2);
	printf("%d\n", resultInt);

	// float, double
	resultFloat = MyMath<float, double>::Min(10.1f, 10.2);
	printf("%lf\n", resultFloat);

	return 0;

}
