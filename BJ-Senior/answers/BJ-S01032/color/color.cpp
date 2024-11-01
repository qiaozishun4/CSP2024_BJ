#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int n;
    cin>>n;
    int a[200005]={};
    int big=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]>big){
            big=a[i];
        }
    }
    int c[10000005];
    int ans=0;
    for(int i=1;i<=n;i++){
        c[a[i]]++;
    }
    for(int i=1;i<=n;i++){
        cout<<c[i]<<endl;
    }
    return 0;
}

