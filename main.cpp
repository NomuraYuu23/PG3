#include <stdio.h>
#include <list>
using namespace std;

int main() {

	// 山手線情報(1970年)
	list<const char*> yamanoteLine = {
		"Tokyo",
		"Kanda",
		"Akihabara",
		"Okachimachi",
		"Ueno",
		"Uguisudani",
		"Nippori",
		"Tabata",
		"Komagome",
		"Sugamo",
		"Otsuka",
		"Ikebukuro",
		"Mejiro",
		"Takadanobaba",
		"Shin-Okubo",
		"Shinjuku",
		"Yoyogi",
		"Harajuku",
		"Shibuya",
		"Ebisu",
		"Meguro",
		"Gotanda",
		"Osaki",
		"Shinagawa",
		"Tamachi",
		"Hamamatsucho",
		"Shimbashi",
		"Yurakucho",
	};

	// 表示する年代を入力
	enum InputData {
		year1970,
		year2019,
		year2022,
		close,
	};

	// 入力情報
	int inputData = 0;

	while (true)
	{

		// 入力
		do {
			printf("数字を入力\n");
			printf("1 : 1970年, 2 : 2019年, 3 : 2022年, 4 : 操作を終了\n");
			scanf_s("%d", &inputData);

		} while (1 > inputData || inputData > InputData::close + 1);

		//+1されてるので
		inputData--;
		if (inputData < InputData::close) {
			// データ挿入
			if (inputData > year1970) {
				for(list<const char*>::iterator itr = yamanoteLine.begin(); itr != yamanoteLine.end(); ++itr){
					if (*itr == "Tabata") {
						itr = yamanoteLine.insert(itr, "Nishi-Nippori");
						if (inputData > year2019) {
							++itr;
						}
						else {
							break;
						}
					}
					else if (*itr == "Tamachi") {
						itr = yamanoteLine.insert(itr, "Takanawa Gateway");
						break;
					}
				}
			}

			// 表示
			int No = 1;
			for (list<const char*>::iterator itr = yamanoteLine.begin(); itr != yamanoteLine.end(); ++itr) {
				printf("JY%d %s\n", No, *itr);
				No++;
			}
			printf("\n");

			// リストから削除
			if (inputData > year1970) {
				for (list<const char*>::iterator itr = yamanoteLine.begin(); itr != yamanoteLine.end(); ++itr) {
					if (*itr == "Nishi-Nippori") {
						itr = yamanoteLine.erase(itr);
						if (inputData == year2019) {
							break;
						}
					}
					else if (*itr == "Takanawa Gateway") {
						itr = yamanoteLine.erase(itr);
						break;
					}
				}
			}

		}
		else {
			// 終了
			break;
		}

	}

	return 0;

}