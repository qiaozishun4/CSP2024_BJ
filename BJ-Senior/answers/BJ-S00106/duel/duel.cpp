#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n;
    int a[10005],b[10005],c;
    cin>>n;
for(int i=1;i<=n;i++)
{
cin>>a[i];
}
for(int i=1;i<=n;i++)
{
if(a[i]>a[i+1])
{
b[i]=a[i+1];
b[i+1]=a[i];
}
else
{
b[i]=a[i];
}
}
for(int i=1;i<=n;i+=2)
{
  if(b[i]>b[i+1])
  {
    b[i+1]=0;
  }
}
for(int i=1;i<=n;i++)
{
    if(b[i]>0)
    {
        c++;
    }
}
cout<<c;
return 0;
}