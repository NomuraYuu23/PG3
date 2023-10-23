#include <stdio.h>

/// <summary>
/// 数学関数
/// </summary>
/// <typeparam name="T1"></typeparam>
/// <typeparam name="T2"></typeparam>
template <typename T1, typename T2>
class MyMath {
public:

	static double Min(T1 a, T2 b);

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
double  MyMath<T1, T2>::Min(T1 a, T2 b)
{

	if (static_cast<double>(a) < static_cast<double>(b)) {
		return static_cast<double>(a);
	}

	return static_cast<double>(b);

}

/// <summary>
/// メイン関数
/// </summary>
/// <returns></returns>
int main() {

	// 結果用変数
	double result = 0.0;

	// int, int
	result = MyMath<int, int>::Min(10, 20);
	printf("%lf\n", result);

	// float, float
	result = MyMath<float, float>::Min(0.1f, 0.2f);
	printf("%lf\n", result);

	// double, double
	result = MyMath<double, double>::Min(10.1, 0.1);
	printf("%lf\n", result);

	// int, float
	result = MyMath<int, int>::Min(10, 20.0f);
	printf("%lf\n", result);

	// int, double
	result = MyMath<float, float>::Min(10, 10.2);
	printf("%lf\n", result);

	// float, double
	result = MyMath<double, double>::Min(10.1f, 10.2);
	printf("%lf\n", result);

	return 0;

}
