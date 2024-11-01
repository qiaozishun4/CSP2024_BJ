#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN = 200005, MAXA = 1000006, _INF = 0xc0c0c0c0c0c0c0c0;
struct Bucket{
    int b[MAXA], tag, maxi;
    void init(int *a, int n){
        b[0]=_INF;
        for(int i=0;i<n;i++)b[a[i]]=_INF;
        maxi = _INF;
        tag = 0;
    }
    void global(int x){
        tag += x;
    }
    void insert(int a, int f){
        b[a] = max(b[a], f-tag);
        maxi = max(maxi, f-tag);
    }
    int rmax(int a){
        return max(maxi, b[a] + a) + tag;
    }
}f;
int a[MAXN];
signed main(){
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        for(int i=0;i<n;i++)cin>>a[i];
        f.init(a,n);
        f.insert(0,0);
        for(int i=0;i<n;i++){
            int fi1 = f.rmax(a[i]);
            if(i && a[i] == a[i-1])f.global(a[i]);
            f.insert(i?a[i-1]:0,fi1);
        }
        cout<<f.maxi+f.tag<<endl;
    }
    return 0;
}