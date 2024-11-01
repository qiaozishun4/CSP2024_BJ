#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int main()
{
   freopen("explore.in","r",stdin);
   freopen("explore.out","w",stdout);
   int T,m,n,k,x,y,d;
   char a[1005][1005]={};
   char o;
   int cnt = 1;
   cin >> T;
   for(int i = 1;i<=T;i++)
   {
      cin >> n >> m >> k;
      cin >> x >> y >> d;
      for(int i = 1;i<=n;i++)
      {
         for(int j = 1;j<=m;j++)
         {
            cin >>o;
            a[i][j]=o;
         }
      }
      for(int i = 1;i<=k;i++)
      {
         if(d==0)
         {
            if(a[x][y+1]!='x'&&y+1<=m)
            {
               y = y+1;
               cnt++;
            }
            else
            {
               d = (d+1)%4;
            }
         }
         else if(d==1)
         {
            if(a[x+1][y]!='x'&&x+1<=n)
            {
               x = x+1;
               cnt++;
            }
            else
            {
               d = (d+1)%4;
            }
         }
         else if(d==2)
         {
            if(a[x][y-1]!='x'&&y-1>=1)
            {
               y = y-1;
               cnt++;
            }
            else
            {
               d = (d+1)%4;
            }
         }
         else 
         {
            if(a[x-1][y]!='x'&&x-1>=1)
            {
               x = x-1;
               cnt++;
            }
            else
            {
               d = (d+1)%4;
            }
         }
      }
   }
   cout << cnt;
   fclose(stdin);
   fclose(stdout);
   return 0;
}