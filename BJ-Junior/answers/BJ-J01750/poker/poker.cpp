#include<iostream>
using namespace std;
const int Maxn=15;
int D[Maxn]/*fangpian*/,C[Maxn]/*caohua*/,H[Maxn]/*hongtao*/,S[Maxn]/*heitao*/,n;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    char a,b;
    while(n--){
        cin>>a>>b;
        if(a=='D'){
            if(b>'1'&&b<='9')D[b-'0']++;
            else if(b=='A')D[1]++;
            else if(b=='T')D[10]++;
            else if(b=='J')D[11]++;
            else if(b=='Q')D[12]++;
            else if(b=='K')D[13]++;
        }if(a=='C'){
            if(b>'1'&&b<='9')C[b-'0']++;
            else if(b=='A')C[1]++;
            else if(b=='T')C[10]++;
            else if(b=='J')C[11]++;
            else if(b=='Q')C[12]++;
            else if(b=='K')C[13]++;
        }if(a=='H'){
            if(b>'1'&&b<='9')H[b-'0']++;
            else if(b=='A')H[1]++;
            else if(b=='T')H[10]++;
            else if(b=='J')H[11]++;
            else if(b=='Q')H[12]++;
            else if(b=='K')H[13]++;
        }if(a=='S'){
            if(b>'1'&&b<='9')S[b-'0']++;
            else if(b=='A')S[1]++;
            else if(b=='T')S[10]++;
            else if(b=='J')S[11]++;
            else if(b=='Q')S[12]++;
            else if(b=='K')S[13]++;
        }
    }
    int ans=0;
    for(int i=1;i<=13;i++){
        if(D[i])ans++;
        if(H[i])ans++;
        if(C[i])ans++;
        if(S[i])ans++;
    }
    cout<<52-ans<<endl;
    return 0;
}
