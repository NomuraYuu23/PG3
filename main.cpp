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

