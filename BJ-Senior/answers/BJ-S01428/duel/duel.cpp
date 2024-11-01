#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <fstream>
#include <queue>
using namespace std;
int n,a[100000+10],b[100000+10],bg,sm,ans;
pair<int,int> c[100000+10];
void cou(){
    int s = 1;
    for (int i=1;i<=n;i++){
        int t = 1;
        while (a[i+1]==a[i]){
            t+=1;
            i+=1;
        }
        c[s++] = make_pair(a[i],t);
        b[s-1] = t;
    }
}
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    scanf ("%d", &n);
    for (int i=1;i<=n;i++) scanf ("%d", &a[i]);
    sort (a+1,a+n+1);
    cou();
    sm = 1;
    bg = 2;
    while(bg<=n&&sm<=n){
        while (b[bg]==0&&bg<=n){
            bg+=1;
            if (bg>n) break;
        }
        while (c[sm].second==0&&sm<=n){
            sm+=1;
            if (sm>n) break;
        }
        if (bg==sm) bg+=1;  //force up
        if (c[bg].second > c[sm].second){
            b[bg]-=c[sm].second;
            c[sm].second = 0;
        }
        else if (c[bg].second < c[sm].second){
            c[sm].second = c[sm].second - c[bg].second;
            b[bg] = 0;
        }
        else if (c[bg].second == c[sm].second){
            c[sm].second = 0;
            b[bg] = 0;
        }
    }
    for (int i=1;i<=n;i++){
        ans+=c[i].second;
    }
    printf ("%d\n", ans);
    return 0;
}
