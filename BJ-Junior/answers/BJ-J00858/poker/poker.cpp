#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    bool poker[4][13]={};
    char h,s;
    int n,hh,ss,lend=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>h>>s;
        if(h=='D'){
            hh=0;
        }else if(h=='C'){
            hh=1;
        }else if(h=='H'){
            hh=2;
        }else{
            hh=3;
        }
        if(s=='A'){
            ss=0;
        }else if(s=='T'){
            ss=9;
        }else if(s=='J'){
            ss=10;
        }else if(s=='Q'){
            ss=11;
        }else if(s=='K'){
            ss=12;
        }else{
            ss=s-49;
        }
        poker[hh][ss]=1;
    }
    for(int i=0;i<4;i++){
        for(int j=0;j<13;j++){
            if(!poker[i][j]){
                lend++;
            }
        }
    }
    cout<<lend;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
