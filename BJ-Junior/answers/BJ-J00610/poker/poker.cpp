#include <bits/stdc++.h>
using namespace std;
int n,len;
string a;
set <string> s;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a;
        s.insert(a);
    }
    len=s.size();
    cout<<52-len;
    return 0;
}
