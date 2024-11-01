#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int n,a[N],rst;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)   cin>>a[i];
    sort(a+1,a+1+n);
    for(int i=1,j;i<=n;i=j+1){
        j=i;
        while(j<n&&a[j+1]==a[i])    j++;
        rst=max(0,rst-(j-i+1));
        rst+=(j-i+1);
    }
    cout<<rst;
    return 0;
}