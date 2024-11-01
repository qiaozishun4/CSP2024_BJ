#include<bits/stdc++.h>
using namespace std;
#define maxn 1005
#define inf 0x3f3f3f3f
int pos[maxn][maxn];
int t,n,m,l,v,ve[maxn],a[maxn],p[maxn],bk[maxn],ov[maxn],vis[maxn],d[maxn],len = 0;
//设dfs(i,j)表示已经考虑到选或不选第i号，还能选j个
bool dfs(int ps,int left,int vis[]){
    int vst[len];
    bool flag = true;
    //cout << len << endl;
    for(int i = 1;i <= len;i++){
        //cout << 1 << endl;
        vst[i] = vis[i];
        if(!vis[i]){
            flag = false;
            break;
        }
    }
    //cout << 1 << endl;
    if(flag && left == 0){
        return true;
    }
    if(ps > m){
        return false;
    }
    if(left < 0) return false;
    bool res = false;
    for(int i = ps + 1;i <= m - left + 1;i++){
        //cout << 666 << endl;
        res |= dfs(i,left - 1,vst);
    }
    for(int i = 1;i <= len;i++){
        if(pos[ps][ov[i]]){
            vst[i] = 1;
        }
    }
    for(int i = ps + 1;i <= m - left + 2;i++){
            //cout << i << endl;
        res |= dfs(i,left - 1,vst);
    }
    //cout << 999 << endl;
    return res;
}
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin >> t;
    while(t--){
        cin >> n >> m >> l >> v;
        for(int i = 1;i <= n;i++){
            cin >> d[i] >> ve[i] >> a[i];
        }
        for(int i = 1;i <= m;i++){
            cin >> p[i];
            for(int j = 1;j <= n;j++){
                if(p[i] >= d[j]){
                    int k = d[j] - p[i];
                    double res = sqrt((double)(ve[j] * ve[j] - 2 * a[j] * k));
                    if(res > v){
                        pos[i][j]++;
                        bk[j]++;
                    }
                }
            }
        }
        int ans = 0;
        for(int i = 1;i <= n;i++){
            if(bk[i]){
                ans++;
                ov[++len] = i;
            }
        }
        cout << ans << endl;
        //cout << len << endl;
        int vis[len];
        for(int i = m;i >= 1;i--){
            memset(vis,0,sizeof(vis));
            bool ck = dfs(1,i,vis);
            //cout << ck << endl;
            if(!ck){
                continue;
            }
            ans = i;
        }
        cout << ans << endl;
    }
    return 0;
}
