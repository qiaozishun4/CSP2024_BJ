#include <bits/stdc++.h>
using namespace std;
int D[15],C[15],H[15],S[15];
int main(){
    long long n,cnt,sum=0;
    char s1,s2;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s1>>s2;
        if(s2=='A') cnt=0;
        else if(s2=='T') cnt=9;
        else if(s2=='J') cnt=10;
        else if(s2=='Q') cnt=11;
        else if(s2=='K') cnt=12;
        else cnt=s2-'0'-1;
        if(s1=='D') D[cnt]=1;
        if(s1=='C') C[cnt]=1;
        if(s1=='H') H[cnt]=1;
        if(s1=='S') S[cnt]=1;
    }
    for(int i=0;i<13;i++){
        if(D[i]!=1) sum+=1;
    }
    for(int i=0;i<13;i++){
        if(C[i]!=1) sum+=1;
    }
    for(int i=0;i<13;i++){
        if(H[i]!=1) sum+=1;
    }
    for(int i=0;i<13;i++){
        if(S[i]!=1) sum+=1;
    }
    cout<<sum;
    return 0;
}
