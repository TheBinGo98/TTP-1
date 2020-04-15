#include <iostream>      
#include <ctime>      

void bubbleSort(short**, int, int, int);

int main() {

	using namespace std;

	setlocale(LC_ALL, "Russian"); //1234
	//Размерность массива

	int n, m;
	(std::cin >> n >> m).get();

	if (cin.fail()) {
		cout << "Для ввода разрешены только числа!" << endl;
		system("pause");
		return 0;
	}
	while (n > 10 || n < 2) {
		cout << "Значение долно быть в диапазоне от 2 до 10. Введите еще раз размер массива: ";
		cin >> n;
	}
	while (m > 10 || m < 2) {
		cout << "Значение долно быть в диапазоне от 2 до 10. Введите еще раз размер массива: ";
		cin >> m;
	}

	// Создание матрицы
	short ** M = new short*[n];
	srand(time(0));
	for (int i = 0; i < n; ++i) {
		M[i] = new short[m];
		for (int j = 0; j < m; ++j)
			std::cout << (M[i][j] = rand() % 100) << '\t';
		std::cout << std::endl;
	}

	std::cout << std::endl;

	// Сортировка матрицы пузырьком
	for (int j = 0; j < m; ++j)
		bubbleSort(M, j, 0, n - 1);

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j)
			std::cout << M[i][j] << '\t';
		std::cout << std::endl;
		delete[] M[i];
	}
	delete[] M;

	std::cin.get();
	system("pause");
	return 0;
}

void bubbleSort(short ** m, int col, int a, int b) {             //Пузырьковая сортировка
	short avg = m[b][col];
	int i = a, j = b;

	do {
		while (m[i][col] < avg) i++;
		while (m[j][col] > avg) j--;

		if (i <= j) {
			if (m[i][col] != m[j][col]) {
				short t = m[i][col];
				m[i][col] = m[j][col];
				m[j][col] = t;
			}
			i++;
			j--;
		}

	} while (i <= j);

	if (i < b)
		bubbleSort(m, col, i, b);
	if (j > a)
		bubbleSort(m, col, a, j);
}

