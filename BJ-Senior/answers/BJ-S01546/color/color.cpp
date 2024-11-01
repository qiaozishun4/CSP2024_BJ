#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<list>
#include<set>
#include<map>
#include<deque>
#include<queue>
#include<cstring>
#include<string>
#include<cmath>
#define endl '\n'
#define int long long
using namespace std;
int T,n,flag[1000005],pos[200005],a[200005];
bool co[200005];
long long ans;
long long solve(int l,int r)
{
    long long lost=0;
    if(l==r-1) return a[l];
    for(int i=l+1;i<=r-1;i++)
    {
        if(pos[i]==0||pos[i]<i) continue;
        if(pos[i]>r) lost+=a[i];
        else
        {
            lost+=solve(i,pos[i]);
            i=pos[i];
        }
    }
    if(1ll*a[l]>=lost) return a[l];
    return -1;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    cin>>T;
    while(T--)
    {
        memset(flag,0,sizeof(flag));
        memset(pos,0,sizeof(pos));
        memset(co,false,sizeof(co));
        ans=0;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            if(!flag[a[i]])
            {
                flag[a[i]]=i;
            }
            else
            {
                pos[i]=flag[a[i]];
                pos[flag[a[i]]]=i;
                flag[a[i]]=0;
            }
        }
        for(int i=1;i<=n;i++)
        {
            if(pos[i]==0||pos[i]<i) continue;
            long long k=solve(i,pos[i]);
            if(k==-1) continue;
            co[i]=co[pos[i]]=1;
            ans+=k;
            i=pos[i];
        }
        int lst=0;
        for(int i=1;i<=n;i++)
        {
            if(co[i]) continue;
            if(a[i]==lst)
            {
                ans+=a[i];
                lst=0;
            }
            else lst=a[i];
        }
        cout<<ans<<endl;
    }
    return 0;
}


