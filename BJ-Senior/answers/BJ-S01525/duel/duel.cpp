#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int a[N];
bool b[N];
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n; cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    int ans=n;
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(i==j) continue;
            if(a[j]>a[i]&&b[j]==false){
                b[j]=true;
                ans--;
                break;
            }
        }
    }
    cout<<ans;
    return 0;
}
