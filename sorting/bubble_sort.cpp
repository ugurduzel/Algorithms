#include <iostream>


void swap(int * int1, int * int2) {
	int temp = *int1;
	*int1 = *int2;
	*int2 = temp;
}

void bubble_sort(int * array, int size) {
	for(int i = 0; i < size; i++) {
		bool swapped = false;
		for(int j = size - 1; i+1 <= j; j--) {
			if(array[j] < array[j-1]) {
				swap(array+j-1, array+j);
				swapped = true;
			}
		}
		if(not swapped) {
				break;
		}
	}
}



int main() {

	int array[10] = {2, 4, 1, 5, 3, 9, 8, 7, 18, 14};

	bubble_sort(array, 10);

	for(int i = 0; i < 10; i++) {
		if(i == 9) {
			std::cout << array[i] << std::endl;
			break;
		}
		std::cout << array[i] << ", ";
	}


	return 0;
}