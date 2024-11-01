#include <iostream>
#include <string>
using namespace std;
int t,n,m,k,x,y,d,s;
bool a[1005][1005],g[1005][1005];
string str;
void turn();
void save();
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    for(int qw=0;qw<t;++qw){
        s=0;
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        for(int i=1;i<=n;++i){
            for(int j=1;j<=m;++j){
                g[i][j]=true;
            }
        }
        for(int ni=1;ni<=n;++ni){
            cin>>str;
            for(int mi=1;mi<=m;++mi){
                if(str[mi-1]=='.')a[ni][mi]=true;
                else a[ni][mi]=false;
            }
        }
        for(int i=0;i<k;++i){
            save();
            switch(d){
                case 0:
                    if(y<m)if(a[x][y+1])++y;
                    else turn();
                    else turn();
                    break;
                case 1:
                    if(x<n)if(a[x+1][y])++x;
                    else turn();
                    else turn();
                    break;
                case 2:
                    if(y>1)if(a[x][y-1])--y;
                    else turn();
                    else turn();
                    break;
                case 3:
                    if(x>1)if(a[x-1][y])--x;
                    else turn();
                    else turn();
                    break;
            }
        }
        save();
        cout<<s<<endl;
    }
    return 0;
}
void turn(){
    ++d;
    d%=4;
}
void save(){
    if(g[x][y])s++;
    g[x][y]=false;
}
