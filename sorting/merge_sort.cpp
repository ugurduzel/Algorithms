#include <iostream>
#include <vector>

void print(const std::vector<int> & array) {
	for(auto a : array) std::cout << a << " ";
	std::cout << std::endl;
}

void merge(const std::vector<int> & left_array, const std::vector<int> & right_array, std::vector<int> & array) {
	std::vector<int> result;
	int i = 0;
	int j = 0;
	while(i < left_array.size() or j < right_array.size()) {
		// Left array has no other entries
		if(i >= left_array.size()) {
			result.push_back(right_array[j]);	
			j++;
		}
		// Right array has no other entries
		else if(j >= right_array.size()) {
			result.push_back(left_array[i]);
			i++;
		}
		else if(left_array[i] < right_array[j]) {
			result.push_back(left_array[i]);
			i++;
		}
		else {
			result.push_back(right_array[j]);	
			j++;
		}
	}
	array = result;
	result.clear();
}

void merge_sort(std::vector<int> & array) {

	if(1 < array.size()) {
		int size = array.size();
		std::vector<int> left_array(array.begin(), array.begin() + size/2);
		std::vector<int> right_array(array.begin() + size/2, array.end());
		merge_sort(left_array);
		merge_sort(right_array);
		merge(left_array, right_array, array);
	}

}


int main() {

	int temp[] = {1,5,2,3,6,8,9};
	std::vector<int> array;
	for(int i=0; i<sizeof(temp)/sizeof(int); i++) array.push_back(temp[i]);

	std::cout << "Unsorted : ";
	print(array);
	merge_sort(array);
	std::cout << "Sorted   : ";
	print(array);

	return 0;
}



