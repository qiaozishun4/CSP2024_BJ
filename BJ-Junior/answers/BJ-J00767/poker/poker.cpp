#include <bits/stdc++.h>
using namespace std;
bool D[15],C[15],H[15],S[15];
int n;
int h(char a){
    if(a=='A') return 1;
    if(a=='T') return 10;
    if(a=='J') return 11;
    if(a=='Q') return 12;
    if(a=='K') return 13;
    return (a-'0');
}
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.ans","w",stdout);
    cin>>n;
    char tmp,a;
    int cnt=0;
    for(int i=1;i<=n;i++){
        cin>>tmp>>a;
        if(tmp=='D') D[h(a)]=1;
        if(tmp=='C') C[h(a)]=1;
        if(tmp=='H') C[h(a)]=1;
        if(tmp=='S') S[h(a)]=1;
    }
    for(int i=1;i<=15;i++)
        if(D[i]) cnt++;
    for(int i=1;i<=15;i++)
        if(C[i]) cnt++;
    for(int i=1;i<=15;i++)
        if(H[i]) cnt++;
    for(int i=1;i<=15;i++)
        if(S[i]) cnt++;
    cout<<52-cnt;
    return 0;
}
