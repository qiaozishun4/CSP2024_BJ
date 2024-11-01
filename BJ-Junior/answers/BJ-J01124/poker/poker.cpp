#include<bits/stdc++.h>
using namespace std;
map<string,bool>mp;
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    long long n,cnt=0;
    cin>>n;
    for(long long i=1;i<=n;i++)
    {
        string s;
        cin>>s;
        if(mp[s])continue;
        else{
            mp[s]=true;
            cnt++;
        }
    }
    cout<<52-cnt<<endl;
    return 0;
}