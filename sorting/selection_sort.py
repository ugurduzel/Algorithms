def swap(lst, index1, index2):
	temp = lst[index1]
	lst[index1] = lst[index2]
	lst[index2] = temp

def selection_sort(lst):
	size = len(lst)
	for i in range(size):
		current = i
		for j in range(i+1, size):
			if lst[j] < lst[current]:
				current = j
		swap(lst, i, current)



lst = [2, 4, 1, 5, 3, 9, 8, 7, 18, 14]
selection_sort(lst)
print(lst == sorted(lst))