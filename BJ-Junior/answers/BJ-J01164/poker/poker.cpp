#include<bits/stdc++.h>
using namespace std;
map<string,int> mp;
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        string s;
        cin >>s;
        mp[s]=1;
    }
    int cnt=0;
    for(auto s=mp.begin();s!=mp.end();s++){
        cnt++;
    }
    cout<<52-cnt;
    fclose(stdin);
    fclose(stdout);
    return 0;
}