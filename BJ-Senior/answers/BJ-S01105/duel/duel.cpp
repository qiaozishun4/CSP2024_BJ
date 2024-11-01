#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,a[N],ans,k;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    k=0;
    for(int i=1;i<n;i++)
    {
        if(a[k]<a[i])
        {
            k++;
        }
    }
    cout<<n-k;
    return 0;
}
