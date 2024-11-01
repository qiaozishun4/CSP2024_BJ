#include<bits/stdc++.h>
using namespace std;
int n,cnt;
const int N=15;
int D[N],C[N],H[N],S[N];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    while(n--){
        string a;
        cin>>a;
        if(a[0]=='D'){
            if(a[1]=='T') D[10]=1;
            else if(a[1]=='J') D[11]=1;
            else if(a[1]=='Q') D[12]=1;
            else if(a[1]=='K') D[13]=1;
            else if(a[1]=='A') D[1]=1;
            else D[a[1]-'0']=1;
        }
        if(a[0]=='C'){
            if(a[1]=='T') C[10]=1;
            else if(a[1]=='J') C[11]=1;
            else if(a[1]=='Q') C[12]=1;
            else if(a[1]=='K') C[13]=1;
            else if(a[1]=='A') C[1]=1;
            else C[a[1]-'0']=1;
        }
        if(a[0]=='H'){
            if(a[1]=='T') H[10]=1;
            else if(a[1]=='J') H[11]=1;
            else if(a[1]=='Q') H[12]=1;
            else if(a[1]=='K') H[13]=1;
            else if(a[1]=='A') H[1]=1;
            else H[a[1]-'0']=1;
        }
        if(a[0]=='S'){
            if(a[1]=='T') S[10]=1;
            else if(a[1]=='J') S[11]=1;
            else if(a[1]=='Q') S[12]=1;
            else if(a[1]=='K') S[13]=1;
            else if(a[1]=='A') S[1]=1;
            else S[a[1]-'0']=1;
        }
    }
    for(int i=1;i<=13;i++){
        if(D[i]==0) cnt++;
        if(C[i]==0) cnt++;
        if(H[i]==0) cnt++;
        if(S[i]==0) cnt++;
    }
    cout<<cnt;
    fclose(stdin);
    fclose(stdout);
    return 0;
}