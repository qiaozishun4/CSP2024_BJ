#include <bits/stdc++.h>
using namespace std;
int n;
int r[100001];
int t[100001];
int cnt1;
int cnt2;
bool flag=true;
int main(){
cin>>n;
for(int i=1;i<=n;i++)
{
    cin>>r[i];
    t[r[i]]++;
    if(r[i]==1)
    {
        cnt1++;
    }
    else
    {
        cnt2++;
    }
}
for(int i=1;i<=n;i++)
{
    if(t[i]>1)
    {
        flag=false;
        break;
    }
}
if(flag==true)
{
    cout<<1;
}
else if(cnt1==cnt2)
{
    cout<<cnt1;
}
else if(cnt1>cnt2)
{
    cout<<n-cnt2;
}
else
{
    cout<<n-cnt1;
}
return 0;
}
