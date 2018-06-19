#include "MaxPool.h"
#include <iostream>
#include <vector>
#include <algorithm> // min. max
#include "Input.h"

using namespace std;

Max_Pool_Parameter::Max_Pool_Parameter(int window_h, int window_w, int stride_vertical, int stride_horizontal, int padding_vertical, int padding_horizontal) {
	this->window_h = window_h;
	this->window_w = window_w;
	this->stride_vertical = stride_vertical;
	this->stride_horizontal = stride_horizontal;
	this->padding_vertical = padding_vertical;
	this->padding_horizontal = padding_horizontal;
}



int Max_Pool_Parameter::pooled_h(int image_h) {
	// 정수가 아닌경우 일대 예외처리 아직안함.
	// Not yet exception integer
	return (image_h + 2 * padding_vertical - window_h) / stride_vertical + 1;
}
int Max_Pool_Parameter::pooled_w(int image_w) {
	return (image_w + 2 * padding_horizontal - window_w) / padding_horizontal + 1;
}
// Max_Pooling 함수
void Max_Pool_Parameter::Max_Pool(int batch_count, int in_channel, int in_height, int in_width, int pooled_h, int pooled_w, int pool_stride_vertical, int pool_stride_horizontal, int pool_padding_vertical, int pool_padding_horizontal,
	int pool_window_h, int pool_window_w, int *rgb, int *cpu_out_pooling_data) {
	for (int n = 0; n < batch_count; ++n) {
		for (int c = 0; c < in_channel; ++c) {
			for (int ph = 0; ph < pooled_h; ++ph) {
				for (int pw = 0; pw < pooled_w; ++pw) {
					int hstart = ph * pool_stride_vertical - pool_padding_vertical;
					int wstart = pw * pool_stride_horizontal - pool_padding_horizontal;
					int hend = min(hstart + pool_window_h, in_height);
					int wend = min(wstart + pool_window_w, in_width);
					hstart = max(hstart, 0);
					wstart = max(wstart, 0);
					//																	배치사이즈
					const int pool_index = ph * pooled_w + pw + (c*pooled_h*pooled_w) + (n * in_channel * pooled_h * pooled_w);
					for (int h = hstart; h < hend; ++h) {
						for (int w = wstart; w < wend; ++w) {
							const int index = h * in_width + w + (c*in_width*in_height) + (n* in_channel * in_width * in_height);
							if ((int)rgb[index] > cpu_out_pooling_data[pool_index]) {
								cpu_out_pooling_data[pool_index] = (int)rgb[index];
							}
						}
					}
				}
			}

		}
	}
}


void Max_Pool_Parameter::Max_Pool(vector<image> in, Max_Pool_Parameter para) {
	para.padding_horizontal;
	for (int n = 0; n < in[0].getBatch_size(); ++n) {
		for (int c = 0; c < in_channel; ++c) {
			for (int ph = 0; ph < pooled_h; ++ph) {
				for (int pw = 0; pw < pooled_w; ++pw) {
					int hstart = ph * pool_stride_vertical - pool_padding_vertical;
					int wstart = pw * pool_stride_horizontal - pool_padding_horizontal;
					int hend = min(hstart + pool_window_h, in_height);
					int wend = min(wstart + pool_window_w, in_width);
					hstart = max(hstart, 0);
					wstart = max(wstart, 0);
					//																	배치사이즈
					const int pool_index = ph * pooled_w + pw + (c*pooled_h*pooled_w) + (n * in_channel * pooled_h * pooled_w);
					for (int h = hstart; h < hend; ++h) {
						for (int w = wstart; w < wend; ++w) {
							const int index = h * in_width + w + (c*in_width*in_height) + (n* in_channel * in_width * in_height);
							if ((int)rgb[index] > cpu_out_pooling_data[pool_index]) {
								cpu_out_pooling_data[pool_index] = (int)rgb[index];
							}
						}
					}
				}
			}

		}
	}
}

//풀링연산 AVG



int Max_Pool_Parameter::getStride_vertical() {
	return this->stride_vertical
}
int Max_Pool_Parameter::getstride_horizontal() {
	return this->stride_horizontal
}
int Max_Pool_Parameter::getWindow_h() {
	return this->window_h;
}
int Max_Pool_Parameter::getWindow_w() {
	return this->window_w
}
int Max_Pool_Parameter::getPadding_vertical() {
	return this->padding_vertical
}
int Max_Pool_Parameter::getPadding_horizontal() {
	return this->padding_horizontal;
}