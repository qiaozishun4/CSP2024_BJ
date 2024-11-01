#include<bits/stdc++.h>
using namespace std;
long long n,a,b[100005],c[100005];
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n;
    for(long long i=1;i<=n;i++)cin>>a,b[a]++,c[a]++;
    long long x=1,y=2,ans=0;
    while(x<=100000){
        bool pd=0;
        while(b[x]){
            while(y<=100000&&(y<=x||!c[y]))y++;
            if(y>100000){
                pd=1;
                break;
            }
            c[y]--;
            b[x]--,ans++;
        }
        if(pd)break;
        x++;
    }
    cout<<n-ans;
    return 0;
}
