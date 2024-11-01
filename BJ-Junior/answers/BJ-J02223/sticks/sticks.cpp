#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
int num[]={6,2,5,5,4,5,6,3,7,6};
int t;
ll n;
ll dfs(ll n,ll x,ll minx,ll ans)
{
    if(n==1)
        return -1;
    else if(n==0)
    {
        return minx;
    }
    if(x==0)
    {
        for (int i=1; i<=9; ++i)
        {
            if(n>=num[i])
            {
                if(dfs(n-num[i],1,minx*10+i,ans)!=-1)
                {
                    ans=min(ans,dfs(n-num[i],1,minx*10+i,ans));
                }
                /*else{
                    cout << i << " ";
                }*/

                continue;
            }
        }
        return ans;
    }
    for (int i=0; i<=9; ++i)
    {
        if(n>=num[i])
        {
            if(dfs(n-num[i],1,minx*10+i,ans)!=-1)
            {
                ans=min(ans,dfs(n-num[i],1,minx*10+i,ans));
            }
            continue;
        }
    }
    return ans;
}
//6 0 0 1e9+10
//4 1 1 1e9+10
//
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin >> t;
    for (int G=1; G<=t; ++G)
    {
        cin >> n;
        if (n==1)
        {
            cout << -1 << endl;
            continue;
        }
        cout << dfs(n,0,0,1e9+10) << endl;
    }
    return 0;
}
