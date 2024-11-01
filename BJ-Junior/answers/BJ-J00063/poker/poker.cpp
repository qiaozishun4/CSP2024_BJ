#include<iostream>
using namespace std;
int n,ans=52,k;
int d[15]={0},c[15]={0},h[15]={0},s[15]={0};
char x,y;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);

    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x>>y;
        if(y>='2'&&y<='9') k=y-'0';
        else if(y=='T') k=10;
        else if(y=='J') k=11;
        else if(y=='Q') k=12;
        else if(y=='K') k=13;
        else if(y=='A') k=1;
        if(x=='D'){
            if(d[k]==0) ans--;
            d[k]++;
        }
        if(x=='C'){
            if(c[k]==0) ans--;
            c[k]++;
        }
        if(x=='H'){
            if(h[k]==0) ans--;
            h[k]++;
        }
        if(x=='S'){
            if(s[k]==0) ans--;
            s[k]++;
        }
    }
    cout<<ans;
    return 0;
}
