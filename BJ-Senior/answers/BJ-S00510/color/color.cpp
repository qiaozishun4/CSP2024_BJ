#include<iostream>
typedef long long ll;
using namespace std;
int n,a[200005],ans;
bool rb[200005];
void dfs(int x){
    if(x==0){
        int r=-1,b=-1,sum=0;
        for(int i=1;i<=n;i++){
            if(rb[i]==false){
                if(r!=-1&&a[r]==a[i]){
                    sum+=a[i];
                }
                r=i;
            }
            else{
                if(b!=-1&&a[b]==a[i]){
                    sum+=a[i];
                }
                b=i;
            }
        }
        ans=max(ans,sum);
        return;
    }
    rb[n-x+1]=true;
    dfs(x-1);
    rb[n-x+1]=false;
    dfs(x-1);
    return;
}
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        dfs(n);
        cout<<ans<<endl;
        ans=0;
    }
    return 0;
}
