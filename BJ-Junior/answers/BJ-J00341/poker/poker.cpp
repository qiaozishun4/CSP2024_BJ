#include<bits/stdc++.h>
using namespace std;
int zhh(char x){
    if(x=='T')return 10;
    if(x=='J')return 11;
    if(x=='Q')return 12;
    if(x=='K')return 13;
    if(x=='A')return 1;
    return x-48;
}
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    char hs,dx;
    int poker[5][14];
    cin>>n;
    for(int i=1;i<5;i++){
        for(int j=1;j<14;j++) poker[i][j]=1;
    }
    for(int i=0;i<n;i++){
        cin>>hs>>dx;
        //DCHS
        // cout<<hs<<' '<<zhh(dx)<<endl;
        if(hs=='D'){
            poker[1][zhh(dx)]=0;
        }
        if(hs=='C'){
            poker[2][zhh(dx)]=0;
        }
        if(hs=='H'){
            poker[3][zhh(dx)]=0;
        }
        if(hs=='S'){
            poker[4][zhh(dx)]=0;
        }
    }
    int cnt=0;
    for(int i=1;i<5;i++){
        for(int j=1;j<14;j++){
            // cout<<poker[i][j]<<' ';
            cnt+=poker[i][j];
        }
        // cout<<endl;
    }
    cout<<cnt;
    return 0;
}
