#include <iostream>
#include <vector>

// Counts occurences of a given number in a sorted array in Theta(lgn)
// To understand fully uncomment the comments and run the program
void helper(const std::vector<int> & array, int first, int last, int & left_found, int & right_found, const int value) {
	//std::cout << "--FUNCTION CALL : (" << first << "," << last << ")\n";
	if(first >= last) {
		if(array[first] == value and first < left_found) left_found = first;
		if(array[first] == value and right_found < first) right_found = first;
			
		return;
	}

	int index = (first+last)/2;
	int pivot = array[index];

	if(pivot == value) {
		if(index <= left_found) {
			//std::cout << "Left Index : " << index << std::endl;
			left_found = index;
			helper(array, first, first + (last-first)/2, left_found, right_found, value);
		}
		if(right_found <= index) {
			//std::cout << "Right Index : " << index << std::endl;
			right_found = index;
			helper(array, first + (last-first)/2+1, last, left_found, right_found, value);
		}
	}
	if(pivot > value) {
		helper(array, first, first + (last-first)/2, left_found, right_found, value);
	}
	if(pivot < value) {
		helper(array, first + (last-first)/2 + 1, last, left_found, right_found, value);
	}
	//std::cout << "--FUNCTION ENDED : (" << first << "," << last << ")\n";
}	


int number_of_occurences(const std::vector<int> & array, const int value) {
	int left = array.size();
	int right = -1;
	helper(array, 0, array.size()-1, left, right, value);
	std::cout << "Indices between (" << left << "," << right << ") ";
	return right-left+1;
}

int main() {

	int temp[] = {1,1,1,1,1,1,5,5,5, 5 ,5,5,7,7,7,7,8,8,8,9};
	std::vector<int> array;
	for(int i=0; i<sizeof(temp)/sizeof(int); i++) array.push_back(temp[i]);

	std::cout << number_of_occurences(array, 1) << std::endl;
	std::cout << number_of_occurences(array, 5) << std::endl;
	std::cout << number_of_occurences(array, 7) << std::endl;
	std::cout << number_of_occurences(array, 8) << std::endl;
	std::cout << number_of_occurences(array, 9) << std::endl;

	return 0;
}