#setup
mode=input('INPUT 1 FOR B-D CONVERSION AND 2 FOR D-B CONVERSION --- ')
if mode=='1':
  n=int(input('INPUT THE BINARY NUMBER: '))
elif mode=='2':
  n=int(input('INPUT THE DECIMAL NUMBER: '))
else:
  print('INVALID RESPONSE. PLEASE RESTART PROGRAM.')

#core script!
nc=0
n_s=0
if mode=='1':
  n_s=str(n)
  for i in range(0,len(n_s)):
    nc+=int(n_s[len(n_s)-i-1])*(2**i)
if mode=='2':
  nc=''
  n_s=n
  def DtB(a):
    if a>=1:
      nc+=str(a%2)
      DtB(a)
  DtB(n_s)
print('         ___',nc,'___')