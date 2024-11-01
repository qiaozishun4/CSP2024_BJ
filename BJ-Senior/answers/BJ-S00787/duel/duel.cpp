#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int a[N];
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    int i=1,j=2;
    while(i<n&&j<=n)
    {
        if(a[i]<a[j])
        {
            a[i]=0;
            i++,j++;
        }
        else j++;
    }
    int cnt=0;
    for(int i=1;i<=n;i++)
        if(a[i]>0) cnt++;
    cout<<cnt;
    return 0;
}
