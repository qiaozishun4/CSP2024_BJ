#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    long long n,sum;
    cin>>n;
    sum=n;
    vector<long long> v(n+1,0);
    vector<bool> b(n+1,true);
    for(int i=1;i<=n;i++){
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    for(int i=1;i<=n;i++){
        for(int j=i;j>0;j--){
            if(v[i]>v[j]&&b[j]){
                //cout<<v[i]<<" "<<v[j];
                sum--;
                b[j]=false;
                break;
            }
        }
    }
    cout<<sum;
    return 0;
}
