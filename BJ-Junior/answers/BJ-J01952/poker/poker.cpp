#include<bits/stdc++.h>
using namespace std;
int K[100],C[100],H[100],S[100];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n,sum=0;
    char b,c;
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>b;
        cin>>c;
        if (b=='D'){
            if (c=='A') K[1]++;
            else if (c=='T') K[10]++;
            else if (c=='J') K[11]++;
            else if (c=='Q') K[12]++;
            else if (c=='K') K[13]++;
            else if (c=='2') K[2]++;
            else if (c=='3') K[3]++;
            else if (c=='4') K[4]++;
            else if (c=='5') K[5]++;
            else if (c=='6') K[6]++;
            else if (c=='7') K[7]++;
            else if (c=='8') K[8]++;
            else if (c=='9') K[9]++;
        }
        if (b=='C'){
            if (c=='A') C[1]++;
            else if (c=='T') C[10]++;
            else if (c=='J') C[11]++;
            else if (c=='Q') C[12]++;
            else if (c=='K') C[13]++;
            else if (c=='2') C[2]++;
            else if (c=='3') C[3]++;
            else if (c=='4') C[4]++;
            else if (c=='5') C[5]++;
            else if (c=='6') C[6]++;
            else if (c=='7') C[7]++;
            else if (c=='8') C[8]++;
            else if (c=='9') C[9]++;
        }
        if (b=='H'){
            if (c=='A') H[1]++;
            else if (c=='T') H[10]++;
            else if (c=='J') H[11]++;
            else if (c=='Q') H[12]++;
            else if (c=='K') H[13]++;
            else if (c=='2') H[2]++;
            else if (c=='3') H[3]++;
            else if (c=='4') H[4]++;
            else if (c=='5') H[5]++;
            else if (c=='6') H[6]++;
            else if (c=='7') H[7]++;
            else if (c=='8') H[8]++;
            else if (c=='9') H[9]++;
        }
        if (b=='S') {
            if (c=='A') S[1]++;
            else if (c=='T') S[10]++;
            else if (c=='J') S[11]++;
            else if (c=='Q') S[12]++;
            else if (c=='K') S[13]++;
            else if (c=='2') S[2]++;
            else if (c=='3') S[3]++;
            else if (c=='4') S[4]++;
            else if (c=='5') S[5]++;
            else if (c=='6') S[6]++;
            else if (c=='7') S[7]++;
            else if (c=='8') S[8]++;
            else if (c=='9') S[9]++;
        }
    }
    for(int i=1;i<=13;i++){
        if(K[i]) sum++;
        if(C[i]) sum++;
        if(S[i]) sum++;
        if(H[i]) sum++;
    }
    cout<<52-sum;
    fclose(stdin);
    fclose(stdout);
    return 0;
}