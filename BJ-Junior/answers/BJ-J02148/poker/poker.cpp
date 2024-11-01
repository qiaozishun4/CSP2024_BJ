#include <bits/stdc++.h>
using namespace std;
string s[10010];
bool cmp(string x,string y)
{
    if(x!=y) return x<y;
}
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin>>n;
    int ans=0;
    for (int i=1;i<=n;i++)
    {
        cin>>s[i];
    }
    sort(s+1,s+n+1,cmp);
    for (int i=1;i<=n;i++)
    {
        while(s[i]==s[i+1])
        {
            i++;
            ans++;
        }
    }
    cout<<52-n+ans;
    return 0;
}