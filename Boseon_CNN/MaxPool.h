#pragma once

class Max_Pool_Parameter {
private:
	int stride_vertical;
	int stride_horizontal;
	int window_h;
	int window_w;
	int padding_vertical;
	int padding_horizontal;

public:
	Max_Pool_Parameter(int window_h, int window_w, int stride_vertical, int stride_horizontal, int padding_vertical, int padding_horizontal);
	int pooled_h(int image_h);
	int pooled_w(int image_w);
	void Max_Pool(int batch_count, int in_channel, int in_height, int in_width, int pooled_h, int pooled_w, int pool_stride_vertical, int pool_stride_horizontal, int pool_padding_vertical, int pool_padding_horizontal,
		int pool_window_h, int pool_window_w, int *rgb, int *cpu_out_pooling_data);
};
