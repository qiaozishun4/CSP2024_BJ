#include<string>
#include<cstdio>
#include<iostream>
using namespace std;
int n,ans;
string s;
bool vis[10][20];
void f(char c,int j){
    if(c=='A'){
        vis[j][1]=1;
    }else if(c=='2'){
        vis[j][2]=1;
    }else if(c=='3'){
        vis[j][3]=1;
    }else if(c=='4'){
        vis[j][4]=1;
    }else if(c=='5'){
        vis[j][5]=1;
    }else if(c=='6'){
        vis[j][6]=1;
    }else if(c=='7'){
        vis[j][7]=1;
    }else if(c=='8'){
        vis[j][8]=1;
    }else if(c=='9'){
        vis[j][9]=1;
    }else if(c=='T'){
         vis[j][10]=1;
    }else if(c=='J'){
         vis[j][11]=1;
    }else if(c=='Q'){
         vis[j][12]=1;
    }else{
        vis[j][13]=1;
    }
    return;
}
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        cin>>s;
        if(s[0]=='D'){
            f(s[1],1);
        }else if(s[0]=='C'){
            f(s[1],2);
        }else if(s[0]=='H'){
            f(s[1],3);
        }else{
            f(s[1],4);
        }
    }for(int i=1;i<=4;++i){
        for(int j=1;j<=13;++j){
            if(vis[i][j]==0){
                ++ans;
            }
        }
    }printf("%d",ans);
    return 0;
}