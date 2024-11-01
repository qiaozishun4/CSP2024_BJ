#include<bits/stdc++.h>
#define int long long
using namespace std;
int q[100010],n,t,a[100010],c[100010],maxx=INT_MIN,sum;
void dfs(int r,bool p){
    if(r==n+1){
        sum=0;
        for(int i=1;i<=r-1;i++){
                //cout<<q[i]<<" ";
            for(int j=i-1;j>=1;j--){
                if(q[j]==q[i]){
                    if(a[i]==a[j]){
                        sum+=a[i];
                        break;
                    }
                    else{
                        break;
                    }
                }
            }
        }
        //cout<<endl;
        maxx=max(maxx,sum);
    }
    else{
        if(r==1){
            q[r]=0;
            dfs(r+1,p);
            dfs(r+1,!p);
        }
        else{
            q[r]=p;
            dfs(r+1,p);
            q[r]=!p;
            dfs(r+1,!p);
        }
    }
}
signed main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    ios::sync_with_stdio(0);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    while(t--){
        maxx=INT_MIN;
        memset(q,0,sizeof q);
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        dfs(1,0);
        cout<<maxx<<endl;
    }
    return 0;
}
