#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
map<string,bool> m;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        string s;
        cin>>s;
        m[s]=1;
    }
    int ans=0;
    auto pos=m.begin();
    while(pos!=m.end()){
        ans++;
        pos++;
    }
    cout<<52-ans;
    return 0;
}
