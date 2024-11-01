//gufen:100+100+100+100 wendu shuzu kongjian bianyi
#include<bits/stdc++.h>
using namespace std;
#define int long long
int read(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c<='9'&&c>='0')x=x*10+c-'0',c=getchar();return x*f;}
const int MAXN=100010;
int n,m,ans,a[MAXN];
map<pair<char,char>,bool>mp;
void slv(){
    n=read();
    for(int i=1;i<=n;i++){
        char x=getchar();
        while(x!='D'&&x!='C'&&x!='H'&&x!='S')x=getchar();
        char y=getchar();
        while((y<'0'||y>'9')&&y!='T'&&y!='J'&&y!='Q'&&y!='K'&&y!='A')y=getchar();
        ans+=1-mp[{x,y}];
        mp[{x,y}]=1;
    }
    printf("%lld",52-ans);
}
signed main(){
    freopen("poker.in","r",stdin);freopen("poker.out","w",stdout);
    slv();
    fclose(stdin);fclose(stdout);
    return 0;
}