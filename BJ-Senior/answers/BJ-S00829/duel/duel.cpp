#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,cnt;
int a[N];
bool v[N];
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    cnt=n;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(a[i]<a[j]&&v[j]==0){

                v[j]=1;
                cnt--;
                break;
            }
        }
    }
    cout<<cnt;
    return 0;
}
