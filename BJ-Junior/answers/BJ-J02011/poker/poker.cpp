#include<bits/stdc++.h>
using namespace std;
set <string> wc;
int main(){

    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n; cin >> n;
    string tm;
    for(int i=1;i<=n;i++){
        cin>>tm;
        wc.insert(tm);
    }
    cout << 52-wc.size() << '\n';
    return 0;
}
