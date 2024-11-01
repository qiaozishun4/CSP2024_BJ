#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
int n,m,t;
double L,V;
struct node{
    double v;
    double d;
    double a;
} s[N];
double p[N];
bool f(int x){
    double o = s[x].v;
    for(int i = 1;i <= m;i++){
        if(p[i] >= s[x].d){
            o = sqrt(o*o + 2.0*s[x].a*(p[i]-s[x].d));
            if(o > V) return true;
        }
    }
    return false;
}
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin >> t;
    while(t--){
        int cnt = 0;
        cin >> n >> m >> L >> V;
        for(int i = 1;i <= n;i++){
            cin >> s[i].d >> s[i].v >> s[i].a;
        }
        for(int j = 1;j <= m;j++){
            cin >> p[j];
        }
        for(int i = 1;i <= n;i++){
            if(f(i)) cnt++;
        }
        cout << cnt << " " << cnt <<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
