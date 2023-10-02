#include <stdio.h>

int Recursive(int time, int hourlyWage) {

	int wages = 0; //給料
	int nextHourlyWage = 0; //次の時給

	wages = hourlyWage;

	if (time - 1 > 0) {
		nextHourlyWage = hourlyWage * 2 - 50;
		wages += Recursive(time - 1, nextHourlyWage);
	}

	return wages;

}

int main() {

	//定数
	const int kGeneralHourlyWage = 1072; //一般的な賃金体系の時給
	const int kRecursiveHourlyWage = 100; //再帰的な賃金体系の最初の時給

	//変数
	int time = 0; //働く時間
	int wages = 0; //給料
	
	//何時間働くか
	printf("何時間働くか");
	scanf_s("%d", &time);

	//一般的な賃金体系
	wages = kGeneralHourlyWage * time;
	printf("一般的な賃金体系 %d円\n", wages);

	//再帰的な賃金体系
	wages = Recursive(time, kRecursiveHourlyWage);
	printf("再帰的な賃金体系 %d円\n", wages);

	return 0;

}