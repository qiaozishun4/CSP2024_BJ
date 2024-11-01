#include<iostream>
#include<string>
using namespace std;
string s[100005];
int l[100005];
bool cando=0;
int r;
char c;
int n,k,q;
void dfs(int x,string hh){
    if(x>=r+1){
        if(hh[hh.length()-1]==c){
            cando=1;
        }
        return;
    }
    for(int i=1;i<=s[x%n].length();i++){
        if(s[x%n][i-1]==hh[hh.length()-1]||x==1){
            for(int j=2;j<=k&&(i+j<=s[x].length());j++){
                string a=s[x%n].substr(i,j);
                if(a!=hh){
                    dfs(x+1,a);
                }
            }
        }
    }
}
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        cin>>n>>k>>q;
        for(int j=1;j<=n;j++){
            cin>>l[j];
            for(int jj=1;jj<=l[i];jj++){
                char a;
                cin>>a;
                s[j]+=a;
            }
        }
        for(int j=1;j<=q;j++){
            cin>>r>>c;
            if(r==1){
                for(int jj=2;jj<s[1].length();jj++){
                    if(s[1][jj-1]==c){
                        cando=1;
                    }
                }
            }
            else{
                dfs(1,"hh");
            }
            cout<<!cando<<'\n';
            cando=0;
        }
    }
    return 0;
}
