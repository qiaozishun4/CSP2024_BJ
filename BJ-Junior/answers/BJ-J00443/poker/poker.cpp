#include<bits/stdc++.h>
using namespace std;
string s;
int S[20],D[20],C[20],H[20];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s;
        if(s[0]=='S'){
            if(s[1]=='A') S[1]++;
            else if(s[1]=='2') S[2]++;
            else if(s[1]=='3') S[3]++;
            else if(s[1]=='4') S[4]++;
            else if(s[1]=='5') S[5]++;
            else if(s[1]=='6') S[6]++;
            else if(s[1]=='7') S[7]++;
            else if(s[1]=='8') S[9]++;
            else if(s[1]=='9') S[8]++;
            else if(s[1]=='T') S[10]++;
            else if(s[1]=='J') S[11]++;
            else if(s[1]=='Q') S[12]++;
            else if(s[1]=='K') S[13]++;
        }else if(s[0]=='D'){
            if(s[1]=='A') D[1]++;
            else if(s[1]=='2') D[2]++;
            else if(s[1]=='3') D[3]++;
            else if(s[1]=='4') D[4]++;
            else if(s[1]=='5') D[5]++;
            else if(s[1]=='6') D[6]++;
            else if(s[1]=='7') D[7]++;
            else if(s[1]=='8') D[8]++;
            else if(s[1]=='9') D[9]++;
            else if(s[1]=='T') D[10]++;
            else if(s[1]=='J') D[11]++;
            else if(s[1]=='Q') D[12]++;
            else if(s[1]=='K') D[13]++;
        }else if(s[0]=='H'){
            if(s[1]=='A') H[1]++;
            else if(s[1]=='2') H[2]++;
            else if(s[1]=='3') H[3]++;
            else if(s[1]=='4') H[4]++;
            else if(s[1]=='5') H[5]++;
            else if(s[1]=='6') H[6]++;
            else if(s[1]=='7') H[7]++;
            else if(s[1]=='8') H[8]++;
            else if(s[1]=='9') H[9]++;
            else if(s[1]=='T') H[10]++;
            else if(s[1]=='J') H[11]++;
            else if(s[1]=='Q') H[12]++;
            else if(s[1]=='K') H[13]++;
        }else if(s[0]=='C'){
            if(s[1]=='A') C[1]++;
            else if(s[1]=='2') C[2]++;
            else if(s[1]=='3') C[3]++;
            else if(s[1]=='4') C[4]++;
            else if(s[1]=='5') C[5]++;
            else if(s[1]=='6') C[6]++;
            else if(s[1]=='7') C[7]++;
            else if(s[1]=='8') C[8]++;
            else if(s[1]=='9') C[9]++;
            else if(s[1]=='T') C[10]++;
            else if(s[1]=='J') C[11]++;
            else if(s[1]=='Q') C[12]++;
            else if(s[1]=='K') C[13]++;
        }
    }
    int ans=52;
    for(int j=1;j<=13;j++){
        if(S[j]>0) ans--;
        if(H[j]>0) ans--;
        if(D[j]>0) ans--;
        if(C[j]>0) ans--;
    }
    cout<<ans;
}
