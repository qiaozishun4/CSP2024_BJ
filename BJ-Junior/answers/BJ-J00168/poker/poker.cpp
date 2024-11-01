#include<bits/stdc++.h>
using namespace std;
long long n,ans;
bool poke[5][50];//分别表示花色与牌种

int main(){

    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        string s;
        cin>>s;
        long long pos1,pos2;
        if(s[0]=='D'){
            pos1=1;
        }else if(s[0]=='C'){
            pos1=2;
        }else if(s[0]=='H'){
            pos1=3;
        }else{
            pos1=4;
        }
        if(s[1]=='A'){
            pos2=1;
        }else if(s[1]=='T'){
            pos2=10;
        }else if(s[1]=='J'){
            pos2=11;
        }else if(s[1]=='Q'){
            pos2=12;
        }else if(s[1]=='K'){
            pos2=13;
        }else{
            pos2=s[1]-'0';
        }
        poke[pos1][pos2]=1;
    }
    for(int i=1;i<=4;i++){
        for(int j=1;j<=13;j++){
            if(!poke[i][j]){
                ans++;
            }
        }
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}