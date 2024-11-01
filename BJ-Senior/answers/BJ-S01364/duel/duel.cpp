#include<bits/stdc++.h>
using namespace std;
int n,idx;
int a[100001];
map<int,int> mp;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int x;scanf("%d",&x);
        if(!mp[x])a[++idx]=x;
        mp[x]++;
    }
    sort(a+1,a+n+1,cmp);
    int ans=0,num=0;
    for(int i=1;i<idx;i++){
        num+=mp[a[i]];
        if(num>=mp[a[i+1]]){
            num-=mp[a[i+1]];
            mp[a[i+1]]=0;
        }
        else {
            mp[a[i+1]]-=num;
            num=0;
        }
    }
    for(int i=1;i<=idx;i++)ans+=mp[a[i]];
    printf("%d",ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
