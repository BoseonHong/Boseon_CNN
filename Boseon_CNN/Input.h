#pragma once
class image {
private:
	int batch_size;
	int channel;
	int height;
	int width;
public:
	image(int b, int c, int h, int w);
	void setImageData(int b, int c, int h, int w);
	void print();
};