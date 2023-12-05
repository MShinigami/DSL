def MATRIX(x, y):
    matrix = []
    for i in range(x):
        row = []
        for j in range(y):
            input_no = float(input(f"Enter the element of ({i + 1},{j + 1}): "))
            row.append(input_no)
        matrix.append(row)
    for i in range(x):
        print("\n", end=' ')
        for j in range(y):
            if j == y - 1:
                print(matrix[i][j], end=' ')
            else:
                print(matrix[i][j], end=' ')
    return matrix

def Dimension(matrix):
    rows = 0
    columns = 0
    for row in matrix:
        rows = rows + 1
        for element in row:
            columns = columns + 1
            break
    return rows, columns

def Addition(matrix1, matrix2):
    row1, column1 = Dimension(matrix1)
    row2, column2 = Dimension(matrix2)

    if row1 != row2 or column1 != column2:
        print("Not possible, the order of matrices is different.")
        return None

    result = []
    for i in range(row1):
        row = []
        for j in range(column1):
            add = matrix1[i][j] + matrix2[i][j]
            row.append(add)
        result.append(row)
    return result

def Subtraction(matrix1, matrix2):
    row1, column1 = Dimension(matrix1)
    row2, column2 = Dimension(matrix2)

    if row1 != row2 or column1 != column2:
        print("Not possible, the order of matrices is different.")
        return None

    result = []
    for i in range(row1):
        row = []
        for j in range(column1):
            sub = matrix1[i][j] - matrix2[i][j]
            row.append(sub)
        result.append(row)
    return result

def Multiplication(matrix1, matrix2):
    row1, column1 = Dimension(matrix1)
    row2, column2 = Dimension(matrix2)

    if column1 != row2:
        print("Not possible, the order of matrices is different.")
        return None

    result = []
    for i in range(row1):
        row = []
        for j in range(column2):
            product = 0
            for k in range(column1):
                product = product + matrix1[i][k] * matrix2[k][j]
            row.append(product)
        result.append(row)
    return result

def Transpose(matrix):
    row, column = Dimension(matrix)
    new_matrix = []
    for i in range(column):
        new_row = []
        for j in range(row):
            mat = matrix[j][i]
            new_row.append(mat)
        new_matrix.append(new_row)
    return new_matrix

print("\n\tFirst Matrix: ")
x1 = int(input("Enter the number of rows = "))
y1 = int(input("Enter the number of columns = "))
matrix1 = MATRIX(x1, y1)

print("\n\tSecond Matrix: ")
x2 = int(input("Enter the number of rows = "))
y2 = int(input("Enter the number of columns = "))
matrix2 = MATRIX(x2, y2)

while True:
    print("\n\n1) Addition.")
    print("2) Subtraction.")
    print("3) Multiplication.")
    print("4) Transpose of Matrix")
    print("5) Retype the first matrix")
    print("6) Retype the second matrix")
    print("7) Exit.")

    choice = input("Enter your choice: ")

    if choice == '1':
        result = Addition(matrix1, matrix2)
        if result:
            print("Matrix Addition :")
            for row in result:
                for i in row:
                    print(i, end='\t')
                print()
    elif choice == '2':
        result = Subtraction(matrix1, matrix2)
        if result:
            print("Matrix Subtraction :")
            for row in result:
                for i in row:
                    print(i, end='\t')
                print()
    elif choice == '3':
        result = Multiplication(matrix1, matrix2)
        if result:
            print("Matrix Multiplication :")
            for row in result:
                for i in row:
                    print(i, end='\t')
                print()
    elif choice == '4':
        mat = int(input("Enter the Matrix to transpose (1/2): "))
        if mat == 1:
            result = Transpose(matrix1)
            print("\nTranspose of First Matrix:\n")
            for row in result:
                for i in row:
                    print(i, end='\t')
                print()
        else:
            result = Transpose(matrix2)
            print("\nTranspose of Second Matrix:\n")
            for row in result:
                for i in row:
                    print(i, end='\t')
                print()
    elif choice == '5':
        print("\n\tFirst Matrix: ")
        x1 = int(input("Enter the number of rows = "))
        y1 = int(input("Enter the number of columns = "))
        matrix1 = MATRIX(x1, y1)
    elif choice == '6':
        print("\n\tSecond Matrix: ")
        x2 = int(input("Enter the number of rows = "))
        y2 = int(input("Enter the number of columns = "))
        matrix2 = MATRIX(x2, y2)
    elif choice == '7':
        print("\nExiting the program.")
        break
    else:
        print("\nInvalid choice.")

