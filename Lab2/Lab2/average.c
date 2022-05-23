#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<float.h>
#include"windows.h"
#pragma warning(disable:4996)

extern float av_val;
extern int mas_len;

void WINAPI average(LPVOID params) {
	av_val = 0;

	for (int i = 0; i < mas_len; i++) {
		av_val += ((float*)params)[i];
		Sleep(12);
	}
	av_val /= mas_len;
	printf("Average: \n");
	printf("%f", av_val);
}