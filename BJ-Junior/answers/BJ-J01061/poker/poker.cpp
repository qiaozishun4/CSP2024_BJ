#include<iostream>
using namespace std;
int n,a[101][101];
string s;
int hs(char x){
    if(x=='D'){
        return 1;
    }else if(x=='C'){
        return 2;
    }else if(x=='H'){
        return 3;
    }else if(x=='S'){
        return 4;
    }
}
int hs2(char x){
    if(x>='2'&&x<='9'){
        return x-'0';
    }else if(x=='A'){
        return 1;
    }else if(x=='T'){
        return 10;
    }else if(x=='J'){
        return 11;
    }else if(x=='Q'){
        return 12;
    }else if(x=='K'){
        return 13;
    }
}
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s;
        a[hs(s[0])][hs2(s[1])]=1;
    }
    int ans=0;
    for(int i=1;i<=4;i++){
        for(int j=1;j<=13;j++){
            if(a[i][j]==0){
                ans++;
            }
        }
    }
    cout<<ans;
    return 0;
}
