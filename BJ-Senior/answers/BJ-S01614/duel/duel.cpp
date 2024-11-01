#include <bits/stdc++.h>
using namespace std;
int n,a[100005],sum;
bool b[100005];
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a,a+n-1,greater<int>());
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(b[i]) continue;
            if(a[j]<a[i]) b[j]=1;
        }
    }
    for(int i=0;i<n;i++) if(b[i]) sum++;
    cout<<sum;
    return 0;
}