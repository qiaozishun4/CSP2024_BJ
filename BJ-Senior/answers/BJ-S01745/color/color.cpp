# include <bits/stdc++.h>
using namespace std;
int ans = -1;
int n;
void dfs(int *a,int *c,int num,int l){
    if(l==n){
        ans = max(ans,num);
        return;
    }
    int f1=0,f2=0;
    for(int i=l-1;i>=0;i--){
        if(c[i]==1){
            if(a[i]==a[l]) f1 = a[l];
            break;
        }
    }
    for(int i=l-1;i>=0;i--){
        if(c[i]==2){
            if(a[i]==a[l]) f2 = a[l];
            break;
        }
    }
    c[l] = 1;
    dfs(a,c,num+f1,l+1);
    c[l] = 2;
    dfs(a,c,num+f2,l+1);
}
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        ans = -1;
        int a[20005],c[20005];
        cin>>n;
        for(int i=0;i<n;i++) scanf("%d",&a[i]);
        dfs(a,c,0,0);
        cout<<ans<<endl;
    }
    return 0;
}
