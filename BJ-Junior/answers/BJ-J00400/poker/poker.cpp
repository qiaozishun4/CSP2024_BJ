#include<bits/stdc++.h>
using namespace std;
string s;
map<char,map<char,bool> > mp;
int n,cnt;
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    while(n--)
    {
        cin>>s;
        if(!mp[s[0]][s[1]])
            cnt++;
        mp[s[0]][s[1]]=1;
    }
    cout<<52-cnt;
    return 0;
}