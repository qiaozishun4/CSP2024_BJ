#include<bits/stdc++.h>
using namespace std;
int t,n,b[50001],k,c[50001];
struct sb
{
    int s,b;
}a[6];
void dfs(int x,int y){
    if(y-1>k)return;
    if(x<2){
        if(x==0){
            int g=y-1;
            if(c[1]==0)return;
            if(g<k){
                k=g;
                for(int i=1;i<=k;i++)b[i]=c[i];
            }
            else if(g==k){
                int f=0;
                for(int i=1;i<=k;i++)
                {
                    if(c[i]<b[i]){
                        f=i;
                        break;
                    }
                }
                if(f)for(int i=f;i<=k;i++)b[i]=c[i];
            }
        }
        return;
    }
    for(int i=0;i<6;i++){
        if(a[i].b<=x){
            c[y]=a[i].s;
            dfs(x-a[i].b,y+1);
        }
    }
    return;
}
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>t;
    a[0].s=8;
    a[0].b=7;
    a[1].s=0;
    a[1].b=6;
    a[2].s=2;
    a[2].b=5;
    a[3].s=4;
    a[3].b=4;
    a[4].s=7;
    a[4].b=3;
    a[5].s=1;
    a[5].b=2;
    while(t--){
        cin>>n;
        if(n==1){
            cout<<-1<<endl;
            continue;
        }
        k=1e7;
        memset(b,9,sizeof(b));
        dfs(n,1);
        for(int i=1;i<=k;i++)cout<<b[i];
        cout<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
