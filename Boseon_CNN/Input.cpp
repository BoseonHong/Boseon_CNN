#include "Input.h"
#include <iostream>

using namespace std;

image::image(int b, int c, int h, int w) {
	this->batch_size = b;
	this->channel = c;
	this->height = h;
	this->width = w;
}
void image::setImageData(int b, int c, int h, int w) {
	this->batch_size = b;
	this->channel = c;
	this->height = h;
	this->width = w;
}
void image::print() {
	cout << this->batch_size << this->channel << this->height << this->width << endl;
}