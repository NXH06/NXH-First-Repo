int gcd_find(int a,int b)
{
   int gcd=1;
   for (int i=2;i<=a;i++)
   {
      if ((a%i==0) && (b%i==0))
      {gcd=i;}
   }
   return gcd;
}