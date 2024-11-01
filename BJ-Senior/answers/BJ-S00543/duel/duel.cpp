#include<bits/stdc++.h>
using namespace std;
struct node{
    int x;
}a[100005];
bool cmp(node x,node y)
{
    return x.x<y.x;
}
int n,ans=0;
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].x;
    }
   sort(a+1,a+n+1,cmp);
   for(int i=2;i<=n;i++)
   {
       int maxx=0;
       for(int j=1;j<=i-1;j++)
       {
           if(a[j].x<a[i].x) maxx=j;
       }
       if(maxx!=0) a[maxx].x=0;
   }
   for(int i=1;i<=n;i++)
   {
        if(a[i].x==0) ans++;
   }
   cout<<ans;
   return 0;
}