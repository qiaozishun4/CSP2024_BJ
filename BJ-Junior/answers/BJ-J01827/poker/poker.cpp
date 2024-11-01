#include<bits/stdc++.h>
using namespace std;
bool vis[300][300];
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n,cnt=0;
    char op,ai;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>op>>ai;
        if(vis[op][ai]) continue;
        vis[op][ai]=true;
        cnt++;
    }
    cout<<52-cnt;
    return 0;
}
