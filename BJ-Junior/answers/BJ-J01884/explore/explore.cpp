#include<iostream>
using namespace std;
bool mp[100010][100010];
char v[100010][100010];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    //freopen("explore.in","w",stdout);
    int q;
    cin>>q;
    for(int i=1;i<=q;i++){
        int n,m,k;
        cin>>n>>m>>k;
        int x,y,d;
        cin>>x>>y>>d;
        for(int j=1;j<=n;j++){
            for(int s=1;s<=m;s++){
                cin>>v[j][s];
            }
        }
        mp[x][y]=1;
        for(int j=1;j<=k;j++){
            switch(d){
                case 0:y++;break;
                case 1:x++;break;
                case 2:y--;break;
                case 3:x--;break;
            }
            if(y>m || x>n || y<0 || x<0 || v[x][y]=='x'){
                switch(d){
                    case 0:y--;break;
                    case 1:x--;break;
                    case 2:y++;break;
                    case 3:x++;break;
                }
                d++;
                if(d>3)d=0;
            }
            else {
                mp[x][y]=1;
            }
        }
        int cnt=0;
        for(int j=1;j<=n;j++){
            for(int s=1;s<=m;s++){
                if(mp[j][s]==1)cnt++;
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}
