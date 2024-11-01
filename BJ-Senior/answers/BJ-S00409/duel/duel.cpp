#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n;
int a[N];
int k[N];
int pre, num;
int ans;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i = 1; i <= n; i++) cin>>a[i];
    sort(a + 1, a + n + 1);
    int now = 0;
    for(int i = 1; i <= n; i++){
        if(a[i] == a[i - 1]) k[now]++;
        else{
            k[++now]++;
        }
    }
    //for(int i = 1; i <= now; i++) cout<<k[i]<<" ";
    //cout<<endl;
    pre = 1;
    num = k[1];
    for(int i = 2; i <= now; i++){
        //cout<<i<<" "<<pre<<" "<<num<<" "<<ans<<endl;
        if(k[i] <= num){
            ans += k[i];
            num -= k[i];
        }else{
            int op = k[i];
            ans += num;
            op -= num;
            if(pre == i - 1){
                pre = i;
                num = k[i];
            }
            for(int j = pre + 1; j < i; j++){
                if(k[j] <= op){
                    op -= k[j];
                    ans += k[j];
                    if(j == i - 1){
                        pre = i;
                        num = k[i];
                    }
                }else{
                    ans += op;
                    num = k[j] - op;
                    pre = j;
                }
            }
        }
    }
    cout<<n - ans;
    return 0;
}
