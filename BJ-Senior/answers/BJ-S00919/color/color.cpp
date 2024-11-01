#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);

    int T,n,a[200001],m,b;
    cin>>T;
    for(int i=1;i<=T;i++){
        cin>>n;
        for(int j=1;j<=n;j++) cin>>a[j];
    }
    for(int i=1;i<=T;i++) cout<<b<<endl;

    fclose(stdin);
    fclose(stdout);
    return 0;
}
