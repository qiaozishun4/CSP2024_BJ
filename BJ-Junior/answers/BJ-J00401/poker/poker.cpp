#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
int f[200][5]={0};
int turn(char c){
    if(c=='A')return 1;
    else if(c=='T')return 10;
    else if(c=='J')return 11;
    else if(c=='Q')return 12;
    else if(c=='K')return 13;
    else return (c-48);
}
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n,sum=0;
    cin>>n;
    string s;
    for(int i=0;i<n;i++){
        cin>>s;
        if(s[0]=='D'){
            f[turn(s[1])][1]=1;
        }
        else if(s[0]=='C'){
            f[turn(s[1])][2]=1;
        }
        else if(s[0]=='H'){
            f[turn(s[1])][3]=1;
        }
        else if(s[0]=='S'){
            f[turn(s[1])][4]=1;
        }
    }
    for(int i=1;i<=13;i++){
        for(int j=1;j<=4;j++){
            if(f[i][j]==1){
                sum++;
            }
        }
    }
    cout<<52-sum;

    return 0;