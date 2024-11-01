#include <bits/stdc++.h>
using namespace std;
int t;
int n;
int a[1000005];
int co[1000005];
long long cnt(){
    int lastred = -1,lastblue = -1;
    long long c = 0;
    for(int i = 0;i<n;i++){
        if(co[i] == 1){
            if(lastred == -1){
                lastred = i;
                continue;
            }else{
                if(a[lastred] == a[i]){
                    c += a[lastred];
                }
                lastred = i;
            }
        }else{
            if(lastblue == -1){
                lastblue = i;
                continue;
            }else{
                if(a[lastblue] == a[i]){
                    c += a[lastblue];
                }
                lastblue = i;
            }
        }
    }
    return c;
}
long long dfs(int deep){
    if(deep == n){
        return cnt();
    }
    long long ans = -1;
    for(int i = 1;i<=2;i++){
        co[deep] = i;
        ans = max(ans,dfs(deep+1));
    }
    return ans;
}
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 0;i<n;i++){
            scanf("%d",&a[i]);
        }
        cout<<dfs(0)<<endl;
    }
    return 0;
}
