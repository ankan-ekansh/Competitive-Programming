# template begins 
##################################### 

# import libraries for input/ output handling 
# on generic level 
# import atexit, io, sys 

# A stream implementation using an in-memory bytes 
# buffer. It inherits BufferedIOBase. 
# buffer = io.BytesIO() 
# sys.stdout = buffer

# print via here 
# @atexit.register 
# def write(): 
# 	sys.__stdout__.write(buffer.getvalue()) 

##################################### 
# template ends 

# normal method followed 
# input N 

# t = int(input())
# for i in range(t):
#     n,z = map(int,input().split())

t = int(input())
mod = int(1000000007)
inv_mod = int(500000004) 
for i in range(t):
    n,k = map(int,input().split())
    # l = raw_input()
    # n,k = l.split()
    # n = long(n)
    # k = long(k)
    # x = long((k-1)/(n-1))
    x = (k-1)//(n-1)
    ans = ((((k-1)*(x+1))%mod) - ((((((n-1)*(x))%mod)*(x+1))%mod)*(inv_mod))%mod)%mod
    print(ans)


# input the array 
# arr = [long(x) for x in raw_input().split()] 


# initialize variable 
# summation = 0

# calculate sum 
# for x in arr: 
# 	summation += x 

# print answer 
# print(summation) 
