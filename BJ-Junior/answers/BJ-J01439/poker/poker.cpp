#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    string x;
    int n,ans = 52;
    map<string,int> vis;
    cin>>n;
    for(int i = 1;i <= n;i++)
    {
        cin>>x;
        if(!vis[x])
        {
            vis[x]++;
            ans--;
        }
    }
    cout<<ans;
}
