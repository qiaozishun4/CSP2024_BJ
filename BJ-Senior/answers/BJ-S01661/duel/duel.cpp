#include<iostream>
#include<cstdio>

#include<algorithm>
using namespace std;
int n;
int z[100010];
int y[100010];
int ans,mx;
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    ans=0;
    mx=0;
    cin >>n;
    for(int i=1;i<=n;i++)
    {
        cin >>z[i];
        y[z[i]]++;
        mx=max(mx,z[i]);
    }
    for(int i=1;i<=mx;i++)
    {
        ans=max(ans,y[i]);
    }
    cout <<ans;
}
