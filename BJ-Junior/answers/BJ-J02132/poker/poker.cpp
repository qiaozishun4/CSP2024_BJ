#include<bits/stdc++.h>
using namespace std;
map<string,bool> m;
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin>>n;
    int ans=52;
    for(int i=1;i<=n;i++)
    {
        string s;
        cin>>s;
        if(!m[s])
        {
            ans--;
            m[s]=true;
        }
    }
    cout<<ans;
    return 0;
}
