def matrix(r,c):
    matrix1=[]
    for i in range(r):
        m1=[]
        for j in range(c):
            val1=int(input("enter the elements :"))
            m1.append(val1)
        matrix1.append(m1)
    return matrix1

def display(r,c,m1):
    for i in range(r):
        for j in  range(c):
            print(m1[i][j],end=" ")
        print()

r1=int(input("enter the number of rows :"))
c1=int(input("enter the number of columns :"))
matrix1=matrix(r1,c1)
print("matrix 1 is:")
display(r1,c1,matrix1)


r2=int(input("enter the number of rows :"))
c2=int(input("enter the number of columns :"))
matrix2=matrix(r2,c2)
print("matrix 2 is:")
display(r2,c2,matrix2)

choice=input("enter the operater(+,-,*,t):")


if(choice=="+"):
    if(r1==r2 and c1==c2):
        add1=[]
        for i in range(r1):
            a1=[]
            for j in range(c1):
                a1.append(matrix1[i][j]+matrix2[i][j])
            add1.append(a1)
            
        print("your addtion of matrix is :")
        display(r1,c1,add1)
    else:
        print("addition can't be performed")


elif(choice=="-"):
    if(r1==r2 and c1==c2):
        sub1=[]
        for i in range(r1):
            s1=[]
            for j in range(c1):
                s1.append(matrix1[i][j]-matrix2[i][j])
            sub1.append(s1)
            
        print("your subtraction of matrix is :")
        display(r1,c1,sub1)
    else:
        print("subtraction can't be performed")
        
        
elif(choice=="*"):
    if(c1==c2):
        mul1=[]
        for i in range(c1):
            mu1=[]
            for j in range(c2):
                s=0
                for k in range(c1):
                    s=s+(matrix1[i][k]*matrix2[k][j])
                mu1.append(s)
            mul1.append(mu1)
        print("your multiplication of matrix is :")
        display(c1,c2,mul1)
    else:
        print("multiplication can't be performed")
        

elif(choice=="t"):
    ch=int(input("enter (1) to transpose matrix 1 and (2) for matrix 2:"))
    if (ch==1):
        if(r1==c1):
            trans1=[]
            for i in range(r1):
                t1=[]
                for j in range(c1):
                    t1.append(matrix1[j][i])
                trans1.append(t1)
            print("your tranposed matrix is:")
            display(r1,c1,trans1)
        else:
            print("matrix should be square matrix")
    elif(ch==2):
        if(r2==c2):
            trans2=[]
            for i in range(r2):
                t2=[]
                for j in range(c2):
                    t2.append(matrix2[j][i])
                trans2.append(t2)
            print("your tranposed matrix is:")
            display(r2,c2,trans2)
        else:
            print("matrix should be square matrix")
    
    else:
        print("invalid input")

    
else:
    print("invalid input")
        
    

        