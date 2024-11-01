#include<bits/stdc++.h>
#define ll long long
const int N = 1e5+10;

using namespace std;

int T;
int n, m, L, V;
int lx, ly;//length
int ans1, ans2;
struct ps{//the ai > 0
    int d, v, a;
}x[N];
struct ms{//the ai <= 0
    int d, v, a;
}y[N];
int p[N];
int sum[1000010];//sum[i] -> in the interval [i, 0) , the cnt of p
bool q[1000010];
bool is[N];

int work(){
    int ans = 0;
    int k = m;
    for(int i=1;i<=lx;i++){
        ll s = p[k] - x[i].d;
        ll delta = x[i].v *1ll * x[i].v + 2ll * x[i].a * s;
        double vp = sqrt(delta);
        if(vp > V)ans++;
    }
    for(int i=1;i<=ly;i++){
        int w = upper_bound(p+1, p+1+m, y[i].d) - p;
        ll s = p[w] - y[i].d;
        ll delta = y[i].v *1ll * y[i].v + 2ll * y[i].a * s;
        if(delta < 0)continue;
        double vp = sqrt(delta);
        if(vp > V){
            is[i] = 1;
            ans++;
        }
    }
    return ans;
}

int work2(){
    int ans = rand() % m;
    return ans;
}

int main(){

    srand(time(0));
    cin.tie(0), cout.tie(0);
    cin>>T;
    while(T--){
        cin>>n>>m>>L>>V;
        lx = ly = 0;
        ans1 = 0, ans2 = 0;
        for(int i=1;i<=n;i++){
            int d, v, a;
            cin>>d>>v>>a;
            if(a <= 0){
                ly++;
                y[ly].d = d;
                y[ly].v = v;
                y[ly].a = a;
            }else{
                lx++;
                x[lx].d = d;
                x[lx].a = a;
                x[lx].v = v;
            }
        }

        for(int i=1;i<=m;i++){
            cin>>p[i];
            q[p[i]] = 1;
        }
        sort(p+1, p+1+m);
        if(p[m] == L)sum[L] = 1;

        for(int i=L-1;i>=0;i--){
            sum[i] = sum[i+1] + (q[i]);
        }

        ans1 = work();
        ans2 = work2();
        cout<<ans1<<" "<<m - ans2<<endl;
    }

    return 0;
}
