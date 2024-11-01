#include <bits/stdc++.h>
using namespace std;
const int N=100005;
int n;
int a[N];
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    int i=1,j=2;
    while(j<=n){
        if(a[j]>a[i]){
            i++;
        }
        j++;
    }
    cout<<j-i;
    return 0;
}
