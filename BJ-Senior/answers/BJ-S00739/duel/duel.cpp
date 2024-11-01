#include<bits/stdc++.h>
using namespace std;
int r[100010],m[100010];
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>r[i];
        m[r[i]]++;
    }
    sort(r+1,r+n+1);
    int sum=0;
    for(int i=1;i<=100000;i++)
    {
        sum=max(0,sum-m[i])+m[i];
    }
    cout<<sum;
    return 0;
}
