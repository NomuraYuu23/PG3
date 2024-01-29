#include <iostream>
#include <string>
#include <chrono>
using namespace std;

int main() {

	//現在時間を取得
	chrono::steady_clock::time_point begin = chrono::steady_clock::now();
	
	// 宣言
	string a(100000, 'a');

	//コピー
	begin = chrono::steady_clock::now();
	string copy = a;
	chrono::steady_clock::time_point copyTimePoint = chrono::steady_clock::now();
	chrono::microseconds copyTime = chrono::duration_cast<chrono::microseconds>(copyTimePoint - begin);

	// ムーブ
	begin = chrono::steady_clock::now();
	string move = std::move(a);
	chrono::steady_clock::time_point moveTimePoint = chrono::steady_clock::now();
	chrono::microseconds moveTime = chrono::duration_cast<chrono::microseconds>(moveTimePoint - begin);

	//表示
	cout << "コピー : " << copyTime.count() << "マイクロ秒" << endl;
	cout << "ムーブ : " << moveTime.count() << "マイクロ秒" << endl;

	return 0;

}