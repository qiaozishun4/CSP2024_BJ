#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e6+5;
int T,n;
ll A[maxn],f[maxn],tag,mx;
int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>T;
    while(T--)
    {
        cin>>n;
        for(int i=1;i<=n;i++) cin>>A[i];
        for(int i=0;i<=1e6;i++) f[i]=-1e18;
        tag=f[0]=mx=0;
        for(int i=1;i<n;i++)
        {
            tag+=(A[i]==A[i+1])*A[i];
            f[A[i]]=max(f[A[i]],max(mx-(A[i]==A[i+1])*A[i],f[A[i+1]]-(A[i]==A[i+1])*A[i]+A[i+1]));
            mx=max(mx,f[A[i]]);
        }
        cout<<mx+tag<<'\n';
        //for(int i=1;i<=n;i++) cout<<A[i]<<' ';
        //cout<<'\n';
        //if(T==8) return 0;
    }
    return 0;
}
