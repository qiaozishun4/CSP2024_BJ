#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int a[N],b[N];
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int sum=0;
        int n;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            b[a[i]]++;
            if(b[a[i]]==2){
                sum+=a[i];
                b[a[i]]==0;
            }
        }
        bool f=0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(a[i]==a[j]){
                    f=1;
                }
            }
        }
        if(f==0) sum=0;
        cout<<sum<<endl;
    }
    return 0;
}
