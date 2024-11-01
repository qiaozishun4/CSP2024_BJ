#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
typedef long long ll;
ll n,t[10][50];
char c[8];
ll dian,hua;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>c;
        if(c[1]=='A'){
            dian=1;
        }else if(c[1]>='2'&&c[1]<='9'){
            dian=c[1]-'0';
        }else if(c[1]=='T'){
            dian=10;
        }else if(c[1]=='J'){
            dian=11;
        }else if(c[1]=='Q'){
            dian=12;
        }else if(c[1]=='K'){
            dian=13;
        }
        if(c[0]=='D'){
            hua=1;
        }else if(c[0]=='C'){
            hua=2;
        }else if(c[0]=='H'){
            hua=3;
        }else if(c[0]=='S'){
            hua=4;
        }
        t[hua][dian]++;
    }
    ll ans=0;
    for(int i=1;i<=4;i++){
        for(int j=1;j<=13;j++){
            if(t[i][j]==0){
                ans++;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
