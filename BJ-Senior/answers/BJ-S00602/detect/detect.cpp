#include <bits/stdc++.h>
using namespace std;
int n,r[100010];
int main()
{
freopen("duel.in","r",stdin);
freopen("duel.out","r",stdout);
cin>>n;
int ans=n;
for(int i=1;i<=n;i++)
{
cin>>r[i];
if(i>=2)
{
for(int j=0;j<=i;j++)
{
if(1+j<=n)
{
if(r[i-j]<r[1+j])
{
int Atri = r[1+j];
r[1+j]= r[i-j];
r[i-j]= Atri;
break;
}
}
}
}
}
for(int i=n;i>=0;i--)
{
for(int j=0;j<=n;j++)
{
if(i-j>=1)
{
if(1+j<=n)
{
if(r[i-j]>r[1+j])
ans--;
break;
}
}
}
}
cout<<ans;
return 0;
}