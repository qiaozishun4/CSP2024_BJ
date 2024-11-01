#include<bits/stdc++.h>
using namespace std;
int n;
string a;
set<string> vis;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    while(n--){
        cin>>a;
        vis.insert(a);
    }
    cout<<52-vis.size();
    return 0;
}
