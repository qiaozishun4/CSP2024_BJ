#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+9;
int a[maxn],b[maxn],s[maxn],c[maxn],ans[maxn];
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n,k = 1;
    cin>>n;
    for(int i = 1;i<=n;i++){
        int x;
        cin>>x;
        a[x]++;
    }
    for(int i = 0;i<=maxn;i++){
        if(a[i]!=0){
            b[k] = i;
            k++;
        }
    }
    ans[1] = a[b[1]];
    sort(b+1,b+k);
    for(int i = 1;i<k;i++) c[i] = a[b[i]];
    for(int i = 1;i<k;i++) s[i] = s[i-1]+c[i];
    for(int i = 2;i<k;i++){
        int k;
        k = min(s[i]-ans[i-1],s[i-1]);
        s[i] = s[i];
        ans[i] = s[i]-k;
    }
    cout<<ans[k-1];
    fclose(stdin);
    fclose(stdout);
    return 0;
}
