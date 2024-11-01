#include<iostream>
#include<cstdio>
using namespace std;
int d[13];
int c[13];
int h[13];
int s[13];//m每种花色13张
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    char a;
    int ans=52;//共52张簰
    cin>>n;//已有牌
    for(int i=1;i<=n;i++){
        cin>>a;
        if(a=="DA"){
            d[1]++;}
        if(a=="D2"){
            d[2]++;}
        if(a=="D3"){
            d[3]++;}
        if(a=="D4"){
            d[4]++;}
        if(a=="D5"){
            d[5]++;}
        if(a=="D6"){
            d[6]++;}
        if(a=="D7"){
            d[7]++;}
        if(a=="D8"){
            d[8]++;}
        if(a=="D9"){
            d[9]++;}
        if(a=="DT"){
            d[10]++;}
        if(a=="DJ"){
            d[11]++;}
        if(a=="DQ"){
            d[12]++;}
        if(a=="DK"){
            d[13]++;}//A 2 3 4 5 6 7 8 9 T J Q K，一一对应
// ----------------------------
        if(a=="CA"){
            c[1]++;}
        if(a=="C2"){
            c[2]++;}
        if(a=="C3"){
            c[3]++;}
        if(a=="C4"){
            c[4]++;}
        if(a=="C5"){
            c[5]++;}
        if(a=="C6"){
            c[6]++;}
        if(a=="C7"){
            c[7]++;}
        if(a=="C8"){
            c[8]++;}
        if(a=="C9"){
            c[9]++;}
        if(a=="CT"){
            c[10]++;}
        if(a=="CJ"){
            c[11]++;}
        if(a=="CQ"){
            c[12]++;}
        if(a=="CK"){
            c[13]++;}
//---------------------------------------
        if(a=="HA"){
            h[1]++;}
        if(a=="H2"){
            h[2]++;}
        if(a=="H3"){
            h[3]++;}
        if(a=="H4"){
            h[4]++;}
        if(a=="H5"){
            h[5]++;}
        if(a=="H6"){
            h[6]++;}
        if(a=="H7"){
            h[7]++;}
        if(a=="H8"){
            h[8]++;}
        if(a=="H9"){
            h[9]++;}
        if(a=="HT"){
            h[10]++;}
        if(a=="HJ"){
            h[11]++;}
        if(a=="HQ"){
            h[12]++;}
        if(a=="HK"){
            h[13]++;}
//      -------------------------
        if(a=="SA"){
            s[1]++;}
        if(a=="S2"){
            s[2]++;}
        if(a=="S3"){
            s[3]++;}
        if(a=="S4"){
            s[4]++;}
        if(a=="S5"){
            s[5]++;}
        if(a=="S6"){
            s[6]++;}
        if(a=="S7"){
            s[7]++;}
        if(a=="S8"){
            s[8]++;}
        if(a=="S9"){
            s[9]++;}
        if(a=="ST"){
            s[10]++;}
        if(a=="SJ"){
            s[11]++;}
        if(a=="SQ"){
            s[12]++;}
        if(a=="SK"){
            s[13]++;}
    for(i=1;i<=13;i++){
        if(a[i]>0){
            ans--;
        }
    }
    for(i=1;i<=13;i++){
        if(c[i]>0){
            ans--;
        }
    }
    for(i=1;i<=13;i++){
        if(h[i]>0){
            ans--;
        }
    }
    for(i=1;i<=13;i++){
        if(s[i]>0){
            ans--;
        }
    }
    cout<<ans;
    return 0;}
