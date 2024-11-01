#include<iostream>
#include<cstdio>
using namespace std;
int n,ans;
bool f[4][14];
int changeC(char c){
    if(c=='D') return 0;
    if(c=='C') return 1;
    if(c=='H') return 2;
    if(c=='S') return 3;
}
int changeN(char c){
    if(c=='A') return 1;
    if(c=='T') return 10;
    if(c=='J') return 11;
    if(c=='Q') return 12;
    if(c=='K') return 13;
    else return (c-'0');
}
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    while(n--){
        char a,b;
        cin>>a>>b;
        f[changeC(a)][changeN(b)]=true;
    }
    for(int i=0;i<4;i++) for(int j=1;j<=13;j++) if(!f[i][j]) ans++;
    cout<<ans<<endl;
    return 0;
}