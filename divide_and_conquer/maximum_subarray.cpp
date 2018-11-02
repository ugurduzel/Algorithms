#include <iostream>
#include <vector>

// Finding the sum of contiguous subarray of numbers which has the largest sum
// It is a Divide and Conquer approach Theta(nlgn)
int maxSubArray(vector<int>& nums) {
        if(1 < nums.size()) {
            auto it1 = nums.begin();
            vector<int> left(it1, it1 + nums.size()/2);
            vector<int> right(it1 + nums.size()/2, nums.end());

            // Case of left branch has the max
            int left_max = maxSubArray(left); 
            // Case of right branch has the max
            int right_max = maxSubArray(right);

            // Case of the max is between them
            // Start from the last element of the left array
            // Find max in linear time
            int middle_max_left = left[left.size()-1];
            for(int i = left.size()-2, temp = middle_max_left; 0 <= i; i--) {
                temp += left[i];
                if(temp > middle_max_left) {
                    middle_max_left = temp;
                } 
            }
            // Start from the first element of the right array
            // Find max in linear time
            int middle_max_right = right[0];
            for(int i = 1, temp = middle_max_right; i < right.size(); i++) {
                temp += right[i];
                if(temp > middle_max_right) {
                    middle_max_right = temp;
                } 
            }
            //Combine them to find the max is between left and right arrays
            int middle_max = middle_max_left + middle_max_right;
            
            if(middle_max > left_max and middle_max > right_max) return middle_max;
            else if(left_max > right_max) return left_max;
            else return right_max;
        }
        else {
            return nums[0];
        }