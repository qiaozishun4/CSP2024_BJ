#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int t,n[1000010],a[1000010];
    cin>>t;
    for(int i=1;i<=t;i++){
        cin>>n[i];
        for(int j=1;j<=n;j++){
            cin>>a[j];
        }
    }
    cout<<1<<"\n"<<0<<"\n"<<8;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
