def input_data():
	data = []
	n= int(input("Enter the number of club members: "))
	for i in range(n):
		roll= int(input(f"Enter the roll no of sudents{i+1}: "))
		data.append(roll)
	return (data)

def Bubble_sort(Data):
	n = len(Data)
	for i in range(n):
		for j in range(0,n-i-1):
			if Data[j] > Data[j+1]:
				Data[j],Data[j+1] = Data[j+1],Data[j]

def Ternary_search(Data,l,r,x):
	while r>= l:
		mid1 = l+(r-l)//3
		mid2 = 2*(l+(r-l))//3
		if Data[mid1] == x:
			return mid1
		elif Data[mid2] == x:
			return mid2
		elif Data[mid1]>x:
			return Ternary_search(Data,l,mid1-1,x)
		elif Data[mid2]<x:
			return Ternary_search(Data,mid2+1,r,x)
		else:
			return Ternary_seach(Data,mid1+1,mid2-1,x)
	return -1

Data = input_data()
print("Data:", Data)
Bubble_sort(Data)
print("\nSorted Data:",Data)

while True:
    x = int(input("Enter the number you want to find: "))
    result = Ternary_search(Data, 0, len(Data) - 1, x)

    if result == -1:
        print(f"The roll number {x} is not the member of the club")
    else:
        print(f"Found, roll number {x} is the member of club at position {result +1}")

    choice = input("Do you wish to find another (y/n): ")
    if choice != 'y':
        break