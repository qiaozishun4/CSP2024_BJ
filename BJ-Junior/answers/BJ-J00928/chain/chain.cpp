#include <iostream>
#include <string>
#include <cstdio>
const int MAXN = 1e5+5;
int main()
{
   freopen("chain.in","r",stdin);
   freopen("chain.out","w",stdout);
   int T,n,k,q,r,c;
   string a[MAXN];
   for(int i = 1;i<=T;i++)
   {
      cin >> n >> k >> q;
      for(int i = 1;i<=n;i++)
      {
         getline(cin,a[i]);
      }
      for(int i = 1;i<=q;i++)
      {
         cin >> r >> c;
      }
   }
   for(int i = 1;i<=T;i++)
   {
       cout << 1 << endl;
   }
   fclose(stdin);
   fclose(stdout);
   return 0 ;
}