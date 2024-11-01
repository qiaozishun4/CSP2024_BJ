#include<bits/stdc++.h>
using namespace std;
int n;
set<string>s;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        string s1;
        cin>>s1;
        s.insert(s1);
    }
    cout<<52-s.size();
    return 0;
}
