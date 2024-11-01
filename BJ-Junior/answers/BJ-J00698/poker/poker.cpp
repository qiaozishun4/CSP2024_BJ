#include<bits/stdc++.h>
using namespace std;
int n,sum=0;
int a[5][15];
int iff(char c){
    if(c=='D') return 1;
    if(c=='C') return 2;
    if(c=='H') return 3;
    if(c=='S') return 4;
    if(c=='A') return 1;
    if(c=='T') return 10;
    if(c=='J') return 11;
    if(c=='Q') return 12;
    if(c=='K') return 13;
    return c-'0';
}
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    string s;
    for(int i=1;i<=n;i++){
        cin>>s;
        a[iff(s[0])][iff(s[1])]++;
    }
    for(int i=1;i<=4;i++){
        for(int j=1;j<=13;j++){
            if(a[i][j]==0){
                sum++;
            }
        }
    }
    cout<<sum;
    return 0;
}
