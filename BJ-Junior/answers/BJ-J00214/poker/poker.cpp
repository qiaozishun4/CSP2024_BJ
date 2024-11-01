#include<bits/stdc++.h>
using namespace std;
set<string>s;
int n;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        string p;
        cin>>p;
        s.insert(p);
    }
    int l=52-s.size();
    cout<<max(0,l);
    return 0;
}
