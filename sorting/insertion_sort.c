#include <stdio.h>


void swap(int * int1, int * int2) {
	int temp = *int1;
	*int1 = *int2;
	*int2 = temp;
}

void insertion_sort(int * array, int size) {

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

	insertion_sort(array, 10);

	
	for(int i = 0; i < 10; i++) {
		printf("%d ", array[i]);
	}
	printf("\n");

	return 0;
}