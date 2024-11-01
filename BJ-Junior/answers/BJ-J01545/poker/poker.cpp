#include<bits/stdc++.h>
using namespace std;
map<string,bool> mp;
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    string c;
    int k=52;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {

        cin>>c;
        if(mp[c]==false)
        {
            k--;
            mp[c]=true;
        }
    }
    cout<<k;
    return 0;
}