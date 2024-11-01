#ifndef DETECT_CPP_INCLUDED
#define DETECT_CPP_INCLUDED

#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;
const int maxm = 1e5+10;
const int maxl = 1e6+10;
int cnt = 0;
int n, m, L, maxv;
struct node
{
    int pos, v, a;
}car[maxn];
int det[maxm];
double spe[maxn][2];
bool check(int i){
    double l, r;
    if(car[i].a > 0){
        if(car[i].v > maxv){
            l = (double)car[i].pos-0.0001;
            r = (double)L+0.0001;
        }
        else{
            l = car[i].pos+(double)(maxv*maxv-car[i].v*car[i].v)/(2*car[i].a)-0.0001;
            r = (double)L+0.0001;
            //cout<<l<<" "<<r<<endl;
        }
    }
    if(car[i].a == 0){
        if(car[i].v > maxv){
            l = (double)car[i].pos-0.0001;
            r = (double)L+0.0001;
        }
        else{
            l = 0.0000;
            r = 0.0000;
        }
    }
    if(car[i].a < 0){
        if(car[i].v > maxv){
            l = (double)car[i].pos-0.0001;
            r = car[i].pos+(double)(maxv*maxv-car[i].v*car[i].v)/(2*car[i].a)+0.0001;
        }
        else{
            l = 0.0000;
            r = 0.0000;
        }
    }
    spe[i][0] = l;
    spe[i][1] = r;
    for(int j=1;j<=m;j++){
        if(det[j]>l && det[j]<r) return true;
    }
    return false;
}
struct node1{
    double l, r;
}vis[maxn];
bool cmp(node1 x, node1 y){
    if(x.l == y.l) return x.r<y.r;
    else return x.l < y.l;
}
int check2(){
    int num = 0;
    for(int i=1;i<=n;i++){
        if(check(i)){
            vis[++num].l = spe[i][0];
            vis[num].r = spe[i][1];
        }
    }
    //cout<<1<<endl;
    sort(vis+1, vis+num+1, cmp);
    int tmp = 1;
    int ans = 0;
    for(int j=1;j<=m;j++){
        if(tmp == num) return ans;
        if(det[j] > vis[tmp].l && det[j] < vis[tmp].r){
            ans++;
            while(tmp <= num && vis[tmp].l<det[j] && vis[tmp].r>det[j]) tmp++;
        }
    }
    return ans;
}
int T;
int main(){
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    scanf("%d", &T);
    while(T--){
        scanf("%d%d%d%d", &n, &m, &L, &maxv);
        for(int i=1;i<=n;i++) scanf("%d%d%d", &car[i].pos, &car[i].v, &car[i].a);
        for(int i=1;i<=m;i++) scanf("%d", &det[i]);
        sort(det+1, det+1+m);
        cnt = 0;
        for(int i=1;i<=n;i++){
            if(check(i)) cnt++;
        }
        //for(int i=1;i<=n;i++) cout<<spe[i][0]<<" "<<spe[i][1]<<endl;
        cout<<cnt<<endl;
        //cout<<1<<endl;
        cout<<m-check2()<<endl;
    }
    return 0;
}

#endif // DETECT_CPP_INCLUDED
