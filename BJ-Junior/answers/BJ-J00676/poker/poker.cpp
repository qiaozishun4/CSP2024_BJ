#include<iostream>
#include<algorithm>
#include<string>
#include<queue>
#include<vector>
#include<map>
#include<set>
using namespace std;
bool k[8][15];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n,cnt=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        char a,b;
        int c,d;
        cin>>a>>b;
        if(a=='D') c=1;
        if(a=='C') c=2;
        if(a=='H') c=3;
        if(a=='S') c=4;
        if(b>='2'&&b<='9') d=b-'0';
        if(b=='A') d=1;
        if(b=='T') d=10;
        if(b=='J') d=11;
        if(b=='Q') d=12;
        if(b=='K') d=13;
        k[c][d]=true;
    }
    for(int i=1;i<=4;i++) for(int j=1;j<=13;j++) if(!k[i][j]) cnt++;
    cout<<cnt;
    return 0;
    fclose(stdin);
    fclose(stdout);
}
