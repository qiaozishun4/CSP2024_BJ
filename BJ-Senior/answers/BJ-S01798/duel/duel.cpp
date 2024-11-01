#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
const int INF=0x3f3f3f3f;
int n;
int a[N];
bool ded[N];
bool used[N];
int fa[N];
int cnt=0;
int f(int i)
{
    if(fa[i])
    {
        fa[i]--;
    }else{
        fa[i]=i;
    }
    return fa[i];
}
int ub(int l,int r,int k)
{
    int mid;
    while(l<=r)
    {
        mid=l+r>>1;
        if(a[mid]<k)
        {
            l=mid+1;
        }
        else
        {
            r=mid-1;
        }
    }
    return f(r);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=1; i<=n; i++)
    {
        if(!used[i]&&!ded[i])
        {
            int kil=ub(1,n,a[i]);
            if(kil!=0&&!ded[kil])
            {
                used[i]==true;
                ded[kil]=true;
                cnt++;
            }
        }

    }
    cout<<(n-cnt);
    return 0;
}
