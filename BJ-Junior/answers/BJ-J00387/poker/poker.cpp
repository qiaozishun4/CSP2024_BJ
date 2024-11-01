#include<bits/stdc++.h>
using namespace std;
int a[5][14];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        char x,y;
        cin>>x>>y;
        int hs=0,num=0;
        if(x=='D'){
            hs=1;
        }else if(x=='C'){
            hs=2;
        }else if(x=='H'){
            hs=3;
        }else{
            hs=4;
        }
        if(y=='A'){
            num=1;
        }else if(y=='T'){
            num=10;
        }else if(y=='J'){
            num=11;
        }else if(y=='Q'){
            num=12;
        }else if(y=='K'){
            num=13;
        }else{
            num=((int)y)-48;
        }
        a[hs][num]=1;
    }
    int ans=52;
    for(int i=1;i<=4;i++){
        for(int j=1;j<=13;j++){
            if(a[i][j]){
                ans--;
            }
        }
    }
    cout<<ans;
    return 0;
}
