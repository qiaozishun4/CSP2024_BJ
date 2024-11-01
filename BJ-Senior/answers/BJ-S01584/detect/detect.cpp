#include<bits/stdc++.h>
using namespace std;
#define LD long double
const int NR = 1e5;
const LD eps = 1e-6;
struct Node{
    int l, r;
};
int p[NR + 10];
inline bool cmp(Node x, Node y){
    if(x.r != y.r) return x.r < y.r;
    return x.l < y.l;
}
struct Vec{
    int len;
    Node arr[NR + 10];
    inline void myclr(){
        len = 0;
    }
    inline void pushbk(const Node x){
        arr[++len] = x;
    }
    inline Node bk(){
        return arr[len];
    }
    inline void paixu(){
        if(len == 0) return ;
        sort(arr + 1, arr + 1 + len, cmp);
    }
};
Vec a;
Vec vec;
int n, m, len, lim;
inline bool check(int v, int add, int del){
    LD sssd = sqrt((LD)v * (LD)v + (LD)2 * (LD)add * (LD)del);
    LD vlim = (LD)lim;
    return vlim - sssd < -eps;
}
inline int Find(int d, int v, int add){
    if(add > 0){
        int l = 0, r = len - d, best = -1;
        while(l <= r){
            int mid = (l + r) >> 1;
            if(check(v, add, mid)){
                best = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        }
        return best;
    }
    if(add < 0){
        int l = 0, r = len - d, best = -1;
        while(l <= r){
            int mid = (l + r) >> 1;
            if(check(v, add, mid)){
                best = mid;
                l = mid + 1;
            }
            else r = mid - 1;
        }
        return best;
    }
    return -1;
}
inline void read(int &x){
    int ret = 0, zfh = 1;
    char c = getchar();
    while((c < '0' || c > '9') && c != '-'){
        c = getchar();
    }
    if(c == '-'){
        zfh = -1;
        c = getchar();
    }
    while(c >= '0' && c <= '9'){
        ret = (ret << 1) + (ret << 3) + c - '0';
        c = getchar();
    }
    x = ret * zfh;
}

int main(){
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    int T;
    scanf("%d", &T);
    while(T--){
        //duo ce yao qing kong
        a.myclr();
        vec.myclr();
        read(n);
        read(m);
        read(len);
        read(lim);
        for(int i = 1;i <= n;i++){
            int d, v, add;
            read(d);
            read(v);
            read(add);
            if(add == 0){
                if(v > lim) a.pushbk(Node{d, len});
            }
            else if(add > 0){
                int del = Find(d, v, add);
                if(del == -1) continue;
                int st = d + del;
                if(st > len) continue;
                a.pushbk(Node{st, len});
            }
            else if(add < 0){
                if(v <= lim) continue;
                int del = Find(d, v, add);
                int ed = d + del;
                if(ed > len) ed = len;
                a.pushbk(Node{d, ed});
            }
        }
        for(int i = 1;i <= m;i++){
            read(p[i]);
        }
        if(a.len == 0){
            printf("0 %d\n", m);
            continue;
        }
        a.paixu();
        int cnt = 0;
        for(int i = 1;i <= a.len;i++){
            // printf("l=%d r=%d\n", i.l, i.r);
            int l = lower_bound(p + 1, p + 1 + m, a.arr[i].l) - p;
            int r = upper_bound(p + 1, p + 1 + m, a.arr[i].r) - p - 1;
            if(l <= r){
                // printf("a[l=%d]=%d a.arr[i].l=%d\n", l, p[l], a.arr[i].l);
                // printf("a[r=%d]=%d a.arr[i].r=%d\n", r, p[r], a.arr[i].r);
                // if(!(p[l] >= a.arr[i].l) || !(p[r] <= a.arr[i].r)){
                //     printf("here!\n");
                // }
                if(vec.len == 0) vec.pushbk(a.arr[i]);
                else{
                    if(vec.bk().r == a.arr[i].r){
                        vec.arr[vec.len].l = max(vec.arr[vec.len].l, a.arr[i].l);
                    }
                    else vec.pushbk(a.arr[i]);
                }
                cnt++;
            }
            // printf("l=%d r=%d\n", l ,r);
        }
        printf("%d ", cnt);
        int ans = 0, last = -1;
        for(int i = 1;i <= vec.len;i++){
            // printf("l=%d r=%d\n", vec[i].l, vec[i].r);
            // printf("last=%d\n", last);
            if(vec.arr[i].l <= last && last <= vec.arr[i].r) continue;
            last = p[upper_bound(p + 1, p + 1 + m, vec.arr[i].r) - p - 1];
            ans++;
        }
        printf("%d\n", m - ans);
        // break;
    }
    return 0;
}
/*
cd ~/GJH/detect && g++ detect.cpp && ./a.out

1
5 5 15 3
0 3 0
12 4 0
1 1 4
5 5 -2
6 4 -4
2 5 8 9 15

*/