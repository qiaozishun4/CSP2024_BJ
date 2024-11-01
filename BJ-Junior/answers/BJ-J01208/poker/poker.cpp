#include<iostream>
#include<map>
#include<string>
using namespace std;
map<string,int>mp;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        string s;
        cin>>s;
        mp[s]++;
    }
    cout<<52-mp.size();
    return 0;
}
