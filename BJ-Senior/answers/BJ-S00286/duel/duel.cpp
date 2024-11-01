#include <bits/stdc++.h>
using namespace std;

int n;
int a[100005];
bool b[100005];

int ans;

int main(){

    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);

    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=n;i>0;--i){
        for(int j=i-1;j>0;--j){
            if(a[i]>a[j]&&b[j]==0){
                b[j]=1;
                ans++;
                j=0;
            }
        }
    }
    cout<<n-ans;
    return 0;
}
