// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class poly {
	
public:
	poly() {

	}
	void init() {
		int c, r;
		//tedade deraye haye qeire sefr ra migirad va baraye an ha hafezeye pooya migirad
		//baraye matrixe sparse
		cout << "enter the number of non-zero numbers in matrix: ";
		cin >> num;
		//arraye 2 bodi arrayeii az arraye ha ast
		*sparse = new int[3];
		for (int i = 0; i < 3; i++) {
			sparse[i] = new int[num];
		}
		cout << endl << "enter the number of rows and columns of matrix:";
		cin >> r >> c;
		*matrix = new int[r];
		for (int i = 0; i < r; i++) {
			matrix[i] = new int[c];
		}
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				cout << "enter matrix[" << i << "]" << "[" << j << "]:";
				cin >> matrix[i][j];
			}
		}
		//az matrixe mamuli matrixe 3ganeye spars misazad k satr o sotun va meqdare deraye haye qeire sefr ra zakhire mikonad
		int counter = 0;
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (matrix[i][j] != 0) {
					sparse[0][counter] = matrix[i][j];
					sparse[1][counter] = i;
					sparse[2][counter] = j;
					counter++;
				}
			}
		}
	}

	void transpose() {
		int temp;
		//taranahade misazad
		for (int i = 0; i < num; i++) {
			temp = sparse[2][i];
			sparse[2][i] = sparse[1][i];
			sparse[1][i] = temp;
		}
		//moratab sazi mikonad
		int v, c, r;
		for (int i = num - 1; i > 0; i--) {
			for (int j = 0; j > i; j++) {
				if ((sparse[1][j]==sparse[1][j+1] && sparse[2][j] > sparse[2][j+1]) || sparse[1][j]>sparse[1][j+1]) {
					v = sparse[0][j];
					r = sparse[1][j];
					c = sparse[2][j];
					sparse[2][j] = sparse[2][j + 1];
					sparse[1][j] = sparse[1][j + 1];
					sparse[0][j] = sparse[0][j + 1];
					sparse[0][j + 1] = v;
					sparse[1][j + 1] = r;
					sparse[2][j + 1] = c;
				}
			}
		}
	}

private:
	int num;
	int **matrix;
	int **sparse;
	int col, row;

};

int main()
{
    return 0;
}

