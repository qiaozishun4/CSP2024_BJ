#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int n,cnt[maxn],last,ans;
struct Monster{
    int digit;
    bool gongji=false;
    bool dead=false;
}a[maxn];
bool cmp(Monster a,Monster b){
    return a.digit>b.digit;}
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;ans=n;
    for (int i=1;i<=n;i++){
        cin>>a[i].digit;
        cnt[a[i].digit]++;}
    for (int i=1;i<=100000;i++)
        if (cnt[i]!=0){
            if (last==0){
                last=cnt[i];
                continue;}
            else {
                ans-=min(cnt[i],last);
                last=cnt[i];}}
    cout << ans;
    return 0;}
