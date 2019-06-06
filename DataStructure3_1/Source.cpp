#include "pch.h"
#include <iostream>
#include "Header.h"
using namespace std;
CSR::CSR(void) {
	Matrix = nullptr;
	rows = 0;
	columns = 0;
}
CSR::CSR(int row, int column) {
	rows = row; columns = column;
	
	Matrix = new int*[rows];
	for (int i = 0; i < rows; i++)
		Matrix[i] = new int[columns];

	for (int j = 0; j < rows; j++)
		for (int k = 0; k < columns; k++)
			Matrix[j][k] = 0;
}
CSR::CSR(const CSR& other) {
	rows = other.rows; columns = other.columns;
	if (other.Matrix != nullptr) {
		Matrix = new int*[rows];
		for (int i = 0; i < rows; i++)
			Matrix[i] = new int[columns];

		for (int j = 0; j < rows; j++)
			for (int k = 0; k < columns; k++)
				Matrix[j][k] = other.Matrix[j][k];
	}
	AN = other.AN; JR = other.JR; JA = other.JA;
}
CSR& CSR::operator=(const CSR& other) {
	if (this == &other)
		return *this;
	if (Matrix != nullptr) {
		for (int i = 0; i < rows; i++)
			delete Matrix[i];
		delete Matrix;
	}
	rows = other.rows; columns = other.columns;
	Matrix = new int*[rows];
	for (int i = 0; i < rows; i++)
		Matrix[i] = new int[columns];
	for (int j = 0; j < rows; j++)
		for (int k = 0; k < columns; k++)
			Matrix[j][k] = other.Matrix[j][k];
	AN = other.AN; JR = other.JR; JA = other.JA;
}
void CSR::Add(int value, int row, int column) {
	Matrix[row][column] = value;
}
int CSR::Columns(void) {
	return columns;
}
int CSR::Rows(void) {
	return rows;
}
void CSR::ShowMatrix(void) {
	if (Matrix != nullptr) {
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < columns; j++)
				cout << Matrix[i][j] << " ";
			cout << endl;
		}
	}
	else {
		cout << "NULL" << endl;
	}
}
void CSR::ShowBoxing(void) {
	if (AN.size() > 0 && JR.size() > 0 && JA.size() > 0) {
		cout << "AN: [";
		for (int point : AN)
			cout << point << " ";
		cout << "]" << endl;
		cout << "JA: [";
		for (int point : JA)
			cout << point << " ";
		cout << "]" << endl;
		cout << "JR: [";
		for (int point : JR)
			cout << point << " ";
		cout << "]" << endl;
	}
	else {
		cout << "NULL" << endl;
	}
}
void CSR::Boxing(void) {
	for (int i = 0; i < rows; i++) {
		JR.push_back(AN.size());
		for (int j = 0; j < columns; j++) {
			if (Matrix[i][j] != 0) {
				AN.push_back(Matrix[i][j]);
				JA.push_back(j);
			}
		}
	}
	JR.push_back(AN.size());
}
void CSR::UnBoxing(void) {
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < columns; j++)
			Matrix[i][j] = 0;
	int index = 0;
	for (int i = 0; i < JR.size() - 1; i++) {
		for (int j = JR[i]; j < JR[i + 1]; j++)
			Matrix[index][JA[j]] = AN[j];
		index++;
	}
}
