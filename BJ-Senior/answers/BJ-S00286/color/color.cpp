#include <bits/stdc++.h>
using namespace std;

int t;

int n;

int c[200005];
bool b[200005];

int ans=-1,maxn=0;

void dfs(int deep){
    if(deep==0){
            ans=0;
        for(int i=1;i<=n;++i){
            for(int j=i-1;j>0;--j){
                if(b[j]==b[i]&&c[j]==c[i]){
                    ans+=c[i];
                    j=0;
                }
            }
        }
        if(ans>maxn){
            maxn=ans;
        }
        return;
    }
    b[n-deep+1]=1;
    dfs(deep-1);
    b[n-deep+1]=0;
    dfs(deep-1);
    return;
}

int main(){

    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);

    cin>>t;

    while(t--){
        cin>>n;
        ans=0;
        maxn=0;
        for(int i=1;i<=n;++i){
                cin>>c[i];
        }
        b[n]=1;
        dfs(n);
        b[n]=0;
        dfs(n);
        cout<<maxn<<endl;
    }

    return 0;
}

/*
#include <bits/stdc++.h>
using namespace std;

int t;

int m;

struct node{
    int a,c;
    bool b;
}n[200005];

int d[200005],ans;

bool flag;

int main(){

    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);

    cin>>t;

    while(t--){
        cin>>m;
        flag=0;ans=0;
        for(int i=1;i<=m;++i){
            cin>>n[i].a;
            d[n[i].a]++;
            n[i].c=-1;
        }
        for(int i=1;i<=m;++i){
            for(int k=1;k<=m;++k){
                if(n[i].a<n[k].a){
                    flag=1;
                }
            }
            if(d[n[i].a]>=2&&!flag){
                int j;
                for(j=i+1;n[j].a!=n[i].a;++j){

                }
                if(n[j].c!=0&&n[i].c!=0){
                    n[j].c=n[i].a;
                    ans+=n[j].c;
                    n[i+1].b=!n[i].b;
                    n[j-1].b=!n[i].b;
                    for(int k=i+2;k<j-1;++k){
                        n[k].c=0;
                        n[k].b=!n[j].b;
                    }
                }
                d[n[i].a]--;
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}
*/
