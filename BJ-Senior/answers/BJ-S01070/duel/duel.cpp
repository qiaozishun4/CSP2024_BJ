#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n;
    cin>>n;
    vector<int>s(n);
    map<int,int>mp;
    for(int i=0;i<n;i++){
        cin>>s[i];
        mp[s[i]]++;
    }
    int sy=mp.begin()->second;
    for(map<int,int>::iterator i=++mp.begin();i!=mp.end();i++){
        sy=max(sy,i->second);
    }
    cout<<sy;
    return 0;
}
//rp++++++++++ gao 100 pts