#include<bits/stdc++.h>
using namespace std;
map<string,bool>ji;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n,tot = 52;
    cin>>n;
    for(int i =1 ; i <= n ; i++){
        string c;
        cin>>c;
        if(ji[c] == 1)continue;
        ji[c] = 1;
        tot--;
    }
    cout<<tot;
    return 0;
}
