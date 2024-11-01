#include<bits/stdc++.h>
using namespace std;
map<string,int> m;
int ans=52;
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        string tmp;
        cin>>tmp;
        if(m[tmp]==0)
            ans--;
        m[tmp]++;
    }
    cout<<ans;
    return 0;
}
