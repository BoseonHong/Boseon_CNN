#include <iostream>
#include "Input.h"
#include "MaxPool.h"
#include <vector>
using namespace std;

//CNN ∏ﬁ¿Œ
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

	
	Max_Pool_Parameter *Max_P =new Max_Pool_Parameter(2, 2, 2, 2, 0, 0);
	Max_P->pooled_h(2);
	// Max_P->Max_Pool(top);
	

	return 0;
}