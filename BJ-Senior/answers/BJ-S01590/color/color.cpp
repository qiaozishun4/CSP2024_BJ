#include <bits/stdc++.h>
using namespace std;
int t,n,x;
long long ans;
int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    cin>>t;
    while(t--)
    {
        map<int,int>mp;
        map<int,int>::iterator it;
        ans=0;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>x;
            mp[x]++;
        }
        for(it=mp.begin();it!=mp.end();it++)
        {
            if((it->second)>1)
            {
                ans+=(it->first)*(it->second-1);
                //cout<<ans<<' '<<(it->first)<<' '<<it->second-1<<';';
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
