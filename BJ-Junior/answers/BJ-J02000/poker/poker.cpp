#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
int tong[4][13]={};
int n=0,ans=0;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=0 ; i<n ; i++){
        string str;
        cin>>str;
        char huase=str[0];
        char dianshu=str[1];
        int hs=-1 , ds=-1 ;
        if(huase=='D'){
            hs=0;
        }else if(huase=='C'){
            hs=1;
        }else if(huase=='H'){
            hs=2;
        }else if(huase=='S'){
            hs=3;
        }
        if(dianshu=='A'){
            ds=0;
        }else if(dianshu=='T'){
            ds=9;
        }else if(dianshu=='J'){
            ds=10;
        }else if(dianshu=='Q'){
            ds=11;
        }else if(dianshu=='K'){
            ds=12;
        }else{
            ds=dianshu-1;
        }
        tong[hs][ds]=1;
    }
    for(int i=0 ; i<4 ; i++ ){
        for(int j=0 ; j<13 ; j++){
            if(tong[i][j]==0){
                ans++;
            }
        }
    }
    cout<<ans;
    return 0 ;
}
