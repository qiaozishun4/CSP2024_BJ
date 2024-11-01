#include<bits/stdc++.h>
using namespace std;
map<string,int> mp;
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        string s;
        cin>>s;
        if((s[0]=='D'||s[0]=='C'||s[0]=='H'||s[0]=='S')&&((s[1]>='2'&&s[1]<='9')||s[1]=='A'||s[1]=='T'||s[1]=='J'||s[1]=='Q'||s[1]=='K'))
            mp[s]++;
    }
    map<string,int>::iterator it;
    int cnt=0;
    for(it=mp.begin();it!=mp.end();it++)
    {
        if(it->second>0)
        {
            cnt++;
        }
    }
    cout<<52-cnt;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
