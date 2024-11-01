#include <bits/stdc++.h>
using namespace std;
int n;
const int N=1e5+5;
int a[N];
int t[N],f[N];

int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        t[a[i]]++;
    }
    for(int i=1;i<=1e5;i++){
        f[i]=f[i-1]+t[i];
    }
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(f[a[i]-1]-cnt>0){
            cnt++;
        }
    }
    cout<<n-cnt;
    return 0;
}