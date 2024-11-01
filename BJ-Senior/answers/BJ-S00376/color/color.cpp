#include<bits/stdc++.h>
using namespace std;

int n,ans;
int a[1000002],ca[1000002];
int cnt1,cnt2,c1[100002],c2[100002];

void calc(){
    int temp=0;
    for(int i=1;i<=cnt1;++i){
        if(a[c1[i]]==a[c1[i-1]]){
            temp+=a[c1[i]];
        }
        //printf("%d ",c1[i]);
    }
    //printf(" ");
    for(int i=1;i<=cnt2;++i){
        if(a[c2[i]]==a[c2[i-1]]) {
            temp+=a[c2[i]];
        }
        //printf("%d ",c2[i]);
    }
    //printf("\n");
    ans=max(ans,temp);
}

void dfs(int p){
    if(p==n){
        if(ca[a[p]]==1){
            c1[++cnt1]=p;
            calc();
            --cnt1;
        }
        else if(ca[a[p]]==2){
            c2[++cnt2]=p;
            calc();
            --cnt2;
        }
        else if(ca[a[p]]==0){
            c1[++cnt1]=p;
            ca[a[p]]=1;
            calc();
            --cnt1;
            c2[++cnt2]=p;
            ca[a[p]]=2;
            calc();
            --cnt2;
        }
        return;
    }
    //printf("%d %d\n",a[p],ca[a[p]]);
    if(ca[a[p]]==1){
        c1[++cnt1]=p;
        dfs(p+1);
        --cnt1;
    }
    else if(ca[a[p]]==2){
        c2[++cnt2]=p;
        dfs(p+1);
        --cnt2;
    }
    else if(ca[a[p]]==0){
        c2[++cnt2]=p;
        //ca[a[p]]=2;
        dfs(p+1);
        --cnt2;
        c1[++cnt1]=p;
        //ca[a[p]]=1;
        dfs(p+1);
        --cnt1;

    }
}

int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int t;
    scanf("%d",&t);
    while(t--){
        ans=0;
        cnt1=cnt2=0;
        memset(ca,0,sizeof(ca));
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d",a+i);
        }
        //printf("\n");
        dfs(1);
        printf("%d\n",ans);
    }


    return 0;
}
