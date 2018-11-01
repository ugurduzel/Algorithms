#include <iostream>
#include <vector>

void print(const std::vector<int> & array) {
	for(auto a : array) std::cout << a << " ";
	std::cout << std::endl;
}

int partition(std::vector<int> & array, int firstElement, int lastElement) {
	int pivot = array[firstElement];
	int pivot_index = firstElement;
	for(int j = firstElement +1; j <= lastElement; j++) {
		if(array[j] <= pivot) {
			pivot_index++;
			int temp = array[pivot_index];
			array[pivot_index] = array[j];
			array[j] = temp;
		}
	}
	array[firstElement] = array[pivot_index];
	array[pivot_index] = pivot;
	return pivot_index;
}

void quick_sort_helper(std::vector<int> & array, int firstElement, int lastElement) {
	if(firstElement < lastElement) {
		int pivot_index = partition(array, firstElement, lastElement);
		quick_sort_helper(array, firstElement, pivot_index - 1);
		quick_sort_helper(array, pivot_index + 1, lastElement);
	}
}

void quick_sort(std::vector<int> & array) {
	quick_sort_helper(array, 0, array.size()-1);
}


int main() {

	int temp[] = {6, 4, 3, 10,2,8 ,7, 1, 14};
	std::vector<int> array;
	for(int i=0; i<sizeof(temp)/sizeof(int); i++) array.push_back(temp[i]);

	std::cout << "Unsorted : ";
	print(array);
	quick_sort(array);
	std::cout << "Sorted   : ";
	print(array);

	return 0;
}