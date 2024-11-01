#include<bits/stdc++.h>
using namespace std;
bool D[14];
bool C[14];
bool H[14];
bool S[14];
int n;
string s;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    while(n--){
        cin>>s;
        if(s=="DA") D[1]=1;
        if(s=="D2") D[2]=1;
        if(s=="D3") D[3]=1;
        if(s=="D4") D[4]=1;
        if(s=="D5") D[5]=1;
        if(s=="D6") D[6]=1;
        if(s=="D7") D[7]=1;
        if(s=="D8") D[8]=1;
        if(s=="D9") D[9]=1;
        if(s=="DT") D[10]=1;
        if(s=="DJ") D[11]=1;
        if(s=="DQ") D[12]=1;
        if(s=="DK") D[13]=1;
        if(s=="CA") C[1]=1;
        if(s=="C2") C[2]=1;
        if(s=="C3") C[3]=1;
        if(s=="C4") C[4]=1;
        if(s=="C5") C[5]=1;
        if(s=="C6") C[6]=1;
        if(s=="C7") C[7]=1;
        if(s=="C8") C[8]=1;
        if(s=="C9") C[9]=1;
        if(s=="CT") C[10]=1;
        if(s=="CJ") C[11]=1;
        if(s=="CQ") C[12]=1;
        if(s=="CK") C[13]=1;
        if(s=="HA") H[1]=1;
        if(s=="H2") H[2]=1;
        if(s=="H3") H[3]=1;
        if(s=="H4") H[4]=1;
        if(s=="H5") H[5]=1;
        if(s=="H6") H[6]=1;
        if(s=="H7") H[7]=1;
        if(s=="H8") H[8]=1;
        if(s=="H9") H[9]=1;
        if(s=="HT") H[10]=1;
        if(s=="HJ") H[11]=1;
        if(s=="HQ") H[12]=1;
        if(s=="HK") H[13]=1;
        if(s=="SA") S[1]=1;
        if(s=="S2") S[2]=1;
        if(s=="S3") S[3]=1;
        if(s=="S4") S[4]=1;
        if(s=="S5") S[5]=1;
        if(s=="S6") S[6]=1;
        if(s=="S7") S[7]=1;
        if(s=="S8") S[8]=1;
        if(s=="S9") S[9]=1;
        if(s=="ST") S[10]=1;
        if(s=="SJ") S[11]=1;
        if(s=="SQ") S[12]=1;
        if(s=="SK") S[13]=1;
    }
    int ans=0;
    for(int i=1;i<=13;i++){
        if(D[i]==true) ans++;
        if(C[i]==true) ans++;
        if(H[i]==true) ans++;
        if(S[i]==true) ans++;
    }
    cout<<52-ans;
    return 0;
}
