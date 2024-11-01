#include<bits/stdc++.h>
using namespace std;
int cnt[10][500];
int cla(char a){
    if(a=='D') return 1;
    else if(a=='C') return 2;
    else if(a=='H') return 3;
    else return 4;
}int cla2(char a){
    if(a>='0'&&a<='9') return a-'0';
    else if(a=='T') return 10;
    else if(a=='J') return 11;
    else if(a=='Q') return 12;
    else if(a=='K') return 13;
    else return 1;
}
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        string s;cin>>s;
        cnt[cla(s[0])][cla2(s[1])]=1;
    }int ans=0;
    for(int i=1;i<=4;i++){
        for(int j=1;j<=13;j++) if(cnt[i][j]==0) ans++;
    }cout<<ans;
    fclose(stdin);fclose(stdout);
    return 0;
}//jp8akioi