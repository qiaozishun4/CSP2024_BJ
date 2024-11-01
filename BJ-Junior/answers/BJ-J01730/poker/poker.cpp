#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n=0;
    cin>>n;
    int a[5][14]={};
    for(int i=0;i<n;i++){
        char k,m;
        cin>>k>>m;
        int x=0,y=0;
        if(m=='A'){
            x=1;
        }else if(m=='T'){
            x=10;
        }else if(m=='J'){
            x=11;
        }else if(m=='Q'){
            x=12;
        }else if(m=='K'){
            x=13;
        }else{
            x=m-'0';
        }
        if(k=='D'){
            y=1;
        }else if(k=='C'){
            y=2;
        }else if(k=='H'){
            y=3;
        }else{
            y=4;
        }
        a[y][x]=1;
    }
    int ANs=0;
    for(int i=1;i<=4;i++){
        for(int j=1;j<=13;j++){
            if(a[i][j]==0){
                ANs++;
            }
        }
    }
    cout<<ANs;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
