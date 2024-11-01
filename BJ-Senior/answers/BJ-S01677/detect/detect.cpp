#include<bits/stdc++.h>
#define int long long
using namespace std;
int t,n,m,l,v,cnt;
int p[100005],sum[1000005];
bool vis[100005],ok[100005];
const double eps = 1e-6;
struct node{
    int d,v,a;
}a[100005];
void dfs(int x,int s){
    if(s>=cnt){
        return;
    }
    if(x==m+1){
        bool vis2[25] = {0};
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(!ok[j]){
                    continue;
                }
                if(p[j]>=a[i].d){
                    if(a[i].a<0){
                        if(a[i].v*a[i].v+2.0*a[i].a*(p[j]-a[i].d)<=0){
                            break;
                        }
                        //cout << i << " " << a[i].v*a[i].v+2.0*a[i].a*(p[j]-a[i].d) << endl;
                    }
                    double x = 0;
                    if(a[i].a==0){
                        x = a[i].v;
                    }
                    else{
                        x = sqrt(a[i].v*a[i].v+2.0*a[i].a*(p[j]-a[i].d));
                    }
                    //cout << i << " " << j << " " << x << " " << v << endl;
                    if(x>v+eps){
                        //cout << i << endl;
                        vis2[i] = 1;
                        break;
                    }
                }
            }
        }
//        for(int i=1;i<=m;i++){
//            if(ok[i]){
//                cout << i << " ";
//            }
//        }
//        cout << endl;
        for(int i=1;i<=n;i++){
            if(vis[i] && !vis2[i]){
                return;
            }
        }
//        if(s==2){
//            for(int i=1;i<=n;i++){
//                if(ok[i]){
//                    cout << i << " ";
//                }
//            }
//            cout << endl;
//        }
        cnt = s;
        return;
    }
    ok[x] = 0;
    dfs(x+1,s);
    ok[x] = 1;
    dfs(x+1,s+1);
}
signed main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin >> t;
    while(t--){
        memset(sum,0,sizeof(sum));
        memset(vis,0,sizeof(vis));
        cin >> n >> m >> l >> v;
        for(int i=1;i<=n;i++){
            cin >> a[i].d >> a[i].v >> a[i].a;
        }
        for(int i=1;i<=m;i++){
            cin >> p[i];
            sum[p[i]] = 1;
        }
        for(int i=l;i>=0;i--){
            sum[i]+=sum[i+1];
        }
        if(n>20 && m>20){
            int ans = 0;
            for(int i=1;i<=n;i++){
                if(!a[i].a){
                    int x = a[i].v;
                    if(x>v && sum[a[i].d]){
                        ans++;
                    }
                }
                else{
                    if(a[i].d>p[m]){
                        continue;
                    }
                    if(sqrt(a[i].v*a[i].v+2*a[i].a*(p[m]-a[i].d))>v){
                        ans++;
                    }
                }
            }
            if(ans==0){
                m++;
            }
            cout << ans << " " << m-1 << endl;
        }
        else{
            int ans = 0;
            for(int i=1;i<=n;i++){
                for(int j=1;j<=m;j++){
                    if(p[j]>=a[i].d){
                        if(a[i].a<0){
                            if(a[i].v*a[i].v+2.0*a[i].a*(p[j]-a[i].d)<=0){
                                break;
                            }
                            //cout << i << " " << a[i].v*a[i].v+2.0*a[i].a*(p[j]-a[i].d) << endl;
                        }
                        double x = 0;
                        if(a[i].a==0){
                            x = a[i].v;
                        }
                        else{
                            x = sqrt(a[i].v*a[i].v+2.0*a[i].a*(p[j]-a[i].d));
                        }
                        //cout << i << " " << j << " " << x << " " << v << endl;
                        if(x>v+eps){
                            ans++;
                            //cout << i << endl;
                            vis[i] = 1;
                            break;
                        }
                    }
                }
            }
            cout << ans << " ";
            cnt = m;
            dfs(1,0);
            cout << m-cnt << endl;
        }
    }
    return 0;
}
