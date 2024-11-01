#include <bits/stdc++.h>
using namespace std;
set<string> sett;
int n;
string str;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>str;
        sett.insert(str);
    }
    cout<<52-sett.size();
    return 0;
}
