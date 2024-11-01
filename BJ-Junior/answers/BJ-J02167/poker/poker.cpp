#include <iostream>
#include <cstdlib>
using namespace std;

bool vis[256][256];

int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n,cnt=0;
    cin>>n;
    for(int i=1;i<=n;++i){
        char a,b;
        cin>>a>>b;
        if(!vis[a][b]){
            ++cnt;
        }vis[a][b]=true;
    }cout<<52-cnt;
    return 0;
}
