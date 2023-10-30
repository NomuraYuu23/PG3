#include <stdio.h>

class IShape 
{

public: // メンバ関数

	// 面積を求める
	virtual void Size() = 0;

	// 値表示
	virtual void Draw() = 0;

protected: // メンバ変数

	// 面積
	float size_ = 0.0f;

};

class Circle : public IShape 
{

public: // メンバ関数

	// 面積を求める
	virtual void Size() override;

	// 値表示
	virtual void Draw() override;

public: // アクセッサ

	// 半径
	void SetRadius(float radius) { radius_ = radius; }

private: // メンバ変数

	// 半径
	float radius_ = 0.0f;

};

class Rectangle : public IShape
{

public: // メンバ関数

	// 面積を求める
	virtual void Size() override;

	// 値表示
	virtual void Draw() override;

public: // アクセッサ

	// 幅
	void SetWidth(float width) { width_ = width; }

	// 高さ
	void SetHeight(float height) { height_ = height; }

private: // メンバ変数

	// 幅
	float width_ = 0.0f;

	// 高さ
	float height_ = 0.0f;

};

void Circle::Size()
{

	float pi = 3.14f;

	size_ = radius_ * radius_ * pi;

}

void Circle::Draw()
{

	printf("円の面積%.2f\n", size_);

}

void Rectangle::Size()
{

	size_ = width_ * height_;

}

void Rectangle::Draw()
{

	printf("矩形の面積%.2f\n", size_);

}

int main() {

	// 円
	Circle circle;
	circle.SetRadius(2.0f);

	// 矩形
	Rectangle rectangle;
	rectangle.SetHeight(2.0f);
	rectangle.SetWidth(3.0f);

	// 計算
	circle.Size();
	rectangle.Size();

	// 表示
	circle.Draw();
	rectangle.Draw();

	return 0;

}
