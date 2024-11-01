#include <bits/stdc++.h>
using namespace std;
int n;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    char a[2][n];
    int ans=0;
    int b[14][5]={0};
    int x,y;
    for(int i=0;i<n;i++){
        cin>>a[1][i]>>a[2][i];
        if(a[1][i]=='D'){
            x=1;
        }
        else if(a[1][i]=='C'){
            x=2;
        }
        else if(a[1][i]=='H'){
            x=3;
        }
        else if(a[1][i]=='S'){
           x=4;
        }
        if(a[2][i]=='A'){
            y=1;
        }if(a[2][i]=='T'){
            y=10;
        }if(a[2][i]=='J'){
            y=11;
        }if(a[2][i]=='Q'){
            y=12;
        }if(a[2][i]=='K'){
            y=13;
        }else if(a[2][i]>='1' && a[2][i]<='9'){
            y=a[2][i];
            y=y-48;
        }
        b[y][x]=1;
    }
    for(int i=1;i<=13;i++){
        for(int j=1;j<=4;j++){
            if(b[i][j]==1) ans++;
        }
    }
    cout<<52-ans;
    return 0;
}
