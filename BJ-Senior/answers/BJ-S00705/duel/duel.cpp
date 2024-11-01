#include<bits/stdc++.h>
#define ll long long
#define N 500050
using namespace std;
ll n,a[N],b[N],c[N],ans;
bool cmp(ll x,ll y){
    return x<y;
    }
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1,cmp);
    /*for(int i=1;i<=n;i++)
    {
        cout<<a[i]<<"  ";
    }*/
    ll cnt = 1,sign = 1;
    c[1] = 0;
    for(int i=1;i<=n;i++){
        if(a[i]==a[i+1]){
            sign++;
        }else{
            b[cnt]=sign;
            cnt++;
            c[cnt]=c[cnt-1]+sign;
            sign=1;
        }
    }
    ll j=0;
    for(int i=2;i<cnt;i++){
            c[i]-=j;
        if(b[i]<=c[i]){
            j+=b[i];
            b[i]=0;
        }else{
            j+=c[i];
            b[i]-=c[i];
        }
    }
    cout<<n-j;
    return 0;
}
