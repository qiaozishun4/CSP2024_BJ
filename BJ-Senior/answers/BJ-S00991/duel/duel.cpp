#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int n;
int a[N];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    int i=1;
    int ans=n;
    for(int j=2;j<=n;j++){
        if(a[j]>a[i]){
            i++;
            ans--;
        }
    }
    cout<<ans<<endl;
    cout.flush();
    return 0;
}