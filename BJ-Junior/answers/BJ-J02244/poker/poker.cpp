#include <bits/stdc++.h>
using namespace std;
int a[5][14]={},x,y,cnt=0;
int n;
char c[5];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);

    cin>>n;
    for(int i = 0;i < n;i++){
        cin>>c;
        if(c[0]=='D') x=0;
        else if(c[0]=='C') x=1;
        else if(c[0]=='H') x=2;
        else x=3;
        if(c[1]>='2'&&c[1]<='9') y = c[1]-'0'-1;
        else if(c[1]=='A') y = 0;
        else if(c[1]=='T') y = 9;
        else if(c[1]=='J') y = 10;
        else if(c[1]=='Q') y = 11;
        else y = 12;
        a[x][y] ++;
    }
    for(int i = 0;i < 4;i++){
        for(int j = 0;j < 13;j++){
            if(a[i][j]==0) cnt++;
        }
    }
    cout<<cnt;
    return 0;
}
