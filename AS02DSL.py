def longest(S):
    longs = S[0]
    nlongs = len(longs)
    for w in S:
        if len(w) > nlongs:
            longs = w
    return longs, nlongs

def Freq(S):
    F = {}
    count = 0
    common_words = []
    for w in S:
        lw = w.lower()
        if lw in F:
            F[lw] += 1
        else:
            F[lw] = 1
        if F[lw] > count:
            count = F[lw]
            common_words = [lw]
        elif F[lw] == count:
            common_words.append(lw)
    return common_words, count

def palindrome(S):
    s = S.lower()
    return s == s[::-1]

def Sub(S, sub):
    s = sub.lower()
    S = S.lower()
    count = S.count(s)
    return count

def Index(S, sub):
    sub = sub.lower()
    S = S.lower()
    index = S.find(sub)
    return index

def Word_index(S, inword):
    inword = inword.lower()
    S = S.lower()
    word = S.split()
    index = -1
    for i, w in enumerate(word):
        if w == inword:
            index = i
    return inword, index

print("Enter the String: ")
S = input()
IP = S.split()
print(IP)

while True:
    print("\n\n1)The longest word.")
    print("2)Word count.")
    print("3)Check for palindrome.")
    print("4)Count substring.")
    print("5)Finding index of substring.")
    print("6)Finding index of a word.")
    print("7)Exit.")
    choice = input("Enter your choice: ")
    if choice == "1":
        lgs, nlgs = longest(IP)
        print("\nThe longest word is")
        print(f"{lgs} - {nlgs}")
    elif choice == "2":
        print("\nWord Count:")
        fc, nfc = Freq(IP)
        for word in fc:
            print(f"{word} = {nfc}")
    elif choice == "3":
        for word in IP:
            pal = input("\nEnter the string: ")
            if palindrome(pal):
                print(f"\n'{pal}' is a palindrome!")
                break
            else:
                print(f"\n'{pal}' is not palindrome. ")
                break
    elif choice == "4":
        sub = input("\nEnter the substring to count: ")
        count = Sub(S, sub)
        print(f"\nThe substring '{sub}' appears {count} times in the string.")
    elif choice == "5":
        sub = input("\nEnter the Substring you want to find: ")
        index = Index(S, sub)
        if index != -1:
            print(f"\nThe Substring '{sub}' was found at index {index}.")
        else:
            print(f"\nThe Substring '{sub}' does not exist in the string.")
    elif choice == "6":
        inword = input("\nEnter the Substring you want to find: ")
        index = Word_index(S, inword)
        if index != -1:
            print(f"\nFound {index}.")
        else:
            print(f"\nThe word '{inword}' does not exist in the string.")
    elif choice == "7":
        print("\nExiting the program.")
        break
    else:
        print("\nInvalid choice.")
    
    another = input("\nDo you want to perform another action? (y/n): ")
    if another != "y":
        print("\nExiting the program.")
        break
