#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t,n,m,k,x,y,d,a[1001][1001]={0};
    cin>>t;
    while(t--){
        memset(a,0,sizeof(a));
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                char temp;
                cin>>temp;
                if(temp=='x') a[i][j]=1;
            }
        }
        int p=x,q=y,cnt=1;
        a[p][q]=2;
        while(k--){
            if(d==0) q++;
            else if(d==1) p++;
            else if(d==2) q--;
            else p--;
            if(1<=p&&p<=n&&1<=q&&q<=m&&a[p][q]!=1){
                if(a[p][q]!=2) cnt++;
                x=p;
                y=q;
                a[p][q]=2;
            }
            else d=(d+1)%4;p=x;q=y;
        }
        cout<<cnt<<endl;
    }
    return 0;
}
