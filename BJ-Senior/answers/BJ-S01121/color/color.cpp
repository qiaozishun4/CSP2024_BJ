#include<bits/stdc++.h>
using namespace std;
int a[200010];
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        int n,tot=0;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        sort(a+1,a+n+1);
        int prv=a[1];
        for(int i=2;i<=n;i++){
            if(a[i]==prv) tot+=a[i];
            prv=a[i];
        }
        cout<<tot<<endl;
    }
    return 0;
}
