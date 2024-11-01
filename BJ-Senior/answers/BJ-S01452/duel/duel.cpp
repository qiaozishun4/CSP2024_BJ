#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[100005];
bool _dead[100005];
bool _used[100005];
signed main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+1+n);
    for(int i=1,j=2;i<=n&&j<=n;i++)
    {
        //j->i
        //cout<<"NOW WE HAVE"<<i<<","<<j<<endl;
        while((a[j]<=a[i]||_used[j])&&(j<=n))
            j++;
        //j kill i
        if(a[j]>a[i])
            _dead[i]=true,_used[j]=true;
    }
    int ans=n;
    for(int i=1;i<=n;i++)
        if(_dead[i])
            ans--;//,cout<<"NUMBER "<<i<<" IS DEAD\n";
    cout<<ans;
    return 0;
}
