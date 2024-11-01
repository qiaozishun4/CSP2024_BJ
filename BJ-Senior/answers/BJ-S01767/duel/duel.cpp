#include <bits/stdc++.h>
using namespace std;
long long a[100005];
long long s[100005];
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    long long n;
    long long t;
    cin>>n;
    long long maxh = 0;
    for(long long i=0;i<n;i++){
        cin>>t;
        a[t]++;
        if(maxh<t){
            maxh = t;
        }
    }
    s[1] = a[1];
    for(long long i=2;i<maxh+1;i++){
        if(a[i]>=s[i-1]){
            s[i] = a[i];
        }
        else {
            s[i] = s[i-1];
        }
    }
    cout<<s[maxh];
    return 0;
}