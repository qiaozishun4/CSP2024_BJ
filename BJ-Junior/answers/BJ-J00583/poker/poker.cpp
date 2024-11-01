#include<bits/stdc++.h>
using namespace std;
int n,cnt;
bool vis[10][20];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    char col,num;
    for(int k=1;k<=n;k++){
        cin>>col>>num;
        int i,j;
        if(col=='D')i=1;
        if(col=='C')i=2;
        if(col=='H')i=3;
        if(col=='S')i=4;
        if(num>='2'&&num<='9')j=num-'0';
        else{
            if(num=='A')j=1;
            if(num=='T')j=10;
            if(num=='J')j=11;
            if(num=='Q')j=12;
            if(num=='K')j=13;
        }
        vis[i][j]=1;
    }
    for(int i=1;i<=4;i++){
        for(int j=1;j<=13;j++){
            if(!vis[i][j])cnt++;
        }
    }
    cout<<cnt<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}