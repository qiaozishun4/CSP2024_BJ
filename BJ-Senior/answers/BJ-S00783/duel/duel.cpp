#include<iostream>
#include<algorithm>
using namespace std;

const int MAXN = 1e5 + 10;
int a[MAXN],n,box[MAXN],maxn = -1e9,len;
struct List{
    int pre,nex,val;
}lis[MAXN];

void erase(int i){
    lis[lis[i].pre].nex = lis[i].nex;
    lis[lis[i].nex].pre = lis[i].pre;
}

int main(){
    ios::sync_with_stdio(false);
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin >> n;
    bool flag = 1;
    for(int i = 1;i <= n;++i){
        cin >> a[i];
        flag = flag && (a[i] <= 2);
        box[a[i]]++;
        maxn = max(maxn,a[i]);
    }
    if(flag){
        int cnt1 = 0,cnt2 = 0;
        for(int i = 1;i <= n;++i){
            cnt1 += (a[i] == 1);
            cnt2 += (a[i] == 2);
        }
        cout << max(cnt2,cnt1) << endl;
        return 0;
    }
    sort(a + 1,a + n + 1);
    int last = 0;
    lis[last].pre = 0;
    for(int i = 1;i <= n;++i){
        if(a[i] != last) lis[a[i]] = {last,0,1},lis[last].nex = a[i],last = a[i];
        else lis[last].val++;
    }
    lis[last].nex = n + 1;
    for(int i = 0;i != n + 1;i = lis[i].nex){
        int k = lis[i].pre;
        int t = lis[i].val;
        while(t != 0 && k != 0){
            int p = t;
            t -= min(lis[k].val,t);
            lis[k].val -= min(lis[k].val,p);
            if(lis[k].val == 0) erase(k);
            k = lis[i].pre;
        }
    }
    int ans = 0;
    for(int i = 0;i != n + 1;i = lis[i].nex) ans += lis[i].val;
    cout << ans << endl;
    return 0;
}
