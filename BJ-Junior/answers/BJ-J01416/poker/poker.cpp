#include <iostream>
using namespace std;
bool v[5][20];
int n,ans=52;
char a,b;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a>>b;
        if(a=='D'){
            if(b=='A')v[1][1]=1;
            else if(b=='T')v[1][10]=1;
            else if(b=='J')v[1][11]=1;
            else if(b=='Q')v[1][12]=1;
            else if(b=='K')v[1][13]=1;
            else v[1][b-'0']=1;
        }if(a=='C'){
            if(b=='A')v[2][1]=1;
            else if(b=='T')v[2][10]=1;
            else if(b=='J')v[2][11]=1;
            else if(b=='Q')v[2][12]=1;
            else if(b=='K')v[2][13]=1;
            else v[2][b-'0']=1;
        }if(a=='H'){
            if(b=='A')v[3][1]=1;
            else if(b=='T')v[3][10]=1;
            else if(b=='J')v[3][11]=1;
            else if(b=='Q')v[3][12]=1;
            else if(b=='K')v[3][13]=1;
            else v[3][b-'0']=1;
        }if(a=='S'){
            if(b=='A')v[4][1]=1;
            else if(b=='T')v[4][10]=1;
            else if(b=='J')v[4][11]=1;
            else if(b=='Q')v[4][12]=1;
            else if(b=='K')v[4][13]=1;
            else v[4][b-'0']=1;
        }
    }for(int i=1;i<=4;i++){
        for(int j=1;j<=13;j++){
            if(v[i][j])ans--;
        }
    }cout<<ans;
    return 0;
}
