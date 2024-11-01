#include<bits/stdc++.h>
using namespace std;
int a;
int A[52],B[52],C[52],D[52];
int ct;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>a;
    for(int i=0;i<a;i++){
        char x,y;
        cin>>x>>y;
        int q;
        if(y=='A') q=1;
        else if(y=='J') q=11;
        else if(y=='Q') q=12;
        else if(y=='K') q=13;
        else if(y=='T') q=10;
        else q=y-'0';
        if(x=='D') A[q]++;
        if(x=='C') B[q]++;
        if(x=='H') C[q]++;
        if(x=='S') D[q]++;
    }
    for(int i=1;i<=13;i++){
        if(A[i]==0) ct++;
        if(B[i]==0) ct++;
        if(C[i]==0) ct++;
        if(D[i]==0) ct++;
    }
    cout<<ct;
    fclose(stdin);
    fclose(stdout);
}
