#include <bits/stdc++.h>
using namespace std;
int n;
bool vis[10][20];
char c[10];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
    cin>>n;
    while(n--){
        cin>>c;
        int x=0,y=0;
        if(c[0]=='D') x=1;
        else if(c[0]=='C') x=2;
        else if(c[0]=='H') x=3;
        else x=4;
        if('2'<=c[1]&&c[1]<='9') y=c[1]-'0';
        else if(c[1]=='A') y=1;
        else if(c[1]=='T') y=10;
        else if(c[1]=='J') y=11;
        else if(c[1]=='Q') y=12;
        else y=13;
        vis[x][y]=1;
    }
    int cnt=0;
    for(int i=1;i<=4;i++){
        for(int j=1;j<=13;j++){
            if(vis[i][j]==0) cnt++;
        }
    }
    cout<<cnt<<endl;
    return 0;
}
