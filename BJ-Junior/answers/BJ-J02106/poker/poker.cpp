#include<bits/stdc++.h>
using namespace std;
int n,a[5][15]={};
void f(string s){
    if(s[0]=='D'){
        if(s[1]>='2'&&s[1]<='9')a[1][s[1]-'0']=1;
        else if(s[1]=='A')a[1][1]= 1;
        else if(s[1]=='T')a[1][10]=1;
        else if(s[1]=='J')a[1][11]=1;
        else if(s[1]=='Q')a[1][12]=1;
        else a[1][13]=1;
    }else if(s[0]=='C'){
        if(s[1]>='2'&&s[1]<='9')a[2][s[1]-'0']=1;
        else if(s[1]=='A')a[2][1]= 1;
        else if(s[1]=='T')a[2][10]=1;
        else if(s[1]=='J')a[2][11]=1;
        else if(s[1]=='Q')a[2][12]=1;
        else a[2][13]=1;
    }else if(s[0]=='H'){
        if(s[1]>='2'&&s[1]<='9')a[3][s[1]-'0']=1;
        else if(s[1]=='A')a[3][1]= 1;
        else if(s[1]=='T')a[3][10]=1;
        else if(s[1]=='J')a[3][11]=1;
        else if(s[1]=='Q')a[3][12]=1;
        else a[3][13]=1;
    }else{
        if(s[1]>='2'&&s[1]<='9')a[4][s[1]-'0']=1;
        else if(s[1]=='A')a[4][1]= 1;
        else if(s[1]=='T')a[4][10]=1;
        else if(s[1]=='J')a[4][11]=1;
        else if(s[1]=='Q')a[4][12]=1;
        else a[4][13]=1;
    }
}
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    string S;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>S;
        f(S);
    }
    int cnt=52;
    for(int i=1;i<=4;i++){
        for(int j=1;j<=13;j++)cnt-=a[i][j];
    }cout<<cnt;
    return 0;
}