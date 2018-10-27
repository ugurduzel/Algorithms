#include <iostream>


void swap(int * int1, int * int2) {
	int temp = *int1;
	*int1 = *int2;
	*int2 = temp;
}

void insertionSort(int * array, int size) {

	for(int i = 1; i < size; i++) {
		int value_to_put_into_sorted = array[i];
		for(int j = i-1; 0 <= j; j--) {
			if(value_to_put_into_sorted >= array[j]) 
				break;
			swap(array+j, array+j+1);
		}
	}

}



int main() {

	int array[10] = {2, 4, 1, 5, 3, 9, 8, 7, 18, 14};

	insertionSort(array, 10);

	for(int i = 0; i < 10; i++) {
		if(i == 9) {
			std::cout << array[i] << std::endl;
			break;
		}
		std::cout << array[i] << ", ";
	}

	return 0;
}