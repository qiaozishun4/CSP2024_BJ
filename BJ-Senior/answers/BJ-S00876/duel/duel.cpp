#include<bits/stdc++.h>
using namespace std;
int n,r[100010],x[100010],sum=0;
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>r[i];
        x[r[i]]++;
    }
    for(int i=1;i<=100000;i++)
    {
        sum=max(sum,x[i]);
    }
    cout<<sum;
    return 0;
}
