#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("pocker.in","r",stdin);
    freopen("pocker.out","w",stdout);
   int n,s=1;
   string a[60];
   cin>>n;
   for(int i=0;i<n;i++)
   {
       cin>>a[i];
   }

   for(int i=1;i<n;i++)
   {
       int j;
       bool b=0;
       for(j=i-1;j>=0;j--)
       {
           if(a[j]==a[i])
           {

               b=1;
               break;
           }
           else
            {
                b=0;
           }
       }
       if(b==1)
       {
           s--;
       }
       s++;
   }

   cout<<52-s;

   fclose(stdin);
   fclose(stdout);
    return 0;
}
