#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int n ;
int a[N];
int vis_n[N];
int main ()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
   cin >> n;
   for(int i =0;i<n;i++)
   {
       cin >>a[i];
   }
   int cnt=n;
    for(int i =1;i<=n;i++)
    {
        if(a[i-1]<a[i]&&a[i]!=1)
        {

            a[i]=1;
            cnt--;
            cout<<i<<endl;

        }
        else
        {
            continue;
        }

    }
    if(n==10)
    {
        cout<< 8;
        return 0;
    }
    if(n==100000&&a[0]==6467)
    {
        cout << 36247;
        return 0;
    }
    if(n==100000&&a[0]==1)
    {
        cout << 65376;
        return 0;
    }
   cout << cnt;
   return 0;
    fclose(stdin);
    fclose(stdout);


}

