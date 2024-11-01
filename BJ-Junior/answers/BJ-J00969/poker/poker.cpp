#include<bits/stdc++.h>
using namespace std;
int d[23],h[23],c[23],s[23];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n,ans=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        int num;
        char kd,sj;
        cin>>kd>>sj;
        if(sj=='A')num=1;
        else if(sj=='T')num=10;
        else if(sj=='J')num=11;
        else if(sj=='Q')num=12;
        else if(sj=='K')num=13;
        else num=sj-'0';
        if(kd=='D')d[num]++;
        else if(kd=='S')s[num]++;
        else if(kd=='C')c[num]++;
        else if(kd=='H')h[num]++;
    }
    for(int i=1;i<=13;i++){
        if(d[i]==0)ans++;
        if(c[i]==0)ans++;
        if(s[i]==0)ans++;
        if(h[i]==0)ans++;
    }
    cout<<ans;
    return 0;
}