#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;
const int N = 1e5 + 10;
int n;
int r[N];
int st[N];
vector<int> v;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&r[i]);
    for(int i=1;i<=n;i++){
        st[r[i]]++;
    }
    for(int i=0;i<=1e5;i++){
        if(st[i]){
            v.push_back(i);
        }
    }
    for(int i=0;i<v.size();i++){
        int t = st[v[i]];
        v[i] = t;
    }
    if(v.size() == 1){
        printf("%d",n);
        return 0;
    }
    for(int i=1;i<v.size();i++){
        if(v[i - 1] <= v[i]){
            v[i - 1] = 0;
        }
        else{
            v[i] = v[i - 1];
            v[i - 1] = 0;
        }
    }
    long long ans = 0;
    for(int i=0;i<v.size();i++) ans += v[i];
    printf("%lld",ans);
    return 0;
}
