#include <iostream>
#include <vector>

// An inversion is a (i,j) such that array[i] >= array[j] for all i and j.
// Modifying merge sort is enough.
// Complexity is Theta(nlgn)
void merge(const std::vector<int> & left_array, const std::vector<int> & right_array, std::vector<int> & array, int & inversions) {
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
      inversions++;
		}
	}
	array = result;
	result.clear();
}

void merge_sort(std::vector<int> & array, int & inversions) {

	if(1 < array.size()) {
		int size = array.size();
		std::vector<int> left_array(array.begin(), array.begin() + size/2);
		std::vector<int> right_array(array.begin() + size/2, array.end());
		merge_sort(left_array, inversions);
		merge_sort(right_array, inversions);
		merge(left_array, right_array, array, inversions);
	}
}


int main() {

	int temp[] = {1,5,2,3,6,8,9};
	std::vector<int> array;
	for(int i=0; i<sizeof(temp)/sizeof(int); i++) array.push_back(temp[i]);

	int inversions = 0;
  merge_sort(array, inversions);
  
  std::cout << "Number of Inversions : " << inversions << std::endl;


	return 0;
}
