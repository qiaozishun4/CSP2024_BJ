#include <bits/stdc++.h>
using namespace std;
const int maxn=2e5+7;
int a[maxn];
int n;

struct node{
    int num,cnt;
    long long cac(){
        return (long long)(num)*cnt;
    }
};

node b[maxn];

/*
int aunique(int n){
    int ind=0;
    b[ind].num = a[0];
    b[ind].cnt = 1;
    for(int i=1;i<n;i++){
        if(a[i] != b[ind].num){
            ind++;
            b[ind].num = a[i];
            b[ind].cnt = 0;
        }
        else{
            b[ind].cnt++;
        }
    }
    return ind+1;
}
*/

void solve1(){
    long long ans=0;
    map<int,long long> mp;
    for(int i=0;i<n;i++){
        cin>>a[i];
        mp[a[i]] += 1;
    }
    node x,y;
    x.num = y.num = 0;
    x.cnt = y.cnt = 0;
    for(int i=0;i<n;i++){
        mp[a[i]]--;
        if(x.num == a[i]){
            ans += a[i];
            x.cnt--;
        }
        else if(y.num == a[i]){
            ans += a[i];
            y.cnt--;
            if(x.cac() > y.cac()){
                node k=x;
                x = y;
                y = k;
            }
        }
        else{
            if(y.cac() < mp[a[i]]*a[i]){
                x = y;
                y.cnt = mp[a[i]];
                y.num = a[i];
            }
            else if(x.cac() < mp[a[i]]*a[i]){
                x.cnt = mp[a[i]];
                x.num = a[i];
            }
        }
    }
    cout<<ans<<endl;
    return;
}

long long ans2=-1;
void dfs(int ind,int a[]){
    if(ind >= n){
        long long ans=0;
        int x=-1,y=-1;
        for(int i=0;i<n;i++){
            if(b[i].cnt == 0){
                if(b[i].num == x){
                    ans += x;
                }
                else{
                    x = b[i].num;
                }
            }
            else{
                if(b[i].num == y){
                    ans += y;
                }
                else{
                    y = b[i].num;
                }
            }
        }
        ans2 = max(ans2,ans);
        return;
    }
    b[ind].num = a[ind];
    b[ind].cnt = 0;
    dfs(ind+1,a);
    b[ind].cnt = 1;
    dfs(ind+1,a);
    return;
}


void solve2(){
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    dfs(0,a);
    cout<<ans2<<endl;
    ans2 = -1;
    return;
}

/*
struct ab{
    int a,b;
    int num;
}dp[maxn][2];

ab amax(ab x,ab y){
    if(x.num > y.num)
        return x;
    else
        return y;
}

void solve3(){
    for(int i=1;i<=n;i++)
        cin>>a[i];
    dp[0][0].a = dp[0][0].b = -1;
    dp[0][1].a = dp[0][1].b = -1;
    dp[0][0].num = dp[0][1].num = 0;
    for(int i=1;i<=n;i++){
        ab l=dp[i-1][0];
        for(int j=i-1;j>=1;j--){
            if(dp[j][0].a == a[i]){
                if(dp[j][0].num+a[i] >= l.num){
                    l.num = dp[j][0].num+a[i];
                    l.a = dp[j][0].a;
                    l.b = dp[j][0].b;
                    break;
                }
            }
        }
        l.a = a[i];
        dp[i][0] = l;

        l = dp[i-1][1];
        for(int j=i-1;j>=1;j--){
            if(dp[j][1].b == a[i]){
                if(dp[j][1].num+a[i] >= l.num){
                    l.num = dp[j][1].num+a[i];
                    l.a = dp[j][1].a;
                    l.b = dp[j][1].b;
                    break;
                }
            }
        }
        l.b = a[i];
        dp[i][1] = l;
    }
    for(int i=0;i<=n;i++){
        cout<<dp[i][0].num<<" ";
    }
    cout<<endl;
    for(int i=0;i<=n;i++){
        cout<<dp[i][1].num<<" ";
    }
    cout<<endl;
    cout<<amax(dp[n][0],dp[n][1]).num<<endl;
}*/


int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int T;
    cin>>T;
    for(int t=0;t<T;t++){
        cin>>n;
        if(n <= 15)
            solve2();
        else
            solve1();
    }
    return 0;
}
