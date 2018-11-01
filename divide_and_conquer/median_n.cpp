#include <iostream>
#include <vector>
#include <algorithm>

// Find the median in Theate(n)
// Assumption : No duplicates exist
int median_of_medians(std::vector<int> array, int median_rank) {
	std::vector<int> medians;
	for(auto it = array.begin(); it < array.end() ; it += 5) {
		if(it + 5 > array.end()) {
			std::sort(it,array.end());
			medians.push_back(*(it+(array.end()-it)/2));
			break;
		}
		else {
			std::sort(it,it+5);
			medians.push_back(*(it+2));
		}
	}
	int pivot;
	if(medians.size() <= 5) {
		std::sort(medians.begin(), medians.end());
		pivot = *(medians.begin() + medians.size() / 2);
	}
	else {
		pivot = median_of_medians(medians, medians.size()/2);
	}
	std::vector<int> lower;
	std::vector<int> upper;
	for(auto it = array.begin(); it != array.end(); it++) {
		if(*it < pivot) lower.push_back(*it);
		else if(*it > pivot) upper.push_back(*it);
	}
	if(lower.size() < median_rank) {
		return median_of_medians(upper, median_rank - lower.size() - 1);
	}
	else if(lower.size() > median_rank) {
		return median_of_medians(lower, median_rank);
	}
	else {
		return pivot;
	}
}

void print(const std::vector<int> & array) {
	for(auto a : array) std::cout << a << " ";
	std::cout << std::endl;
}

int main() {

	int temp[] = {11,15,19,12,61,8,4,17,3,1,5,7,13,31,6,23};
	std::vector<int> array;
	for(int i=0; i<sizeof(temp)/sizeof(int); i++) array.push_back(temp[i]);

	std::cout << median_of_medians(array, array.size()/2) << std::endl;
	std::sort(array.begin(),array.end());
	print(array);
	return 0;
}
