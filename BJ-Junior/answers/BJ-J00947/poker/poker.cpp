#include<bits/stdc++.h>
using namespace std;
int n;
map<string,bool> m;
signed main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n;
    for(int i=1;i<=n;i++){
        string s;
        cin>>s;
        if(m.count(s)==0){
            m[s]=true;
        }
    }
    int cnt=0;
    for(auto p:m){
        cnt++;
    }
    cout<<52-cnt<<endl;
    return 0;
}
