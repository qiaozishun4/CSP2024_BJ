#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int n,a[N];
map<int,int> m,c;
int main(){

    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        m[a[i]]++;
    }
    int ans=n,idx=m[a[1]],p=0;
    sort(a+1,a+n+1);
    for(int i=1;i<n;i++){
        if(a[i]!=p){
            p=a[i];
            idx=max(i+m[a[i]]-1,idx);
        }
        if(n-idx>0){
            ans--;
            idx++;
        }
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);

    return 0;
}
