#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
struct node{
    int di,vi,ai,of=0;
}a[30][10000];
struct node1{
    int num,nf=0;
    int ch[1000],zt[1000];
}b[30][10000];
bool cmp(node1 x,node1 y){
    return x.nf>y.nf;
}
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        int n,m,l,v,sum=m;
        cin>>n>>m>>l>>v;
        for(int x=1;x<=n;x++){
            cin>>a[i][x].di>>a[i][x].vi>>a[i][x].ai;
        }
        for(int y=1;y<=m;y++){
            cin>>b[i][y].num;
            for(int x=1;x<=n;x++){
                if(a[i][x].di<=b[i][y].num){
                    if(sqrt(2*a[i][x].ai*(b[i][y].num-a[i][x].di)+pow(a[i][x].vi,2))>v){
                        b[i][y].nf++;
                        b[i][y].ch[b[i][y].nf]=x;
                        b[i][y].zt[b[i][y].nf]=1;
                    }
                }
            }
        }
        for(int y=1;y<=m;y++){
            if(b[i][y].nf==0){
                sum--;
                continue;
            }
        }
        sort(a+m,a+1+m,cmp);
        for(int y=sum;y>=1;y--){
            int g=b[i][y].nf;
            for(int x=1;x<=sum;x++){
                for(int z=1;z<=b[i][x].nf;z++){
                    for(int q=1;q<=b[i][y].nf;q++){
                        if(b[i][x].ch[z]==b[i][y].ch[q]&&b[i][y].zt[q]==1){
                            g--;
                            b[i][y].zt[q]=0;
                        }
                    }
                }
            }
            if(g==0){
                sum--;
            }
        }
        cout<<sum;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
