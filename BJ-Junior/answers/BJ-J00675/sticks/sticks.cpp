#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+9;
int num[44] = {0,-1,1,7,4,2,6,8,10,18,22,20,28,80,88,180,188,228,208,288,808,888,1080,1888,2288,2088,2888,8088,8888,10888,18888,22888,20888,28888,80888,88888,108888,188888,228888,208888,288888,808888,888888,1088888};
int ans[maxn];
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int _;
    cin>>_;
    while(_--){
        int n,x,k = 1;
        cin>>n;
        int t = n/42;
        int h = n%42;
        if((h == 1 && t == 0) || (h == 0 && t == 0)){
            cout<<-1<<endl;
            continue;
        }else if(h == 1){
            t--;
            h+=42;
        }
        if(h!=0) x = num[h];
        while(x){
            ans[k] = x%10;
            x = x/10;
            k++;
        }
        while(t--){
            for(int i = 0;i<6;i++){
                ans[k] = 7;
                k++;
            }
        }
        sort(ans+1,ans+k);
        int b = 1;
        while(ans[b]==0){
            b++;
        }
        cout<<ans[b];
        for(int i = 1;i<b;i++) cout<<0;
        for(int i = 1+b;i<k;i++){
            cout<<ans[i];
        }
        cout<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

