#include<bits/stdc++.h>
using namespace std;

int p[100000],n,m,l,v,d[100000],e[100000],a[100000],sum,ans,s[100000];

int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);

        cin>>n>>m>>l>>v;
        for(int i=1;i<=n;i++){
            cin>>d[i]>>e[i]>>a[i];
        }
        int maxa=0,da;
        for(int i=1;i<=m;i++){
            cin>>p[i];
            if(p[i]>maxa){
                da=i;
                maxa=p[i];
            }
        }
        int y=n;
        for(int i=1;i<=n;i++){
            if(a[i]>0){
                int x=da;
                if(sqrt(2*a[i]*(p[x]-d[i])+e[i])>v){
                    sum++;
                    s[p[x]]++;
                }
            }
            if(a[i]<0){
                auto x=lower_bound(p+1,p+1+n,d[i]);
                if(sqrt(2*a[i]*(p[*x]-d[i])+e[i])>v){
                    sum++;
                    s[p[*x]]++;
                }
            }
            if(a[i]=0){
                if(e[i]>v){
                    sum++;
                    y--;
                }
            }
        }
        cout<<sum;
        for(int i=1;i<=l;i++){
            if(!s[p[i]]){
                ans++;
            }
        }
    return 0;
}
