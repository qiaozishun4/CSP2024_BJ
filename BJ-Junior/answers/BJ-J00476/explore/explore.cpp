#include<iostream>
using namespace std;
#define int long long
const int N = 1e3+2;
char a[N][N];
bool v[N][N];
int n,m,t,k,x_1,y_1,d0;

void go(){
    int ans=1;
    int x_2,y_2;
    v[x_1][y_1]=1;
    while(k--){
        x_2=x_1,y_2=y_1;
        if(d0==0) y_2+=1;
        if(d0==1) x_2+=1;
        if(d0==2) y_2-=1;
        if(d0==3) x_2-=1;
        if(a[x_2][y_2]=='.') {
                //first +1;
            if(v[x_2][y_2]==0) {
                    ans++;v[x_2][y_2]=1;
            }
            x_1=x_2,y_1=y_2;
        }
        else d0=(d0+1)%4;
    }
    cout<<ans<<endl;
}

void fun(){
    cin>>t;
    while(t--){
        cin>>n>>m>>k;
        cin>>x_1>>y_1>>d0;
        for(int i=0;i<=n+1;i++) a[i][0]='x';
        for(int i=0;i<=n+1;i++) a[i][m+1]='x';
        for(int j=0;j<=m+1;j++) a[0][j]='x';
        for(int j=0;j<=m+1;j++) a[n+1][j]='x';
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>a[i][j];
            }
        }
        for(int i=0;i<=n+1;i++){
            for(int j=0;j<=m+1;j++)
                v[i][j]=0;
        }
        go();
    }


}
signed main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    fun();

    return 0;
}
