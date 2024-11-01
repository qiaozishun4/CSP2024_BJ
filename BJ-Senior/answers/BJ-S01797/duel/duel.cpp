#include<bits/stdc++.h>
#define Maxn 100004
using namespace std;
int n,num[Maxn];
bool attacted[Maxn];

int init(int n){
    if(n==1) return 0;
    else if(n==2){
        if(num[0]==num[1]) return 0;
        else return 1;
    }
    int ans=n,mxnum,sfrom,sto,bfrom=0,bto,now,last=0;
    sort(num,num+n);
    sfrom=0;
    now=num[0];
    mxnum=num[n-1];
    sto=sfrom;
    while(num[sto+1]==now) sto++;
    while(true){
        bfrom=sto+1;
        bto=bfrom;
        while(num[bto+1]==num[bfrom]) bto++;
        if(sto-sfrom+1+last>bto-bfrom+1){
            ans-=bto-bfrom+1;
            last+=sto-sfrom-bto+bfrom;
        }
        else ans-=sto-sfrom+1+last;
        now=num[bfrom];
        if(now==mxnum) break;
        sfrom=bfrom;
        sto=bto;
    }
    return ans;
}

int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++) cin>>num[i];
    cout<<init(n)<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
