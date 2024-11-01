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
int n,k,q,r,c,l[1005],s[1005][2005];
bool dfs(int a,int x,int t){    //a表示当前接龙的人，x表示上次接龙的末尾单词，t表示现在是第几轮
    if(t==r){
        for(int i=1;i<=l[a];i++){
            if(s[a][i]==x){
                for(int j=2;j<=min(l[a]-i+1,k);j++){
                    if(s[a][i+j-1]==c){
                        return 1;
                    }
                }
            }
        }
        return 0;
    }
    bool f=0;
    for(int i=1;i<=l[a];i++){
        if(s[a][i]==x){
            for(int j=2;j<=min(l[a]-i+1,k);j++){
                for(int m=1;m<=n;m++){
                    if(a!=m){
                        f=f|dfs(m,s[a][i+j-1],t+1);
                        if(f==1){
                            break;
                        }
                    }
                }
                if(f==1){
                    break;
                }
            }
        }
        if(f==1){
            break;
        }
    }
    return f;
}
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);

    int T=read();

    while(T--){
        cin>>n>>k>>q;
        for(int i=1;i<=n;i++){
            cin>>l[i];
            for(int j=1;j<=l[i];j++){
                cin>>s[i][j];
            }
        }
        for(int i=1;i<=q;i++){
            cin>>r>>c;
            bool f=0;
            for(int j=1;j<=n;j++){
                f=f|dfs(j,1,1);
                if(f==1){
                    break;
                }
            }
            cout<<f<<"\n";
        }

        memset(l,0,sizeof(l));
        memset(s,0,sizeof(s));
    }

    return 0;
}
