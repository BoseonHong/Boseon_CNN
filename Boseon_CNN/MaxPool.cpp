#include "MaxPool.h"
#include <iostream>
#include <vector>
#include <algorithm> // min. max

using namespace std;

// Max_Pooling 함수
void Max_Pool(int batch_count, int in_channel, int in_height, int in_width, int pooled_h, int pooled_w, int pool_stride_vertical, int pool_stride_horizontal, int pool_padding_vertical, int pool_padding_horizontal,
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


//풀링연산 AVG