#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,cnt=0;
    cin>>n;
    freopen("poker.in","r",stdin);
    char ch[n+1];
    for(int i=1;i<=n;i++){
            cin>>ch[i];
        freopen("poker.in","r",stdin);
    }
    cout<<52-n;
    freopen("poker.out","w",stdout);
    return 0;
}