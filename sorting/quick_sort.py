def swap(lst, index1, index2):
	temp = lst[index1]
	lst[index1] = lst[index2]
	lst[index2] = temp


# Last is the index of the last element in the list
def partition_with_high_locality(lst, first, last):
	pivot = lst[first]
	pivot_index = first

	for j in range(first+1, last+1):
		if lst[j] <= pivot:
			pivot_index += 1
			swap(lst, pivot_index, j)
	swap(lst, first, pivot_index)
	return pivot_index

# Last is the index of the last element in the list
def quick_sort_helper(lst, first, last):
	if first < last:
		pivot_index = partition_with_high_locality(lst, first, last)
		quick_sort_helper(lst, first, pivot_index-1)
		quick_sort_helper(lst, pivot_index+1, last)

def quick_sort(lst):
	quick_sort_helper(lst, 0, len(lst)-1)


lst = [2, 4, 1, 5, 3, 9, 8, 7, 18, 14]
quick_sort(lst)
print(lst == sorted(lst))