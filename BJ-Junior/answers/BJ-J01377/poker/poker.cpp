#include<iostream>
#include<string>
using namespace std;
int d[5][20];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n,a,b,cnt=0;
    string s;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s;
        if(s[0]=='D'){
            a=1;
        }
        if(s[0]=='C'){
            a=2;
        }
        if(s[0]=='H'){
            a=3;
        }
        if(s[0]=='S'){
            a=4;
        }
        if(s[1]=='A'){
            b=1;
        }else if(s[1]=='T'){
            b=10;
        }else if(s[1]=='J'){
            b=11;
        }else if(s[1]=='Q'){
            b=12;
        }else if(s[1]=='K'){
            b=13;
        }else{
            b=s[1]-'0';
        }
        d[a][b]=1;
    }
    for(int i=1;i<=4;i++){
        for(int j=1;j<=13;j++){
            if(!d[i][j]){
                cnt++;
            }
        }
    }
    cout<<cnt;
    return 0;
}