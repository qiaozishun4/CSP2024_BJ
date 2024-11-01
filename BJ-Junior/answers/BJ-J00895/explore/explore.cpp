#include <iostream>
using namespace std;
int n,m,k,x,y,d,xa,ya;
long long sum;
char c;
bool w[1001][1001];
bool h[1001][1001];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin>>t;
    for(int q=1;q<=t;q++){
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>c;
                w[i][j]=(c=='.');
            }
        }
        h[x][y]=1;
        for(int i=1;i<=k;i++){
            if(d==0){
                xa=x;
                ya=y+1;
            }
            else if(d==1){
                xa=x+1;
                ya=y;
            }
            else if(d==2){
                xa=x;
                ya=y-1;
            }
            else if(d==3){
                xa=x-1;
                ya=y;
            }//1 ≤ x ′ ≤ n, 1 ≤ y ′ ≤ m
            if(1<=xa&&xa<=n&&1<=ya&&ya<=m&&w[xa][ya]){
                x=xa;
                y=ya;
                h[x][y]=1;
            }
            else d=(d+1)%4;
        }
        //cout<<"*";
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                sum+=h[i][j];
                //cout<<i<<" "<<j<<":"<<h[i][j]<<endl;
                h[i][j]=0;
            }
        }
        cout<<sum<<endl;
        sum=0;
    }

    return 0;
}
