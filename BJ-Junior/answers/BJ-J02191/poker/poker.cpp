#include<bits/stdc++.h>
using namespace std;
string a;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a;
    }
    if(n>=52) cout<<0;
    else cout<<52-n;
}
