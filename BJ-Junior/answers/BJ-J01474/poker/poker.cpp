#include <bits/stdc++.h>
using namespace std;
int n;
string  a[105];
set <string> b;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        b.insert(a[i]);
    }
    cout<<(52-b.size())<<endl;
    return 0;
}
