#include<bits/stdc++.h>
using namespace std;
bool b[1005][1005];
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin>>n;
    string s;
    int ans=52;
    for(int i=1; i<=n; i++)
    {
        cin>>s;
        if(b[(int)(s[0])][(int)(s[1])]==0)
            ans--;
        b[(int)(s[0])][(int)(s[1])]=1;
    }
    cout<<ans;
    return 0;
}