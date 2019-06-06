#pragma once
#include "pch.h"
#include <iostream>
#include <vector>
using namespace std;

class CSR {
private:
	int rows;
	int columns;
	int** Matrix;
public:
	vector<int> AN;
	vector<int> JA;
	vector<int> JR;

	CSR();
	CSR(int, int);
	CSR(const CSR&);
	CSR& operator=(const CSR&);
	void Boxing(void);
	void UnBoxing(void);
	void Add(int, int, int);
	void ShowMatrix(void);
	void ShowBoxing(void);
	int Columns(void);
	int Rows(void);
	~CSR() {
		if (Matrix != nullptr) {
			for (int i = 0; i < rows; i++)
				delete Matrix[i];
			delete Matrix;
		}
	}
};