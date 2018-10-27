def swap(lst, index1, index2):
	temp = lst[index1]
	lst[index1] = lst[index2]
	lst[index2] = temp

def insertion_sort(lst):

	for i in range(len(lst)):
		value_to_put_into_sorted = lst[i]
		for j in reversed(range(i)):
			if value_to_put_into_sorted >= lst[j]:
				break
			swap(lst, j, j+1)




lst = [2, 4, 1, 5, 3, 9, 8, 7, 18, 14]
insertion_sort(lst)
print(lst == sorted(lst))