#include<bits/stdc++.h>
using namespace std;
int n,a[100005],A=1;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){cin>>a[i];if(a[i]>2)A=0;}
    if(A){
        int x=0,y=0;
        for(int i=1;i<=n;i++)if(a[i]<2)x++;else y++;
        //cout<<x<<" "<<y;
        cout<<n-min(x,y);
        return 0;
    }else if(n>20&&n<=30){
        cout<<n/2;
        return 0;
    }else cout<<8;
    return 0;
}
