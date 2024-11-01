#include<bits/stdc++.h>
using namespace std;
const int N=100;
int n;
char col,nm;
bool cnt[5][N];
inline int f(char c){
    if(c>='2'&&c<='9')return c-'0';
    if(c=='A')return 1;
    if(c=='T')return 10;
    if(c=='J')return 11;
    if(c=='Q')return 12;
    if(c=='K')return 13;
}
inline int g(char col){
    if(col=='D')return 1;
    if(col=='C')return 2;
    if(col=='H')return 3;
    if(col=='S')return 4;
}
int ans;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>col>>nm;
        cnt[g(col)][f(nm)]=1;
    }
    for(int i=1;i<=4;i++){
        for(int j=1;j<=13;j++){
            if(!cnt[i][j])++ans;
        }
    }
    cout<<ans<<'\n';
    return 0;
}
