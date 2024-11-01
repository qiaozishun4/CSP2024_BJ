#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    string s;
    set<string>a;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s;
        a.insert(s);
    }
    cout<<52-a.size();
    return 0;
}
