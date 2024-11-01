#include<iostream>
using namespace std;
struct p{
    char a;
    char b;
}poker[105];
int n;
int num;
bool tong[5][15];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>poker[i].a>>poker[i].b;
        if(poker[i].b=='A') poker[i].b=1;
        else if(poker[i].b=='T') poker[i].b=10;
        else if(poker[i].b=='J') poker[i].b=11;
        else if(poker[i].b=='Q') poker[i].b=12;
        else if(poker[i].b=='K') poker[i].b=13;
        else poker[i].b-='0';
        if(poker[i].a=='D') tong[0][poker[i].b]=true;
        else if(poker[i].a=='C') tong[1][poker[i].b]=true;
        else if(poker[i].a=='H') tong[2][poker[i].b]=true;
        else if(poker[i].a=='S') tong[3][poker[i].b]=true;
    }
    num=52;
    for(int i=0;i<=3;i++){
        for(int j=1;j<=13;j++){
            if(tong[i][j]){
                num--;
            }
        }
    }
    cout<<num;
    return 0;
}
