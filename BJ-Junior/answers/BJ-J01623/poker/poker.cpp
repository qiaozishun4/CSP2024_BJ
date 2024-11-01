#include<bits/stdc++.h>
using namespace std;
int n;
bool p[20][20];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    scanf("%d",&n);
    char a,b;
    for(int i=1;i<=n;++i){
        cin>>a>>b;
        if(a=='D'){
            a=1;
        }
        if(a=='C'){
            a=2;
        }
        if(a=='H'){
            a=3;
        }
        if(a=='S'){
            a=4;
        }
        if(b=='T'){
            b=10;
        }else if(b=='A'){
            b=1;
        }else if(b=='J'){
            b=11;
        }else if(b=='Q'){
            b=12;
        }else if(b=='K'){
            b=13;
        }else{
            b-='0';
        }
        p[a][b]=1;
    }
    int ans=0;
    for(int i=1;i<=4;++i){
        for(int j=1;j<=13;++j){
            ans+=(p[i][j]==0);
        }
    }
    printf("%d\n",ans);
    return 0;
}