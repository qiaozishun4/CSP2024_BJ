#include<bits/stdc++.h>
using namespace std;
int a[100005];
bool b[100005];
int pd(int n){
    int sl=0,sh=0,ans=0;
    for(int i=1;i<=n;i++){
        //cout<<b[i];
        if(b[i]==0){
            if(sh==0 || a[sh]!=a[i]){
                sh=i;
            }else if(a[sh]==a[i]){
                ans+=a[i];
                sh=i;
            }
        }else{
            if(sl==0 || a[sl]!=a[i]){
                sl=i;
            }else if(a[sl]==a[i]){
                ans+=a[i];
                sl=i;
            }
        }
    }
    //cout<<endl;
    return ans;
}
int bfs(int c,int n){
    if(c==n+1){
        //cout<<c<<" "<<n<<endl;
        //cout<<"sbnhynn"<<endl;
        //cout<<pd(n)<<endl;
        return pd(n);
    }else{
        b[c]=0;
        //cout<<"3"<<endl;
        int x=bfs(c+1,n);
        b[c]=1;
        //cout<<"6"<<endl;
        int y=bfs(c+1,n);
        //cout<<x<<" "<<y<<endl;
        return max(x,y);
    }
}
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        memset(b,0,sizeof(b));
        int n;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        cout<<bfs(1,n)<<endl;
    }
    return 0;
}
