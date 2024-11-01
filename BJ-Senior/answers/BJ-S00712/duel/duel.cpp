#include<bits/stdc++.h>
using namespace std;
const int N=100003;
int a[N],c[N]={0};
int n,maxn;
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        c[a[i]]++;
    }
    for(int i=1;i<=1e5;i++)
    {
        maxn=max(maxn,c[i]);
    }
    cout<<maxn;
    return 0;
}
