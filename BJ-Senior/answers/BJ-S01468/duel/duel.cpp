#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[200010],cnt,p1,p2;
bool p[200010],d[200010];
signed main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    ios::sync_with_stdio(0);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==2){
            p2++;
        }
        if(a[i]==1){
            p1++;
        }
    }
    if(p1+p2==n){
        if(p2>=p1){
            cout<<p2<<endl;
        }
        else{
            cout<<n-p2<<endl;
        }
        return 0;
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(a[j]>a[i]&&!d[j]&&!p[j]&&!d[i]){
                p[j]=1;
                d[i]=1;
                cnt++;
                break;
            }
        }
    }
    cout<<n-cnt;
    return 0;
}
