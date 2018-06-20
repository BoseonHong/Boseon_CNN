#pragma once
class image {
private:
	int batch_size;
	int channel;
	int height;
	int width;

	// 2018.06.20 데이터 추가
	int *data;

public:
	image(int b, int c, int h, int w);
	void setImageinfo(int b, int c, int h, int w);
	void setImageData(int *data);
	void print();
	int getBatch_size();
	int getChannel();
	int getHeight();
	int getWidth();
};