#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
int n,r[100010],ans,rmax=0;
bool flag=true;
bool vis[100010];
int t[100010]={};
int eat[100010]={};
vector<int>v;
bool cmp(int x,int y){
    return x<y;
}
bool check(int x){
    for(int i=x+1;i<=n;i++){
        if(vis[i]==false&&r[i]>r[x]){
            vis[i]=true;
            return true;
        }
    }
    return false;
}
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    scanf("%d",&n);
    ans=n;
    for(int i=1;i<=n;i++){
        scanf("%d",&r[i]);
        t[r[i]]++;
        eat[r[i]]++;
        rmax=max(r[i],rmax);
        vis[i]=false;
        if(r[i]>2){
            flag=false;
        }
    }
    if(flag==true){
        int r1=0,r2=0;
        for(int i=1;i<=n;i++){
            if(r[i]==1){
                r1++;
            }
            if(r[i]==2){
                r2++;
            }
        }
        if(r2>=r1){
            ans=ans-r1;
        }else{
            ans=ans-r2;
        }
        printf("%d",ans);
        return 0;
    }
    if(n<=8000){
        sort(r+1,r+n+1,cmp);
        for(int i=1;i<=n;i++){
            if(check(i)==true){
                ans--;
            }else{
                break;
            }
        }
        printf("%d",ans);
        return 0;
    }
    for(int i=1;i<=rmax;i++){
        if(t[i]!=0){
            v.push_back(i);
        }
    }
    for(int i=0;i<v.size();i++){
        int eatmax=0,needeat=0,tmp=0;
        needeat=t[v[i]];
        for(int j=i+1;j<v.size();j++){
            eatmax+=eat[v[j]];
            if(eatmax>=t[v[i]]){
                eatmax=t[v[i]];
                tmp=j;
                break;
            }
        }
        if(eatmax>=t[v[i]]){
            t[v[i]]=0;
            for(int j=i+1;j<v.size();j++){
                if(eat[v[j]]<eatmax){
                    eatmax-=eat[v[j]];
                    eat[v[j]]=0;
                }else{
                    eat[v[j]]-=eatmax;
                    eatmax=0;
                    break;
                }
                if(eatmax==0){
                    break;
                }
            }
        }else{
            t[v[i]]-=eatmax;
            break;
        }
    }
    ans=0;
    for(int i=0;i<v.size();i++){
        ans+=t[v[i]];
    }
    printf("%d",ans);

    return 0;
}
