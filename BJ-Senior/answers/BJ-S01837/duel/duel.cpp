#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,r[N],ans;
bool live[N],a[N];
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    ans=n;
    for(int i=1;i<=n;i++){
        cin>>r[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(r[i]==r[j]||live[i]==true||live[j]==true){
                continue;
            }
            if(r[i]<r[j]&&a[j]==false){
                ans--;
                live[i]=true;
                a[j]=true;
            }
            if(r[i]>r[j]&&a[i]==false){
                ans--;
                live[j]=true;
                a[i]=true;
            }
        }
    }
    cout<<ans;
    return 0;
}
