#include <iostream>
#include <cstdio>
using namespace std;
const int MAXN = 1e5+5;
int a[MAXN]
int mian()
{
   freopen("sticks.in","r",stdin);
   freopen("sticks.out","w",stdout);
   int n;
   cin >> n;
   for(int i=1;i<=n;i++)
   {
      cin >> a[i];
   }
   for(int i=1;i<=n;i++)
   {
      if(a[i]<2)
      {
         cout << -1;
      }
      else if(a[i]<7&&a[i]>=2)
      {
         if(a[i]==2)
         {
            cout << 1;
         }
         else if(a[i]==3)
         {
            cout << 7;
         }
         else if(a[i]==4)
         {
            cout << 4;
         }
         else if(a[i]==5)
         {
            cout << 2;
         }
         else if(a[i]==6)
         {
            cout << 6;
         }
      }
      else if(n==7)
      {
         cout << 8;
      }
      else
      {
         if(a[i]%7==0)
         {
            for(int i = 1;i<=a[i]/7;i++)
            {
               cout << 8;
            }
         }
         else
         {
            cout << a[i];
         }
      }
   }
   fclose(stdin);
   fclose(stdout);
   return 0;
}