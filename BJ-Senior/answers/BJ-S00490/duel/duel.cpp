#include<bits/stdc++.h>
using namespace std;
const int N=100001;
int n;
int a[N];
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin>>n;
    for (int i=1;i<=n;++i)
    {
        cin>>a[i];
    }
    int s=1,t=1,cnt=0;
    sort(a+1,a+n+1);
    while (t<=n)
    {
        if (a[s]<a[t])
        {
            ++s;
            ++t;
        }
        else
        {
            ++t;
        }
    }
    cout<<n-s+1<<endl;
    return 0;
}
