#include<bits/stdc++.h>
using namespace std;
int n,ans;
char a,b;
bool f[10][100];
int shu(char c){
    if(c>='2'&&c<='9') return (c-'0');
    if(c=='A') return 1;
    if(c=='T') return 10;
    if(c=='J') return 11;
    if(c=='Q') return 12;
    return 13;
}
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a>>b;
        int x=shu(b);
        if(a=='D'){
            f[1][x]=true;
        }else if(a=='C'){
            f[2][x]=true;
        }else if(a=='H'){
            f[3][x]=true;
        }else f[4][x]=true;
    }
    for(int i=1;i<=4;i++){
        for(int j=1;j<=13;j++){
            if(f[i][j]==false) ans++;
        }
    }
    cout<<ans;
    return 0;
}
