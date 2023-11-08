#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void Create(int** a, const int rowCount, const int colCount, const int Low, const int High, int i, int j);
void Print(int** a, const int rowCount, const int colCount, int i, int j);
void FindMax(int** a, const int n, int& max, int i);

int main()
{
	srand((unsigned)time(NULL));
	int Low = -42;
	int High = 51;
	int max;
	int rowCount = 4;
	int colCount = 4;
	int** a = new int* [rowCount];
	for (int i = 0; i < rowCount; i++)
		a[i] = new int[colCount];
	Create(a, rowCount, colCount, Low, High, 0, 0);
	Print(a, rowCount, colCount, 0, 0);
	FindMax(a, rowCount, max, 0);
	cout << endl << "max = " << max << endl;
	delete[] a;
	return 0;
}

void Create(int** a, const int rowCount, const int colCount, const int Low, const int High, int i, int j)
{
	if (i < rowCount) {
		if (j < colCount) {
			a[i][j] = Low + rand() % (High - Low + 1);
			Create(a, rowCount, colCount, Low, High, i, j + 1);  // Перехід до наступного стовпця
		}
		else {
			Create(a, rowCount, colCount, Low, High, i + 1, 0);  // Перехід до наступного рядка
		}
	}
}

void Print(int** a, const int rowCount, const int colCount, int i, int j)
{
	if (i < rowCount) {
		cout << setw(5) << a[i][j];
		if (j < colCount - 1) {
			Print(a, rowCount, colCount, i, j + 1);  // Вивід елементу та перехід до наступного стовпця
		}
		else {
			cout << endl << endl;
			Print(a, rowCount, colCount, i + 1, 0);  // Перехід до наступного рядка
		}
	}
	else {
		cout << endl;
	}
}

void FindMax(int** a, const int n, int& max, int i)
{
	if (i == n) // коли досягли кінця діагоналі
	{
		return;
	}

	if (a[i][i] > max)
	{
		max = a[i][i]; // якщо знайдений більший елемент
	}

	FindMax(a, n, max, i + 1); // виклик для наступного елементу діагоналі
}

