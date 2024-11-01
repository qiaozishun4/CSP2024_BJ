#include<bits/stdc++.h>
using namespace std;
bool h[1005][1005]={false};
int n ,cnt=0; string st;
void runhash(string str) {
    char a=str[0] ,b=str[1];
    int num1 ,num2 ;
    if(a=='D') {
        num1=4;
    } else if(a=='C') {
        num1=1;
    } else if(a=='H') {
        num1=2;
    } else if(a=='S') {
        num1=3;
    }
    if('2'<=b && b<='9') {
        num2=b-'0';
    } else if(b=='T') {
        num2=10;
    } else if(b=='J') {
        num2=11;
    } else if(b=='Q') {
        num2=12;
    } else if(b=='K') {
        num2=13;
    } else if(b=='A') {
        num2=1;
    }
    h[num1][num2]=true;
}
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>st;
        runhash(st);
    } for(int i=1;i<=4;i++) {
        for(int j=1;j<=13;j++) {
            if(h[i][j]==false) {
                cnt++;
            }
        }
    } cout<<cnt;
    return 0;
}

