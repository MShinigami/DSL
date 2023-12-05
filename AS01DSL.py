def average(marks):
    sum = 0
    count = 0
    for i in marks:
        if i == -1:
            count = count + 1
        else:
            sum = sum + i
    avg = sum / (n - count)
    return avg

def absent(marks):
    count = 0
    for ab in marks:
        if ab == -1:
            count = count + 1
    return count

def high_score(marks):
    hs = marks[0]
    for s in marks:
        if s > hs:
            hs = s
    return hs

def low_score(marks):
    ls = None
    for mark in marks:
        if mark == -1:
            continue
        if ls is None or mark < ls:
            ls = mark
    return ls

def high_freq(marks):
    count = 0
    hs = marks[0]
    for s in marks:
        if s > hs:
            hs = s
    for b in marks:
        if b == hs:
            count = count + 1
    return hs, count

def low_freq(marks):
    count = 0
    ls = None
    for i in marks:
        if i == -1:
            continue
        elif ls is None or i < ls:
            ls = i
    if ls is not None:
        for b in marks:
            if b == ls:
                count = count + 1
    return ls, count


s = []
n = int(input("Enter the number of students: "))
for i in range(n):
    marks = int(input(f"Enter marks of student {i + 1}: "))
    s.append(marks)
print("Lists of Marks", s)
while True:
    print("\n Select option of choice")
    print("1) Average of Students")
    print("2) Absent Students")
    print("3) Highest Marks obtained")
    print("4) Lowest Marks obtained")
    print("5) Frequency of Highest Marks")
    print("6) Frequency of Lowest Marks")
    print("7) EXIT")
    choice = input("\n Enter the Choice: ")
    if choice == "1":
        av = average(s)
    elif choice == "2":
        ab = absent(s)
        print("\nAbsent Students = ", ab)
    elif choice == "3":
        hs = high_score(s)
        print("\nHighest Score = ", hs)
    elif choice == "4":
        ls = low_score(s)
        print("\nLowest Score = ", ls)
    elif choice == '5':
        high, count = high_freq(s)
        print("\nHighest Marks Frequency")
        print(f"{high} = {count}")
    elif choice == "6":
        low, count = low_freq(s)
        print("\nLowest Marks Frequency")
        print(f"{low} = {count}")
    elif choice == "7":
        print("\nThank You\n")
        break
    else:
        print("Invalid choice. Please select a valid option.")
