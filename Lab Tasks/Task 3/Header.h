#pragma once
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int arraySum(int arr[][5], int size1, int size2) 
{
	int sum = 0;
	for (int i = 0; i < size1; i++)
	{
		for (int j = 0; j < size2; j++)
			sum += arr[i][j];
	}
	return sum;
}

int* rowSum(int arr[][4], int size1, int size2)			
{
	int sum = 0;
	int* ptr = new int[4];
	for (int i = 0; i < size1; i++)
	{
		sum = 0;
		for (int j = 0; j < size2; j++)
			sum += arr[i][j];
		*(ptr + i) = sum;
	}
	return ptr;
}

int* colSum(int arr[][4], int size1, int size2)			
{
	int sum = 0;
	int* ptr = new int[4];
	for (int i = 0; i < size1; i++)
	{
		sum = 0;
		for (int j = 0; j < size2; j++)
			sum += arr[j][i];					
		*(ptr + i) = sum;
	}
	return ptr;
}

int multiplyMatrix(int mat1[][4], int mat2[][4], int size1, int size2, int size3 , int size4)
{
	int sum = 0;
	for (int i = 0; i < size1; i++)
	{
		for (int j = 0; j < size2; j++)
		{
			for (int x = 0; x < 4; x++)
				sum += mat1[x][j] * mat2[i][x];
		}
	}
	return sum;
}

int** transposeMatrix(int arr[][2], int size1, int size2)
{
	int sum = 0;
	int** ptr = new int* [2];
	for (int i = 0; i < 2; i++)
		*(ptr + i) = new int[2];
	for (int i = 0; i < size1; i++)
	{
		for (int j = 0; j < size2; j++)
			ptr[i][j] = arr[j][i];
	}
	return ptr;
}

int** matrixSum(int arr[][3], int arr1[][3], int size1, int size2)
{
	int sum = 0;
	int** ptr = new int* [3];
	for (int i = 0; i < 3; i++)
		*(ptr + i) = new int[3];
	for (int i = 0; i < size1; i++)
	{
		for (int j = 0; j < size2; j++)
			ptr[i][j] = arr[i][j] + arr1[i][j];
	}
	return ptr;
}

int leftDiagonalSum(int arr[][4], int size1, int size2)
{
	int sum = 0;
	for (int i = 0; i < size1; i++)
	{
		for (int j = 0; j < size2; j++)
		{
			if (i == j)
				sum += arr[i][j];
		}
	}
	return sum;
}

int rightDiagonalSum(int arr[][4], int size1, int size2)
{
	int sum = 0;
	for (int i = 0; i < size1; i++)
	{
		for (int j = 0; j < size2; j++)
		{
			if (i + j == size2 - 1)
				sum += arr[i][j];
		}
	}
	return sum;
}

int* displayMiddleRow(int arr[][5], int size)
{
	int* ptr = new int[size];
	int mid = (size / 2);
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (i == mid)
				*(ptr + j) = arr[i][j];
		}
	}
	return ptr;
}

int* displayMiddleCol(int arr[][5], int size)
{
	int* ptr = new int[size];
	int mid = (size / 2);
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (j == mid)
				*(ptr + i) = arr[i][j];
		}
	}
	return ptr;
}

int* toIntArray(string str)
{
	int size = 0;
	while (str[size] != '\0')
		size++; 
	int* ptr = new int[size];
	for (int i = 0; i < size; i++)
		*(ptr + i) = int(str[i]) - 48;
	return ptr;
}

int* addTwoArray(string str1, string str2)
{
	int size = 0;
	while (str1[size] != '\0')
		size++;
	int* ptr = new int[size];
	for (int i = 0; i < size; i++)
		*(ptr + i) = (int(str1[i]) - 48) + (int(str2[i]) - 48);
	return ptr;
}

int* subTwoArray(string str1, string str2)
{
	int size = 0;
	while (str1[size] != '\0')
		size++;
	int* ptr = new int[size];
	for (int i = 0; i < size; i++)
		*(ptr + i) = (int(str1[i]) - 48) - (int(str2[i]) - 48);
	return ptr;
}
