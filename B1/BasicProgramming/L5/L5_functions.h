int sumevenodd(int n, int mode)
{
   int sum_even=0; int sum_odd=0;
   for (int i=1;i<=n;i++)
   {
      if (i%2==0)
      {sum_even+=i;}
      else
      {sum_odd+=i;}
   }
   if (mode=0)
   {return sum_even;}
   else
   {return sum_odd;}
}