#include <bits/stdc++.h>
using namespace std;
int D[100], C[100], H[100], S[100];
int d(char a, int b){
    if(a=='D'){
        D[b]=1;
    }else if(a=='C'){
        C[b]=1;
    }else if(a=='H'){
        H[b]=1;
    }else if(a=='S'){
        S[b]=1;
    }
}
int main(){
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    int n, ans=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        char a, b, c;
        cin>>a>>b;
        if(b>='2'&&b<='9'){
            c=int(b-'0');
        }else if(b=='A'){
            c=1;
        }else if(b=='T'){
            c=10;
        }else if(b=='J'){
            c=11;
        }else if(b=='Q'){
            c=12;
        }else if(b=='K'){
            c=13;
        }
        d(a, c);
    }
    for(int i=1;i<=13;i++){
        if(D[i]==0){
            ans++;
        }
        if(C[i]==0){
            ans++;
        }
        if(H[i]==0){
            ans++;
        }
        if(S[i]==0){
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
