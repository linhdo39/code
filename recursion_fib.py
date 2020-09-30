def main():
  num = int(input("Enter a position ")) 
  while (num <=0):
    print('Invalid input. Please reenter value')
    num = int(input())
  for i in range (0,num,1):
    print(fib(i))

def fib(n):
  if (n==0):
    return 0
  elif (n==1):
    return 1
  else:
    n = fib(n-1) + fib(n-2) 
    return n 
 
main() 
