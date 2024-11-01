#include<bits/stdc++.h>
using namespace std;
inline int read(){
    int c=0,ch=getchar();

    while(ch<'0'||ch>'9'){
        ch=getchar();
    }

    while(ch>='0'&&ch<='9'){
        c=c*10+ch-'0';
        ch=getchar();
    }

    return c;
}

int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);

    int T=read();

    while(T--){
        int n,m,k,x,y,d,ans=0;
        bool mp[1005][1005];
        bool l[1005][1005];

        memset(mp,0,sizeof(mp));
        memset(l,0,sizeof(l));

        scanf("%d %d %d\n %d %d %d\n",&n,&m,&k,&x,&y,&d);

        l[x][y]=1;

        for(int i=1;i<=n;i++){
            string s;
            getline(cin,s);
            for(int j=1;j<=m;j++){
                if(s[j-1]=='.'){
                    mp[i][j]=1;
                }
            }
        }

        for(int i=1;i<=k;i++){
            if(d==0){
                if(1<=y+1&&y+1<=m&&mp[x][y+1]){
                    y++;
                    l[x][y]=1;
                }else{
                    d=1;
                }
            }else if(d==1){
                if(1<=x+1&&x+1<=n&&mp[x+1][y]){
                    x++;
                    l[x][y]=1;
                }else{
                    d=2;
                }
            }else if(d==2){
                if(1<=y-1&&y-1<=m&&mp[x][y-1]){
                    y--;
                    l[x][y]=1;
                }else{
                    d=3;
                }
            }else{
                if(1<=x-1&&x-1<=n&&mp[x-1][y]){
                    x--;
                    l[x][y]=1;
                }else{
                    d=0;
                }
            }
        }

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(l[i][j]){
                    ans++;
                }
            }
        }

        cout<<ans<<"\n";
    }

    return 0;
}
