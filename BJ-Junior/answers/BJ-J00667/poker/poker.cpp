#include<iostream>
using namespace std;
int n,x,ans=0;
char cc1,cc2;
int a[5][14];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=4;i++){
        for(int j=1;j<=13;j++){
            a[i][j]=0;
        }
    }
    for(int i=0;i<n;i++){
        cin>>cc1>>cc2;
        if(cc2=='A'){
            x=1;
        }else if(cc2=='T'){
            x=10;
        }else if(cc2=='J'){
            x=11;
        }else if(cc2=='Q'){
            x=12;
        }else if(cc2=='K'){
            x=13;
        }else{
            x=cc2-'0';
        }
        if(cc1=='D'){
            a[1][x]=1;
        }else if(cc1=='C'){
            a[2][x]=1;
        }else if(cc1=='H'){
            a[3][x]=1;
        }else if(cc1=='S'){
            a[4][x]=1;
        }
    }
    for(int i=1;i<=4;i++){
        for(int j=1;j<=13;j++){
            ans+=a[i][j];
        }
    }
    cout<<52-ans;
    return 0;
}
