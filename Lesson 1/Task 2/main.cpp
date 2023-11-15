#include <iostream>

int countHigherNumbers(int* arr, int size, int refPoint) {
	
	if ((size < 0) || (size == 1 && arr[0] <= refPoint)) return 0;
	if (size == 1 && arr[0] > refPoint) return 1;
	
	int left = 0; int right = size-1; // левая и правая границы диапазона

	// сокращаем диапазон, пока в нем не останется два элемента
	while ( left < right-1 ) {
		//смотрим в середину диапазона
		int num = (right + left) / 2;
		// если элемент в середине > точки отсчета, то сдвигаем правую границу диапазона к этому элементу
		if (arr[num] > refPoint) right = num;
		// иначе сдвигаем левую границу диапазона
		else left = num;
	}

	if (arr[left] > refPoint) return size - left;
	if (arr[left] <= refPoint && arr[right] > refPoint) return size - left - 1;
	return 0;
}

int main() {
	setlocale(LC_ALL, "");

	int arr[] = { 14, 16, 19, 32, 32, 32, 56, 69, 72 };
	int refPoint;
	std::cout << "Введите точку отсчета: ";
	std::cin >> refPoint;

	std::cout << "Количество элементов в массиве больших, чем " << refPoint << ": ";
	std::cout << countHigherNumbers(arr, sizeof(arr) / sizeof(arr[0]), refPoint);

	return 0;
}

//