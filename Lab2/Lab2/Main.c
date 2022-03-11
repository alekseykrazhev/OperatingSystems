#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<float.h>
#include"windows.h"
#pragma warning(disable:4996)

extern void WINAPI min_max(LPVOID params);
extern void WINAPI average(LPVOID params);

int min_n = 0;
int max_n = 0;
float av_val;
int mas_len = 0;

int main() {
	printf("write array size\n");
	scanf("%d", &mas_len);

	HANDLE* threadArray = (HANDLE*)calloc(mas_len, sizeof(HANDLE));
	HANDLE MinMaxThread;
	HANDLE AverageThread;
	float* array = (float*)calloc(mas_len, sizeof(float));

	for (int i = 0; i < mas_len; i++) {


		float value = 0;
		printf("write array [%d] element value\n", i);
		scanf("%f", &value);
		array[i] = value;


	}

	printf("***********************\n");

	MinMaxThread = CreateThread(
		NULL,                   
		0,                      
		min_max,       
		array,          
		0,
		NULL);


	AverageThread = CreateThread(
		NULL,                   
		0,                      
		average,       
		array,          
		0,                      
		NULL);   


	WaitForSingleObject(MinMaxThread, INFINITE);
	WaitForSingleObject(AverageThread, INFINITE);

	array[min_n] = av_val;
	array[max_n] = av_val;

	printf("Result:\n");
	for (size_t i = 0; i < mas_len; i++)
	{
		printf("%f ", array[i]);
	}
	return 0;
}