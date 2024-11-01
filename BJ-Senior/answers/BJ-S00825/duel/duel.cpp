#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int a[N],h[N];
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        h[a[i]]++;
    }
    int sum=0;
    for(int i=1;i<=1e5;i++){
        if(sum>=h[i]) sum-=h[i];
        else sum=0;
        sum+=h[i];
    }
    cout<<sum;
    return 0;
}
