#include<bits/stdc++.h>
using namespace std;
int n,m,L,V,a[1000005],t;
struct node{
    int d,v,c,l,r;
    bool b;
}edge[1000005];
int h[1000005];
struct csps{
    int ll,rr;
}b[1000005];
struct nodee{
    int val,id;
} vis[1000005];
bool cmp(nodee a ,nodee b){
    return a.val > b.val;
}
int id[1000005];
bool viss[1000005];
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin >> t;
    while(t--){
        memset(edge,0,sizeof(edge));
        memset(h,0,sizeof(h));
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        memset(vis,0,sizeof(vis));memset(id,0,sizeof(id));memset(viss,0,sizeof(viss));
        int ans = 0;
        cin >> n >> m >> L >> V;
        for(int i = 1;i <= n;i++)cin >> edge[i].d >> edge[i].v >> edge[i].c;
        for(int i = 1;i <= m;i++)cin >> a[i];
        int kkk = 1;
        for(int i = 1;i <= L;i++){
            h[i] = kkk;
            if(i == a[kkk]){
                kkk++;
            }
        }
        for(int i = 1;i <= n;i++){
            if(edge[i].c > 0){
                int lon = edge[i].d + (V - edge[i].v) * (V + edge[i].v) / 2 / edge[i].c;
                if(lon > a[m])edge[i].b = 0;
                else{
                    //cout << "bigggggg\n";
                    ans++;
                    edge[i].r = m;
                    edge[i].l = h[lon];
                    edge[i].b = 1;
                }
            }
            else if(edge[i].c == 0){
                if(edge[i].v > V and edge[i].d <= a[m]){
                    //cout << "middleeeeeee\n";
                    ans++;
                    edge[i].l = h[edge[i].d];
                    edge[i].r = m;
                    edge[i].b = 1;
                }
            }
            else{
                if(edge[i].v > V){
                    //cout << edge[i].d + (int)((V * V - edge[i].v * edge[i].v) / 2 / edge[i].c) << " " << i << " " << a[h[edge[i].d]] << endl;
                    if(a[h[edge[i].d]] < edge[i].d + floor((long double)(V * V - edge[i].v * edge[i].v) / 2 / edge[i].c)){
                        //cout << "smalllllllll\n";
                        ans++;
                        edge[i].l = h[edge[i].d];
                        int ijk = edge[i].d + floor((long double)(V * V - edge[i].v * edge[i].v) / 2 / edge[i].c);
                        if(ijk <= a[m])edge[i].r = h[ijk] - 1;
                        else edge[i].r = m;
                        edge[i].b = 1;
                    }
                }
            }
        }
        cout << ans << " ";
        int cnt = 0;
        for(int i = 1;i <= n;i++){
            if(edge[i].b == 1){b[++cnt].ll = edge[i].l,b[cnt].rr = edge[i].r;for(int j = b[cnt].ll;j <= b[cnt].rr;j++)vis[j].val++;}//cout << b[cnt].ll << " " << b[cnt].rr << endl; }
        }
        for(int i = 1;i <= m;i++){
            vis[i].id = i;
        }
        //sort(b+1,b+ans+1,cmp);
        int ccnt = 0;
        for(int i = 1;i <= ans;i++){
            sort(vis+1,vis+m+1,cmp);
            for(int j = 1;j <= m;j++){id[vis[j].id] = j;}//cout << vis[j].val << " ";}
            if(vis[1].val > 0){
                ccnt++;
                //cout << vis[1].val << " " << vis[1].id << endl;
                for(int j = 1;j <= n;j++){
                    //cout << b[j].ll << "   " << b[j].rr << endl;
                    if(b[j].ll <= vis[1].id and b[j].rr >= vis[1].id and viss[j] == 0) {
                        viss[j] = 1;
                        for(int k = b[j].ll;k <= b[j].rr;k++)vis[id[k]].val--;//cout << k << " " << vis[id[k]].val << " " << j << endl;
                    }
                }
            }
            else break;//cout << endl;
        }
        cout << m - ccnt << endl;
    }
    
    return 0;
}