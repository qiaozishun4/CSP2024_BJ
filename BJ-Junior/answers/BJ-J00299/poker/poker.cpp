#include<bits/stdc++.h>
using namespace std;
map <string,int> d;
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin>>n;
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        string s;
        cin>>s;
        d[s]++;
        if(d[s]==1)
        {
            ans++;
        }
    }
    if(ans>=52)
    {
        cout<<"0";
    }
    else
    {
        cout<<52-ans;
    }
    return 0;
}
