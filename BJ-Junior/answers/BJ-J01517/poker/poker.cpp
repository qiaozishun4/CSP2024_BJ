#include<bits/stdc++.h>
using namespace std;
int n,ans;
bool vis[5][20];
int mp(char x){
    if('2'<=x && x<='9') return x-'0';
    if(x == 'A') return 1;
    if(x == 'T') return 10;
    if(x == 'J') return 11;
    if(x == 'Q') return 12;
    if(x == 'K') return 13;
}
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        char ch[5];
        cin>>ch;
        if(ch[0] == 'D'){
            vis[0][mp(ch[1])] = true;
        }
        else if(ch[0] == 'C'){
            vis[1][mp(ch[1])] = true;
        }
        else if(ch[0] == 'H'){
            vis[2][mp(ch[1])] = true;
        }
        else if(ch[0] == 'S'){
            vis[3][mp(ch[1])] = true;
        }
    }
    for(int i=0;i<=3;i++){
        for(int j=1;j<=13;j++){
            if(!vis[i][j]) ans++;
        }
    }
    printf("%d",ans);
    return 0;
}
