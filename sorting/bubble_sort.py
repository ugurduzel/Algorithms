def swap(lst, index1, index2):
	temp = lst[index1]
	lst[index1] = lst[index2]
	lst[index2] = temp

def bubble_sort(lst):
	size = len(lst)
	for i in range(size):
		swapped = False
		for j in reversed(range(i+1, size)):
			if lst[j] < lst[j-1]:
				swap(lst, j-1, j)
				swapped = True
		if swapped == False:
			break


lst = [2, 4, 1, 5, 3, 9, 8, 7, 18, 14]
bubble_sort(lst)
print(lst == sorted(lst))