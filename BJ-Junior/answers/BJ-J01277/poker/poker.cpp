#include<iostream>
using namespace std;
int n;
bool f[5][15];
int check(char x){
    if(x=='A') return 1;
    if(x>='2'&&x<='9') return x-'0';
    if(x=='T') return 10;
    if(x=='J') return 11;
    if(x=='Q') return 12;
    if(x=='K') return 13;
}
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        char a,b;
        cin>>a>>b;
        if(a=='D') {
            f[1][check(b)]=1;
        }else if(a=='C') f[2][check(b)]=1;
        else if(a=='H') f[3][check(b)]=1;
        else if(a=='S')f[4][check(b)]=1;
    }
    int ans=0;
    for(int i=1;i<=4;i++) for(int j=1;j<=13;j++) if(!f[i][j]) ans++;
    cout<<ans;
    return 0;
}
