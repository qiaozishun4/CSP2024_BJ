#include<bits/stdc++.h>
using namespace std;
int n,m,L,V;
struct car{
    int d,v,a,s;
}c[100010];
int e[100010];
pair<int,int>s[100010];
int T;
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    scanf("%d",&T);
    while(T--){
        scanf("%d%d%d%d",&n,&m,&L,&V);
        for(int i=1;i<=n;i++){
            scanf("%d%d%d",&c[i].d,&c[i].v,&c[i].a);
        }
        for(int i=1;i<=m;i++)scanf("%d",&e[i]);
        int top=0;
        for(int i=1;i<=n;i++){
            int j=lower_bound(e+1,e+m+1,c[i].d)-e;
            if(j<0)continue;
            if(c[i].a==0){
                if(c[i].v>V&&j<=m)s[++top]={m,j};
            }
            else if(c[i].a<0){
                if(c[i].v>V){
                    int y=lower_bound(e+j,e+1+m,c[i].d+(int)ceil((1.0000*V*V-1.0000*c[i].v*c[i].v)/(2.0000*c[i].a)))-e-1;
                    if(y<0)y=m;
                    if(y<j)continue;
                    s[++top]={y,j};
                }
            }
            else {
                if(c[i].v>V&&j<=m)s[++top]={m,j};
                else {
                    int y=upper_bound(e+j,e+1+m,c[i].d+(int)((1.0000*V*V-1.0000*c[i].v*c[i].v)/(2.0000*c[i].a)))-e;
          //          cout<<c[i].d+(int)((1.0*V*V-c[i].v*c[i].v)/(2*c[i].a))<<endl;
                    if(y<0||y>m)continue;
                    s[++top]={m,y};
                }
            }
           // cout<<s[top].second<<" "<<s[top].first<<" "<<top<<endl;
        }
        printf("%d ",top);
        sort(s+1,s+1+top);
        int sum=0;
        if(top>0)sum++;
        for(int i=1,j=s[1].first;i<=top;i++){
     //       cout<<s[i].second<<"->"<<s[i].first<<endl;
            if(s[i].second>j){
                j=s[i].first;
                sum++;
            }
        }
        printf("%d\n",m-sum);
        memset(c,0,sizeof c);
        memset(e,0,sizeof e);
        memset(s,0,sizeof s);
    }
}
