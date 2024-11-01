#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    set<string>s;
    int n;
    cin>>n;
    string h;
    for(int i=0;i<n;i++){
        cin>>h;
        s.insert(h);
    }
    cout<<52-s.size();
    return 0;
}
