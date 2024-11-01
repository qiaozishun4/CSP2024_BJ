#include<bits/stdc++.h>
using namespace std;
int n,a[100005],ans;
multiset<int>s;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        if(!s.empty()){
            multiset<int>::iterator it=s.lower_bound(a[i]);
            if(it!=s.begin()){
                it--;
                s.erase(it),ans++;
            }
        }
        s.insert(a[i]);
    }
    cout<<n-ans;
    return 0;
}
