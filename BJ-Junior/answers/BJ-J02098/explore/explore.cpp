#include <iostream>
using namespace std;
int n,m,x,y,d,k,T;
struct st{
    string a;
    bool s;
};

int main(){
    freopen("explore1.in","r",stdin);
    freopen("explore123.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>T;
    for(int i=0;i<T;i++){
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        string ma[n][m];
        for(int j=0;j<n;j++){
            for(int h=0;h<m;h++){
                cin>>ma[j][h];
            }
        }
        int ans=0;
        for(int j=0;j<k;j++){
            if( ((x<=n && x>=1) && (y<=m && y>=1)) && (ma[x][y]=="."))
            {
                if(d % 4 == 0){
                y++;
                }
                else if(d % 4 == 1){
                x++;
                }
                else if(d % 4 == 2){
                    y--;
                }
                else if(d % 4 == 3){
                    x--;
                }
                ans++;
            }
            else
                d++;

            cout<<ans;
        }



    }
    return 0;

}
