#include<bits/stdc++.h>
using namespace std;

const int MAXN=1e5+10;
int r[MAXN];
bool y[MAXN];
int mmc;

int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w" ,stdout);
    int n;
    int ans=0;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >>r[i];
    }
//1 2 3 2 1
    sort(r,r+n);
    r[0]=-1;
    int max=0;
    //-1:chuju 0:gongji 1:weigongji
    for(int i=0;i<n;i++){
        if(r[i]>max) {
            max=r[i];
            mmc=i;
        }
    }
    if(n%2!=0){
        if(r[n/2+1]<max){
            r[n/2+1]=-1;
            r[mmc]=0;
        }
    }
    for(int i=1;i<n-1;i++){
        if(r[i]<r[n-1]){
            r[i]=-1;
            r[n-i]=0;
        }
    }
    for(int i=0;i<n;i++){
        if(r[i]!=-1) ans++;
    }
    cout << ans;
    return 0;
}

