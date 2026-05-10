#initial setup
print('Please input range to search for square triangles with integer sides.')
m=int(input('> Start:  '))
n=int(input('> End: '))

import math
list=[]

#square triangle check function
for c in range (m,n+1):
  for a in range (3, math.floor(c/math.sqrt(2))+1):
    for b in range (a+1, c):
      if a**2+b**2==c**2:
        list+=[(c,a,b)]

print('Square triangles found in provided range:',list)