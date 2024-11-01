#include <bits/stdc++.h>
using namespace std;
int a[100005];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int cnt=0;
    sort(a+1,a+n+1);
 //   for(int i=1;i<=n;i++){
 //       cout<<a[i]<<" ";
 //   }
 //   cout<<endl;
    for(int i=1,j=1;i<=n,j<=n;){
        if(i==j){
 //           cout<<i<<" "<<" "<<j<<endl;
            j++;
        }
        else if(a[i]==a[j]){
//            cout<<i<<" "<<a[i]<<" "<<j<<" "<<a[j]<<endl;
            j++;
        }
        else{
 //           cout<<i<<" "<<" "<<j<<endl;
            i++;
            j++;
            cnt++;
        }
    }
    cout<<n-cnt;
    return 0;
}
