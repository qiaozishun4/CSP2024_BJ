#include<bits/stdc++.h>
using namespace std;

set<string>s;

int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;cin>>n;
    string str;
    for(int i=0;i<n;i++){
        cin>>str;
        s.insert(str);
    }
    cout<<52-s.size()<<endl;
    return 0;
}
