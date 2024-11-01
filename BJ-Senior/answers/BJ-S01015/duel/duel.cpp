#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,ans=0;
int a[N],v[N];
queue<int> q;
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=n;i>=1;i--)
    {
        if(!q.empty()&&a[q.front()]>a[i]) 
        {
            q.pop();
            ans++;
            v[i]=1;
        }
        q.push(i);
    }
    cout<<n-ans<<"\n";
    return 0;
}
