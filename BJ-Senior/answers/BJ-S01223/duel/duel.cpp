#include<bits/stdc++.h>
using namespace std;
int n,a[10005],minn = 10005,maxn = 0,qwe1,ans=0;
bool eater[10005];
void find(int minn){
    for(int i = minn+1;i<=maxn;i++){
        for(int j = 1;j<=n;j++){
            if(a[j] == i && eater[j]){
                eater[j] = false;
                a[qwe1] = 0;
                qwe1 = j;
                break;
            }
        }
    }
}

int panding(){
    int all=0;
    for(int i = 1;i<=n;i++){
        if(!eater[i] || a[i] == 0){
            all++;
        }
    }
    if(all == n)return 0;
    else return 1;
}
int findlow(){
    int findlow1=10005;
    for(int i = 1;i<=n && a[i] !=0;i++){
        if(a[i]<findlow1)findlow1 = a[i];
    }
    return findlow1;
}
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin >> n;
    for(int i = 1;i<=n;i++)cin >> a[i];
    for(int i = 1;i<=n;i++)eater[i] = true;
    for(int i = 1;i<=n;i++){
        if(a[i]<minn)minn = a[i];
        if(a[i]>maxn)maxn = a[i];
    }
    while(panding()){
        for(int i = 1;i<=n;i++){
            if(a[i] == findlow())qwe1 = i;
        }
        find(findlow());
    }
    for(int i = 1;i<=n;i++){
        if(a[i]!=0)ans++;
    }
    cout << ans;
    return 0;
}
