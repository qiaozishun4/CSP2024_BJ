#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("poker.in","w",stdin);
    freopen("poker.out","r",stdout);
    int n;
    cin>>n;
    string s;
    for(int i=1;i<=n;i++){
        cin>>s;
    }
    cout<<52-n;
    return 0;
}