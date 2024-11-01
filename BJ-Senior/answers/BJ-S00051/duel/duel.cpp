#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n,id;
    freopen("duel.in","r",stdin);

    cin>>n;
    vector<long long>a(10010,0);
    for(long long i=0;i<n;i++){
        cin>>id;
        a[id]++;

    }
    long long k=a[1]-a[0];
    for(long long i=2;i<10010;i++){
        k=max(k,a[i]);

    }
    freopen("duel.out","w",stdout);
    cout<<abs(k);
    return 0;
}
