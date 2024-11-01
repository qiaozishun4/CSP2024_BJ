#include<bits/stdc++.h>
using namespace std;
bool h[100];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    string x;
    int v,ans=0;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x;
        if(x[0]=='D') v=0;
        else if(x[0]=='C') v=13;
        else if(x[0]=='H') v=26;
        else v=39;
        if(x[1]=='A') v++;
        else if(x[1]=='T') v+=10;
        else if(x[1]=='J') v+=11;
        else if(x[1]=='Q') v+=12;
        else if(x[1]=='K') v+=13;
        else v+=int(x[1]-'0');
        h[v]=1;
    }
    for(int i=1;i<=52;i++){
        if(h[i]==0) ans++;
    }
    cout<<ans;
    return 0;
}
