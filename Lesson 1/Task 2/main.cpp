#include <iostream>

int countHigherNumbers(int* arr, int size, int refPoint) {
	
	if ((size < 0) || (size == 1 && arr[0] <= refPoint)) return 0;
	if (size == 1 && arr[0] > refPoint) return 1;
	
	int left = 0; int right = size-1; // ����� � ������ ������� ���������

	// ��������� ��������, ���� � ��� �� ��������� ��� ��������
	while ( left < right-1 ) {
		//������� � �������� ���������
		int num = (right + left) / 2;
		// ���� ������� � �������� > ����� �������, �� �������� ������ ������� ��������� � ����� ��������
		if (arr[num] > refPoint) right = num;
		// ����� �������� ����� ������� ���������
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
	std::cout << "������� ����� �������: ";
	std::cin >> refPoint;

	std::cout << "���������� ��������� � ������� �������, ��� " << refPoint << ": ";
	std::cout << countHigherNumbers(arr, sizeof(arr) / sizeof(arr[0]), refPoint);

	return 0;
}