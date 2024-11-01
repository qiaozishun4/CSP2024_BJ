#include<bits/stdc++.h>
//#define int long long
using namespace std;

int t,n;
int a[100010];
bool c[100010];//0->red 1->blue

int solve(int now){
    if(now>n){
        int fr,fb;
        fr=fb=-1;
        int ans=0;
        for(int i=1;i<=n;i++){
            if(!c[i]){
                if(fr==-1){
                    fr=a[i];
                    continue;
                }
                if(a[i]==fr){
                    ans+=fr;
                }
                fr=a[i];
            }
            if(c[i]){
                if(fb==-1){
                    fb=a[i];
                    continue;
                }
                if(a[i]==fb){
                    ans+=fb;
                }
                fb=a[i];
            }
        }
        return ans;
    }
    int tmp1=solve(now+1);
    c[now]=1;
    int tmp2=solve(now+1);
    c[now]=0;
    return max(tmp1,tmp2);
}

signed main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        memset(c,0,sizeof(c));
        cout<<solve(1)<<'\n';
    }

    return 0;
}
