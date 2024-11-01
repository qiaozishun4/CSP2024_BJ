#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n,C[14]={},D[14]={},H[14]={},S[14]={},sum=0;
    cin>>n;
    if(n==1){
        cout<<51;
        return 0;
    }
    while(n--){
        string x;
        cin>>x;
        if(x[0]=='C'){
            int sz;
            if(x[1]=='A') sz=1;
            else if(x[1]=='T') sz=10;
            else if(x[1]=='J') sz=11;
            else if(x[1]=='Q') sz=12;
            else if(x[1]=='K') sz=13;
            else sz=x[1]-'0';
            C[sz]++;
        }
        if(x[0]=='D'){
            int sz;
            if(x[1]=='A') sz=1;
            else if(x[1]=='T') sz=10;
            else if(x[1]=='J') sz=11;
            else if(x[1]=='Q') sz=12;
            else if(x[1]=='K') sz=13;
            else sz=x[1]-'0';
            D[sz]++;
        }
        if(x[0]=='H'){
            int sz;
            if(x[1]=='A') sz=1;
            else if(x[1]=='T') sz=10;
            else if(x[1]=='J') sz=11;
            else if(x[1]=='Q') sz=12;
            else if(x[1]=='K') sz=13;
            else sz=x[1]-'0';
            H[sz]++;
        }
        if(x[0]=='S'){
            int sz;
            if(x[1]=='A') sz=1;
            else if(x[1]=='T') sz=10;
            else if(x[1]=='J') sz=11;
            else if(x[1]=='Q') sz=12;
            else if(x[1]=='K') sz=13;
            else sz=x[1]-'0';
            S[sz]++;
        }
    }
    for(int i=1;i<=13;i++) if(!C[i]) sum++;
    for(int i=1;i<=13;i++) if(!H[i]) sum++;
    for(int i=1;i<=13;i++) if(!D[i]) sum++;
    for(int i=1;i<=13;i++) if(!S[i]) sum++;
    cout<<sum;
    return 0;
}
