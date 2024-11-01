#include<bits/stdc++.h>
using namespace std;
struct node{
    int d,v,a;
    double cs;
    bool vis;
}a[100005];
int t,n,m,l,V,s[100005];
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>t;
    while(t--){
        for(int i=1;i<=100000;i++) a[i].vis=0;
        cin>>n>>m>>l>>V;
        for(int i=1;i<=n;i++){
            cin>>a[i].d>>a[i].v>>a[i].a;
            if(a[i].a==0){
                if(a[i].v>V){
                    a[i].cs=a[i].d;
                }else{
                    a[i].cs=-1;
                }
            }else if(a[i].a>0){
                if(a[i].v>V) a[i].cs=a[i].d;
                else a[i].cs=(V-a[i].v)/a[i].a+a[i].d;
            }else{
                if(a[i].v<=V){
                    a[i].cs=-1;
                }else{
                    a[i].cs=(V-a[i].v)/a[i].a+a[i].d;
                }
            }

        }
        int ans1=0,ans2=0;
        for(int i=1;i<=m;i++){
            cin>>s[i];
            for(int j=1;j<=n;j++){
                if(!a[j].vis&&a[j].cs!=-1&&a[j].cs<=l){
                    if(a[j].a>=0){
                        if(s[i]>=a[j].cs){
                            ans1++;
                            a[j].vis=1;
                        }
                    }else{
                        if(s[i]<=a[j].cs&&s[i]>=a[j].d){
                            ans1++;
                            a[j].vis=1;
                        }
                    }
                }
            }
        }
        cout<<ans1<<' '<<ans1;
    }
    fclose(stdin);
    fclose(stdout);
}
