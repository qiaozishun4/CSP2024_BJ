#include<iostream>
#include<cstdio>
using namespace std;
int n,a[53];char c[53][2];
bool dp[4][13];
int c0(char m){
    if(m=='D')return 0;
    if(m=='C')return 1;
    if(m=='H')return 2;
    if(m=='S')return 3;
    return -1;
}
int c1(char n){
    if(n=='A')return 0;
    if(n=='T')return 9;
    if(n=='J')return 10;
    if(n=='Q')return 11;
    if(n=='K')return 12;
    return (int)n-'1';
}
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>c[i];
        int d=c0(c[i][0]);
        int e=c1(c[i][1]);
        dp[d][e]=true;
    }int cnt=0;
    for(int i=0;i<=3;i++){
        for(int j=0;j<=12;j++){
            if(!dp[i][j])cnt++;
        }
    }cout<<cnt;
    fclose(stdin);
    fclose(stdout);
    return 0;
}