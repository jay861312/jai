def selection_sort(array): 
    n = len(array) 
    for i in range(n): 
        min_index = i 
        for j in range(i + 1, n): 
            if array[j] < array[min_index]: 
                min_index = j 
        array[i], array[min_index] = array[min_index], array[i] 
    return array 
 
def binary_search(array, rollno): 
    low = 0 
    high = len(array) - 1 
 
    while low <= high:   
        mid = (low + high) // 2  
 
        if array[mid] == rollno: 
            print(f"Roll number {rollno} attended the training program (Binary Search).") 
            return 
        elif array[mid] < rollno: 
            low = mid + 1   
        else: 
            high = mid - 1  
 
    print(f"Roll number {rollno} did not attend the training program (Binary Search).") 
 
 
def fibonacci_search(array, rollno): 
    f2 = 0   
    f1 = 1   
    f0 = f2 + f1   
     
    while f0 < len(array): 
        f2 = f1 
        f1 = f0 
        f0 = f2 + f1 
     
    offset = -1 
     
    for i in range(len(array)): 
        if f0 <= 1: 
            break 
     
        index = min(offset + f2, len(array) - 1) 
         
        if array[index] < rollno: 
            f0 = f1 
            f1 = f2 
            f2 = f0 - f1 
            offset = index 
        elif array[index] > rollno: 
            f0 = f2 
            f1 = f1 - f2 
            f2 = f0 - f1 
        else: 
            print(f"Roll number {rollno} attended the training program (Fibonacci Search).") 
            return 
         
    if f1 and offset + 1 < len(array) and array[offset + 1] == rollno: 
        print(f"Roll number {rollno} attended the training program (Fibonacci Search).") 
    else: 
        print(f"Roll number {rollno} did not attend the training program (Fibonacci Search).") 
 
n=int(input("enter no of students: ")) 
rollnos = [] 
for i in range(0,n,1): 
    val=int(input("enter roll no: ")) 
    rollnos.append(val) 
print("unsorted array: ",rollnos) 
         
# Sorting 
rollnos = selection_sort(rollnos) 
print("Roll numbers of students who attended the training program in sorted array:", 
rollnos) 
     
sch = int(input("Enter roll number to search: ")) 
     
binary_search(rollnos, sch) 
     
fibonacci_search(rollnos, sch)