#include <iostream>

using namespace std;

class shape {
private:
	string name;
public:
	int width, height;
	string getName(string a) {
		name=a;
		return name;
	}
	double getArea(shape *p) {
		return (3.14) * width * height;
	}
	~shape();
};

shape::~shape() {
	cout << name << " ¼Ò¸êÀÚ ½ÇÇàÁß...";
}

int main() {
	shape p;
	p.width = 2;
	p.height = 24;

	cout << p.getName("»ï°¢±è¹ä ") << "³ÐÀÌ´Â " << p.getArea(&p)<<endl;


}