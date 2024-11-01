#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+1;
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int n,a[N];
        ll b[N];
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            b[a[i]]++;
        }
        int s=0;
        for(int i=1;i<=n;i++){
            if(b[a[i]]%2!=0){
                b[a[i]]--;
            }
            s+=(b[a[i]]/2)*a[i];
            b[a[i]]=0;
        }
        cout<<s<<endl;
    }
    return 0;
}
