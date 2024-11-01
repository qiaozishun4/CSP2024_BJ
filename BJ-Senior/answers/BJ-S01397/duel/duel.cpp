#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;
int n,a[maxn],n1,n2;
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++)
    {
        if(a[i]>a[i-1])
        {
            n1+=n2;
            n2=0;
        }
        if(n1>0) n1--;
        n2++;
    }
    cout<<n1+n2<<'\n';
    return 0;
}
