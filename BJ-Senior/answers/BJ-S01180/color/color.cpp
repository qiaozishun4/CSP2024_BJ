#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5,M=1e6+5;

int t,n,a[N];
bool f[M];
long long ans;
map<int,int> mp;
vector<int> v;
void dfs(int be)
{
    int lar=0,lab=0;
    long long sum=0;
    for(int i=1;i<=n;i++)
    {
        //red
        if(f[a[i]])
        {
            if(lar==a[i])
            {
                sum+=a[i];
            }
            lar=a[i];
        }
        else
        {
            if(lab==a[i])
            {
                sum+=a[i];
            }
            lab=a[i];
        }
    }
    ans=max(ans,sum);
    for(int i=be;i<=n;i++)
    {
        f[a[i]]=1;
        dfs(i+1);
        f[a[i]]=0;
    }
}
int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    cin>>t;
    while(t--)
    {
        ans=0;
        mp.clear();
        v.clear();
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            mp[a[i]]++;
        }
        dfs(1);
        cout<<ans<<endl;
    }
    return 0;
}