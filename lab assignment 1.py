n=int(input("Number of students in class= ")) 
l=[] 
for i in range(0,n): 
    val=int(input("Enter marks scored in Fundamentals of Data Structure subject= ")) 
    l.append(val) 
     
def av(l,n): 
    cnt=0 
    add=0 
    for i in range(0,n): 
        if(l[i]>0): 
            add=add+l[i] 
            cnt=cnt+1  
    avg=add/cnt 
    print("\nThe average score of class= ",avg) 
     
def maxmin(l): 
    mx=l[0] 
    for i in range(0,len(l)): 
        if(l[i]>0): 
            if(l[i]>mx): 
                mx=l[i] 
    print("\nHighest score of class= ",mx) 
    mn=l[0] 
    for i in range(0,len(l)): 
        if(l[i]>=0): 
            if(l[i]<mn): 
                mn=l[i] 
    print("Lowest score of class= ",mn) 
     
def abse(l): 
    cnt=0 
    for i in range(0,len(l)): 
        if(l[i]==-1): 
            cnt=cnt+1  
    print("\nCount of absent students= ",cnt) 
     
def freq(l): 
    maxx=0 
    marks=0 
    for j in range(0,len(l)): 
        if(l[j]==-1): 
            continue 
        cnt=0 
        for i in range(0,len(l)): 
            if(l[j]==l[i]): 
                cnt=cnt+1  
            if(cnt>maxx): 
                maxx=cnt 
                marks=l[j] 
    print("\nThe marks with highest frequency of ",maxx,"= ",marks) 
     
ch1=1  
while(ch1==1): 
    print("""\nChoose what you want to perform: \n1 = average score of class\n2 = Highest 
    score and Lowest score of class\n3 = Count of students who were absent for the test\n4 = 
    Display marks with highest frequency""") 
    ch=int(input("\nEnter choice= ")) 
    if(ch==1): 
        av(l,n) 
    elif(ch==2): 
        maxmin(l) 
    elif(ch==3): 
        abse(l) 
    elif(ch==4): 
        freq(l) 
    else: 
        print("Invalid Choice") 
    ch1=int(input("\nDo you want to continue(1-yes/0-no)= "))