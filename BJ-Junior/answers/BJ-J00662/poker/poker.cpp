#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n,kun1[100][100]={},sum=0;
    cin>>n;
    string q;
    for(int i=1;i<=n;i++){
        cin>>q;
        int jnjn;
        if(q[0]=='D') jnjn=1;
        else if(q[0]=='C') jnjn=2;
        else if(q[0]=='H') jnjn=3;
        else jnjn=4;
        int jnjn2;
        if(q[1]=='A'){
            jnjn2=1;
        }else if(q[1]=='T'){
            jnjn2=10;
        }else if(q[1]=='J'){
            jnjn2=11;
        }else if(q[1]=='Q'){
            jnjn2=12;
        }else if(q[1]=='K'){
            jnjn2=13;
        }else{
            jnjn2=q[1]-'0';
        }kun1[jnjn][jnjn2]=1;
    }for(int i=1;i<=4;i++){
        for(int j=1;j<=13;j++){
            if(kun1[i][j]==0){
                sum++;
            }
        }
    }cout<<sum;
    return 0;
}
