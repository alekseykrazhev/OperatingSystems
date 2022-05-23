#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<float.h>
#include"windows.h"

extern int min_n;
extern int max_n;
extern int mas_len;

void WINAPI min_max(LPVOID params) {

	float minValue = FLT_MAX;
	float maxValue = FLT_MIN;

	for (int i = 0; i < mas_len; i++) {
		if (minValue > ((float*)params)[i]) {
			minValue = ((float*)params)[i];
			min_n = i;
		}
		Sleep(7);
		if (maxValue < ((float*)params)[i]) {
			maxValue = ((float*)params)[i];
			max_n = i;
		}
		Sleep(7);
	}
	printf("Min Element:\n");
	printf("%f", minValue);
	printf("MaxElement\n");
	printf("%f", maxValue);
}