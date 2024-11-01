#include<bits/stdc++.h>
using namespace std;
int t[100050],a[100050];
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n,maxn=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        t[a[i]]++;
        maxn=max(maxn,a[i]);
    }
    int sum=t[1];
    for(int i=2;i<=maxn;i++){
        if(sum<t[i]){
            sum=t[i];
        }
    }
    cout<<sum;
    return 0;
}