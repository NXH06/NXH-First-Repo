#initial setup
print('Please input range for twin primes search.')
m=int(input('> Start:  '))
n=int(input('> End: '))
list=[]

#prime check function
def prime_check(j):
  for i in range (2, int(j)):
    if j%i==0:
      break
  else:
    return True

#twin prime search!
for i in range (m,n+1):
  if i>=3 and prime_check(i) == True:
    if prime_check(i+2) == True:
      list+=[{i,i+2}]
print('Twin primes found in provided range:',list)
