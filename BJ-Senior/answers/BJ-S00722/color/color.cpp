#include<bits/stdc++.h>
using namespace std;
pair<int,int> a[200009];
bool b[200009];
int t,n,ans,num=1;bool f1;
int main(){
  freopen("color.in","r",stdin);
  freopen("color.out","w",stdout);
  cin >> t;
  while(t--){
    cin >> n;
    for(int i=1;i<=n;i++){
      cin >> a[i].first;
    }
    num=1;
    for(int i=n;i>=1;i--){
        if(b[i]) continue;
        a[i].second==num%2;
      for(int j=i-1;j>=1;j--){
        if(a[j].first==a[i].first){
            a[j].second=num%2;
            f1=true;
            b[j]=1;
            b[i]=1;
        }
      }
      num++;
    }
    for(int i=1;i<=n;i++){
        cout << a[i].second << ' ';
      for(int j=i-1;j>=1;j--){
        if(a[j].first==a[i].first && a[j].second==a[i].second) ans+=a[i].first;
      }
    }
    cout << ans << endl;
  }
  return 0;
}
