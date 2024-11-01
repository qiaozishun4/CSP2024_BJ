#include<bits/stdc++.h>
using namespace std;
int minn,minx;
int t,n;
int nu[10] = {6,2,5,5,4,5,6,3,7,6};
void dfs(int x,int num,int cho){
    if(x>minx) return;
    if(num==0){
        minn = min(minn,cho);
        if(minn==cho){
            minx = x;
        }
        return;
    }
    for(int i=0;i<=9;i++){
        if(!(x==1 and i==0) and nu[i]<=num){
            dfs(x+1,num-nu[i],10*cho+i);
        }
    }
}
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin >> t;
    while(t--){
        minn=minx=1e9+7;
        cin >> n;
        dfs(1,n,0);
        if(minn!=1e9+7) cout << minn << '\n';
        else cout << -1 << '\n';
    }
    return 0;
}
