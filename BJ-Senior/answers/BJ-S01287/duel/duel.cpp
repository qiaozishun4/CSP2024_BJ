#include<bits/stdc++.h>
using namespace std;
long long n,a[1000005],v[1000005],cnt,j;
bool b[1000005];
int main(){
    ios::sync_with_stdio(0);
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    j=1;
    for(long long i=2;i<=n;i++){
        if(a[i]>a[j]){
            cnt++;
            j++;
        }

    }
    cout<<n-cnt;
}