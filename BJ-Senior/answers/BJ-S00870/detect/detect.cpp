#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int t;
int n,m,L,V;
int d[N], pre[N],p[N];
double v[N],a[N];
struct Node{int beg,edi;}s[N];
int cnt = 0;
int ans;
bool cmp(Node x,Node y){
    return x.edi > y.edi;
}
int main(){
    freopen("detect1.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin >> t;
    while(t--){
        memset(pre,0,sizeof(pre));
        cnt = ans = 0;
        cin >> n >> m >> L >> V;
        for(int i = 1;i <= n;i++){
            cin >> d[i] >> v[i] >> a[i];
        }
        for(int i = 1;i <= n;i++){
            cin >> p[i];
        }
        for(int i = 1;i <= n;i++){
            bool flag = (a[i] >= 0 ? 1 : 0);
            if(a[i] == 0 && v[i] <= V){continue;}
            if(a[i] == 0 && v[i] > V){
                if(p[m] >= d[i]){ans++;}
                pre[d[i]]++;
                pre[L + 1]--;
                s[++cnt].beg = d[i];
                s[cnt].edi = L;
                continue;}
            double k = (((double)(V) * (double)(V)) - (v[i] * v[i])) / (2 * a[i]);
            int cel = d[i] + ceil(k);
            int flr = d[i] + floor(k);
            if(flag){
                if(cel > L){continue;}
                int l = 1,r = m;
                while(l <= r){
                    int mid = (l + r) / 2;
                    if(p[mid] > L){
                        r = mid - 1;
                    }else if(p[mid] <= k + d[i]){
                        l = mid + 1;
                    }else{
                        break;
                    }
                }
                if(p[(l + r) / 2] <= L && p[(l + r) / 2] > k + d[i]){
                    pre[cel]++;
                    pre[L + 1]--;
                    ans++;
                    s[++cnt].beg = cel;
                    s[cnt].edi = L;
                }
            }else{
                if(d[i] > L){continue;}
                int l = 1,r = m;
                while(l <= r){
                    int mid = (l + r) / 2;
                    if(p[mid] >= k + d[i]){
                        r = mid - 1;
                    }else if(p[mid] < d[i]){
                        l = mid + 1;
                    }else{
                        break;
                    }
                }
                if(p[(l + r) / 2] < k + d[i] && p[(l + r) / 2] >= d[i]){
                    ans++;
                    pre[d[i]]++;
                    pre[flr]--;
                    s[++cnt].beg = d[i];
                    s[cnt].edi = (k > floor(k) ? flr : flr - 1);
                }
            }
        }
        long long sum = 0;
        for(int i = 1;i < cnt;i++){
            if(s[i].beg <= s[i - 1].beg && s[i].beg >= s[i - 1].edi){
                continue;
            }else{
                sum++;
            }
        }
        cout << ans << " " << m - sum <<endl;
    }
    return 0;//rp++
}//rp++
