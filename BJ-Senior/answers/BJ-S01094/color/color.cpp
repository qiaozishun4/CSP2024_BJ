#include<bits/stdc++.h>
using namespace std;
int t,n;
int a[200002];
int c[200002];
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        for(int i=1;i<=n;i++){
            c[a[i]]++;
        }
        int sum=0;
        for(int i=1;i<=200002;i++){
            if(!c[i])sum+=i*(c[i]-1);
        }
        cout<<sum;
    }
    return 0;
}
