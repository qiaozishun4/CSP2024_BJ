#include <bits/stdc++.h>
using namespace std;
string s[101];
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n,ans=52,cmp=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cmp=0;
        cin>>s[i];
        for(int j=1;j<i;j++) if(s[i]==s[j]) cmp=1;
        if(cmp==0) ans--;
    }
    cout<<ans;
    return 0;
}
