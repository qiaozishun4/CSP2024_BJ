#include<bits/stdc++.h>
using namespace std;
int t;
int n,k,q;
int a[1005][2005];
int l[100005],s[100005];
bool f[200005];
void sc(){
    cout<<t<<endl<<n<<k<<q<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<=a[i][0];j++)cout<<a[i][j];
        cout<<endl;
    }
    for(int i=0;i<q;i++)cout<<l[i]<<s[i]<<endl;
}
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n>>k>>q;
        for(int i=0;i<n;i++){
            cin>>a[i][0];
            for(int j=1;j<=a[i][0];j++){
                cin>>a[i][j];
                f[a[i][j]]=true;
            }
        }
        for(int i=0;i<q;i++)cin>>l[i]>>s[i];
        //sc();
        for(int i=0;i<q;i++){
            if(!f[s[i]])cout<<0<<endl;
            else cout<<1<<endl;
        }
    }
    return 0;
}
//wei wan cheng
