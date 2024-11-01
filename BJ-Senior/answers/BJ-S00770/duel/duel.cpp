#include<bits/stdc++.h>
using namespace std;
int a[200005];
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n;
    int cnt=1,sum=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=2;i<=n;i++){
        if(a[i]>a[cnt]){
            sum++;
            cnt++;
        }
    }
    cout<<n-sum<<endl;
    return 0;
}
