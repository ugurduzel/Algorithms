#include <stdio.h>


void swap(int * int1, int * int2) {
	int temp = *int1;
	*int1 = *int2;
	*int2 = temp;
}


int partition_with_high_locality(int * array, int firstElement, int lastElement) {
	int pivot = array[firstElement];
	int pivot_index = firstElement;

	for(int j = firstElement+1; j <= lastElement; j++) {
		if(array[j] <= pivot) {
			pivot_index++; 
			swap(array+pivot_index, array+j);
		}
	}
	swap(array+firstElement, array+pivot_index);
	return pivot_index;
}

void quick_sort_helper(int * array, int firstElement, int lastElement) {
	if(firstElement < lastElement) {
		int pivot_index = partition_with_high_locality(array, firstElement, lastElement);
		quick_sort_helper(array, firstElement, pivot_index-1);
		quick_sort_helper(array, pivot_index+1, lastElement);
	}
}

void quick_sort(int * array, int size) {
	quick_sort_helper(array, 0, size-1);
}



int main() {

	int array[10] = {2, 4, 1, 5, 3, 9, 8, 7, 18, 14};

	quick_sort(array, 10);

	
	for(int i = 0; i < 10; i++) {
		printf("%d ", array[i]);
	}
	printf("\n");

	return 0;
}
