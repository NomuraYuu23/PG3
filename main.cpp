#include <stdio.h>

class Finger {

public: // メンバ関数

	Finger() = default;
	~Finger() = default;

	virtual void NameDisplay() = 0;

protected: //メンバ変数

	const char* name_;

};

class Thumb : public Finger {

public: // メンバ関数

	Thumb();
	~Thumb();

	virtual void NameDisplay();

};

Thumb::Thumb()
{

	name_ = "親指\n";

}

Thumb::~Thumb()
{
}

void Thumb::NameDisplay()
{
}
