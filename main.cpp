#include <stdio.h>

/// <summary>
/// 指クラス
/// </summary>
class Finger {

public: // メンバ関数

	Finger() = default;
	~Finger() = default;

	virtual void NameDisplay() = 0;

};

/// <summary>
/// 親指クラス
/// </summary>
class Thumb : public Finger {

public: // メンバ関数

	Thumb() = default;
	~Thumb() = default;

	virtual void NameDisplay();

};

void Thumb::NameDisplay()
{
	printf("親指\n");
}

/// <summary>
/// 人指し指クラス
/// </summary>
class IndexFinger : public Finger {

public: // メンバ関数

	IndexFinger() = default;
	~IndexFinger() = default;

	virtual void NameDisplay();

};

void IndexFinger::NameDisplay()
{
	printf("人指し指\n");
}

/// <summary>
/// 中指クラス
/// </summary>
class MiddleFinger : public Finger {

public: // メンバ関数

	MiddleFinger() = default;
	~MiddleFinger() = default;

	virtual void NameDisplay();

};

void MiddleFinger::NameDisplay()
{
	printf("中指\n");
}

/// <summary>
/// 薬指クラス
/// </summary>
class RingFinger : public Finger {

public: // メンバ関数

	RingFinger() = default;
	~RingFinger() = default;

	virtual void NameDisplay();

};

void RingFinger::NameDisplay()
{
	printf("薬指\n");
}

/// <summary>
/// 小指クラス
/// </summary>
class LittleFinger : public Finger {

public: // メンバ関数

	LittleFinger() = default;
	~LittleFinger() = default;

	virtual void NameDisplay();

};

void LittleFinger::NameDisplay()
{
	printf("小指\n");
}

/// <summary>
/// メイン関数
/// </summary>
/// <returns></returns>
int main() {

	Finger* fingers[5];
	fingers[0] = new Thumb();
	fingers[1] = new IndexFinger();
	fingers[2] = new MiddleFinger();
	fingers[3] = new RingFinger();
	fingers[4] = new LittleFinger();

	for (size_t i = 0; i < 5; i++) {
		fingers[i]->NameDisplay();
		delete fingers[i];
	}

}
