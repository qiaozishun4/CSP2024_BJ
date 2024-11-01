#include<bits/stdc++.h>
using namespace std;
int n,x=0,y=0,cnt=0,a[5][14]={};
string c;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> c;
        if(c[0]=='D')x=1;
        if(c[0]=='C')x=3;
        if(c[0]=='H')x=2;
        if(c[0]=='S')x=4;
        if(c[1]=='A')y=1;
        if('2'<=c[1]&&c[1]<='9')y=c[1]-48;
        if(c[1]=='T')y=10;
        if(c[1]=='J')y=11;
        if(c[1]=='Q')y=12;
        if(c[1]=='K')y=13;
        if(0<x<5&&0<y<14)a [x][y]++;
    }
    for(int i=1;i<=4;i++){
        for(int j=1;j<=13;j++){
            if(a[i][j]==0){
                cnt++;
            }
        }
    }
    cout << cnt;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
