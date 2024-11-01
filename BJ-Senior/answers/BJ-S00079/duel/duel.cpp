#include <bits/stdc++.h>
using namespace std;
int a[100010];
int buc[100010];
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n;
    cin>>n;
    for(int i = 1; i <= n; i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    int cnt = 0;
    a[0] = -1;
    for(int i = 1;i <= n; i++){
        if(a[i] != a[i-1]){
            buc[++cnt] = 1;
        }else{
            buc[cnt]++;
        }
    }
    sort(buc+1,buc+1+cnt);
    buc[0] = 0;
    int res=0;
    for(int i = 1; i < cnt; i++){
        res+=(buc[i]-buc[i-1])*(cnt-i);
    }
    cout<<n-res;
}
