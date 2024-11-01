#include<bits/stdc++.h>
using namespace std;
map<string,bool>m;
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    string s;
    cin>>n;
    int ans=52;
    for(int i=1;i<=n;i++)
    {
        cin>>s;
        if(m[s]==false)
        {
            m[s]=true;
            ans--;
        }
    }
    cout<<ans;
    return 0;
}
