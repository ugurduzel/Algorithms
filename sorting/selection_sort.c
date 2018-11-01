#include <stdio.h>


void swap(int * int1, int * int2) {
	int temp = *int1;
	*int1 = *int2;
	*int2 = temp;
}

void selection_sort(int * array, int size) {

	for(int i = 0; i < size; i++) {
		int current = i;
		for(int j = i+1; j < size; j++) {
			if(array[j] < array[current]) {
				current = j;
			}
		}
		swap(array+i, array+current);
	}

}



int main() {

	int array[10] = {2, 4, 1, 5, 3, 9, 8, 7, 18, 14};

	selection_sort(array, 10);

	
	for(int i = 0; i < 10; i++) {
		printf("%d ", array[i]);
	}
	printf("\n");

	return 0;
}