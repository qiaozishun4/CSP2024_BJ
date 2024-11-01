#include<bits/stdc++.h>
using namespace std;
bool table[10][20];
int ans=0;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin>>n;
    string t;
    for(int i=1;i<=n;i++){
        cin>>t;
        int a,b;
        if(t[0]=='D') a=1;
        else if(t[0]=='C') a=2;
        else if(t[0]=='H') a=3;
        else if(t[0]=='S') a=4;
        if(t[1]=='T') b=10;
        else if(t[1]=='J') b=11;
        else if(t[1]=='Q') b=12;
        else if(t[1]=='K') b=13;
        else if(t[1]=='A') b=1;
        else b=t[1]-'0';
        if(!table[a][b]) ans++;
        table[a][b]=true;
    }
    cout<<52-ans;
    return 0;
}
