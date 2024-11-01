#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        long long m[n],maxn=0,sum=0;
        for(int i=0;i<n;i++){
            cin>>m[i];
            maxn=max(maxn,m[i]);
        }
        int k[maxn+1];
        for(int i=0;i<=maxn;i++){
            k[i]=0;
        }
        for(int i=0;i<n;i++){
            k[m[i]]++;
        }
        for(int i=0;i<=maxn;i++){
            k[i]/=2;
            sum+=i*k[i];
        }
        cout<<sum<<endl;
    }
    return 0;
}
