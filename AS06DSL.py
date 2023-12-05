def get_data(A):
	Data = []
	for i in range(A):
		Marks = float(input(f"Enter the marks student{i + 1} : "))
		Data.append(Marks)
	return Data
	
def partition(A, l, r):
	pivot = A[r]
	left = l
	right = r - 1

	while True:
		while left <= right and A[left] <= pivot:
			left= left+1
		while left <= right and A[right] >= pivot:
			right= right-1
		if left <= right:
			A[left], A[right] = A[right], A[left]
		else:
			break
	A[left], A[r] = A[r], A[left]
	return left

def quick_sort(A, l, r):
	if l < r:
		p = partition(A, l, r)
		quick_sort(A, l, p - 1)
		quick_sort(A, p + 1, r)

N = int(input("Enter the number of students: "))
Data =get_data(N)
print("\n")
print("Unsorted Marks of Students: ")
for i in Data:
	print("| ",i,end=" | ")
print("\n")

print("Sorted Marks of Students: ")
quick_sort(Data,0,len(Data)-1)
for i in Data:
	print("| ",i,end=" | ")
print("\n")