// DataStructure3_1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include "Header.h"
using namespace std;

CSR Addition(CSR&, CSR&);
void Output(CSR&, CSR&, CSR&);

int main(void)
{
	char ch;
	int row; int column;
	cout << "Enter a matrix1 size here: ";
	cin >> row >> ch >> column;

	CSR matrix1(row, column);
	int value;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			cout << "Item [" << i << "][" << j << "]: ";
			cin >> value;
			matrix1.Add(value, i, j);
		}
	}
	cout << "Enter a matrix2 size here: ";
	cin >> row >> ch >> column;

	CSR matrix2(row, column);
	value=0;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			cout << "Item [" << i << "][" << j << "]: ";
			cin >> value;
			matrix2.Add(value, i, j);
		}
	}
	
	matrix1.Boxing();
	matrix2.Boxing();
	CSR Res = Addition(matrix1, matrix2);
	Res.UnBoxing();
	Output(matrix1, matrix2, Res);
	system("pause");
	return 0;
}
CSR Addition(CSR& matrix1, CSR& matrix2) {
	if (matrix1.Rows() == matrix2.Rows() && matrix1.Columns() == matrix2.Columns()) {
		int row = matrix1.Rows(); int column = matrix1.Columns();
		CSR Result(row, column);
		int* ColumnsTemp = new int[column];
		for (int i = 0; i < row; i++) {
			for (int n = 0; n < column; n++)
				ColumnsTemp[n] = 0;
			Result.JR.push_back(Result.AN.size());
			for (int j = matrix1.JR[i]; j < matrix1.JR[i + 1]; j++) 
				ColumnsTemp[matrix1.JA[j]] += matrix1.AN[j];
			for (int k = matrix2.JR[i]; k < matrix2.JR[i + 1]; k++)
				ColumnsTemp[matrix2.JA[k]] += matrix2.AN[k];
			for(int z=0; z<column; z++)
				if (ColumnsTemp[z] != 0) {
					Result.AN.push_back(ColumnsTemp[z]);
					Result.JA.push_back(z);
				}
		}
		Result.JR.push_back(Result.AN.size());
		delete ColumnsTemp;
		return Result;
	}
	else {
		cout << "WARNING Addition(): Not possible to execute addition function." << endl;
		system("pause");
		exit(-1);
	}
}
void Output(CSR& matrix1, CSR& matrix2, CSR& result) {
	system("cls");
	cout << "Matrix 1: Boxing mode" << endl;
	cout << "---------------------" << endl;
	matrix1.ShowBoxing();
	cout << "---------------------------------------" << endl;
	cout << endl;
	cout << "Matrix 2: Boxing mode" << endl;
	cout << "---------------------" << endl;
	matrix2.ShowBoxing();
	cout << "----------------------------------------" << endl;
	cout << endl;
	cout << endl;
	cout << "Matrix: Result of addition" << endl;
	cout << "--------------------------" << endl;
	result.ShowMatrix();
	cout << "----------------------------------------" << endl;
	cout << "Matrix: Boxing mode" << endl;
	cout << "-------------------" << endl;
	result.ShowBoxing();
	cout << "----------------------------------------" << endl;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
