#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=64,M=20;
ll n,res;
bool tong[5][M];
string pok;
ll h(char c){
    if(c=='D'){
        return 1;
    }
    if(c=='C'){
        return 2;
    }
    if(c=='H'){
        return 3;
    }
    return 4;
}
ll H(char c){
    if(c=='A'){
        return 1;
    }
    if(c=='T'){
        return 10;
    }
    if(c=='J'){
        return 11;
    }
    if(c=='Q'){
        return 12;
    }
    if(c=='K'){
        return 13;
    }
    return c-'0';
}
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(ll i=1;i<=n;i++){
        cin>>pok;
        tong[h(pok[0])][H(pok[1])]=1;
    }
    if(n==1){
        cout<<51;
        return 0;
    }
    for(ll i=1;i<=4;i++){
        for(ll j=1;j<=13;j++){
            if(!tong[i][j]){
                res++;
            }
        }
    }
    cout<<res;

    return 0;
}
