#include <iostream>
#include "Input.h"
#include "MaxPool.h"
#include <vector>
using namespace std;

//CNN 메인
int main() {
	image *in = new image(1, 3, 3, 3);
	vector<image*> top;
	vector<image*> bottom;
	top.reserve(2);
	top.push_back(in);
	
	top[0]->print();

	int a = 2;
	top[0]->setImageData(a, 4, 4, 4);
	top[0]->print();

	//test git
	// 한글이 안써지나요?
	return 0;
}