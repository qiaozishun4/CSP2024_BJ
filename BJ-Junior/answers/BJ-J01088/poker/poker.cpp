#include<bits/stdc++.h>
using namespace std;
int n,t[100];
int toten(char x){
    if(x=='D') return 0;
    if(x=='C') return 1;
    if(x=='H') return 2;
    if(x=='S') return 3;
}
int to13(char x){
    if(x>='1' && x<='9') return x-'0';
    if(x=='A') return 1;
    if(x=='T') return 10;
    if(x=='J') return 11;
    if(x=='Q') return 12;
    if(x=='K') return 13;
}
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        char a,b;
        cin>>a>>b;
        int tmp=toten(a)*13+to13(b);
        t[tmp]++;
    }
    int sum=0;
    for(int i=1;i<=52;i++){
        if(t[i]==0) sum++;
    }
    cout<<sum<<endl;
    return 0;
}