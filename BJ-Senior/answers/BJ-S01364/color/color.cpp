#include<bits/stdc++.h>
using namespace std;
int T;
int n;
int a[200001];
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        map<int,int> mp;
        int idx=0;
        for(int i=1;i<=n;i++){
            int x;scanf("%d",&x);
            if(!mp[x])a[++idx]=x;
            mp[x]++;
        }
        int ans=0;
        for(int i=1;i<=idx;i++){
            ans+=(mp[a[i]]-1)*a[i];
        }
        printf("%d\n",ans);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}