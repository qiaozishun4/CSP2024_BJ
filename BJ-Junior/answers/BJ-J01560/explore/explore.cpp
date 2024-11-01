#include <bits/stdc++.h>
using namespace std;

int a[1001][1001];

int main (){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int T;
    scanf("%d",&T);
    while(T--){
        //输入
        int n,m,k;
        scanf("%d%d%d",&n,&m,&k);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                a[i][j]=0;
            }
        }
        //输入字符阵
        int x,y,d;
        scanf("%d%d%d",&x,&y,&d);
        for(int i=1;i<=n;i++){
            string s;
            cin>>s;
            for(int j=1;j<=m;j++){
                if(s[j-1]=='.') a[i][j]=1;
                else a[i][j]=-1;
            }
        }
        //模拟
        int ans=1;
        a[x][y]=2;
        while(k--){
            int x1=x,y1=y;
            if(d==0) y1+=1;
            else if(d==1) x1+=1;
            else if(d==2) y1-=1;
            else x1-=1;
//            cout<<"k="<<k<<" x1="<<x1<<" y1="<<y1<<endl;
            if(x1<=0||y1<=0||x1>n||y1>m){
                d=(d+1)%4;
                continue;
            }else{
                if(a[x1][y1]==-1){
//                    cout<<"A"<<endl;
                    d=(d+1)%4;
                    continue;
                }else if(a[x1][y1]==1){
//                    cout<<"B"<<endl;
                    ans++;
                    a[x1][y1]=2;
                    x=x1,y=y1;
                }else{
                    x=x1,y=y1;
                }
            }
//            cout<<"x="<<x<<" y="<<y<<endl;
        }
        cout<<ans<<endl;
    }
    return 0;
}