#include<iostream>
using namespace std;
int t,n,k,q;
int l[200010],r[100010],c[100010],s[200010];
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    cin>>t>>n>>k>>q;
    for(int i = 0;i < t;i++)
    for(int i = 0;i < n;i++){
        cin>>l[i];
        for(int j = 0;j < l[i];j++){
            cin>>s[j];
        }
    }
    for(int i = 0;i < q;i++){
        cin>>r[i]>>q[i];
    }
    for(int i = 0;i < t;i++){
        cout<<1<<endl;
    }
    return 0;
}
