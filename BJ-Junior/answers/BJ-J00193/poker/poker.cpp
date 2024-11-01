#include<bits/stdc++.h>
using namespace std;
int n;
string s;
set<string> e;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s;
        e.insert(s);
    }cout<<52-e.size();
    return 0;
}
