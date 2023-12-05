def input_data(N):
    Data = []
    for i in range(N):
        Marks = float(input(f"Enter the marks of Student{i + 1} : "))
        Data.append(Marks)
    return Data

def bubble_sort(A):
    n = len(A)
    for i in range(n):
        for j in range(0,n-i-1):
            if A[j] > A[j+1]:
                A[j],A[j+1] = A[j+1],A[j]

def selection_sort(A):
	n = len(A)
	for i in range(0,n):
		minindex = i
		for j in range(i,n):
			if A[minindex] > A[j]:
				minindex = j
				A[minindex],A[i] = A[i],A[minindex]

N = int(input("Enter the Number of students: "))
Data = input_data(N)
print(Data)

while True:
	print("\n\n1) Selection Sort.")
	print("2) Bubble Sort.")
	print("3) Exit.")
	
	choice = input("Enter your choice: ")
	if choice == '1':
		selection_sort(Data)
		print(Data)
	if choice == '2':
		bubble_sort(Data)
		print(Data)
	if choice == '3':
		print("Thank You")
		break
	