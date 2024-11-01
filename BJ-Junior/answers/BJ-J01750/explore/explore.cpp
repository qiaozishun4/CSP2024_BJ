#include<iostream>
#include<algorithm>
using namespace std;
const int Maxn=1e3+5;
int T,n,m,k,x0,d0,y0;char a[Maxn][Maxn];//zhuyiyouyushiquanjubianliangsuoyipanduanshifouchujieshibunengpanduanshifouwei0eryaopanduanshifouchaochunhuomhuo0
//(d0+1)%4
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin.tie(0);
    cin>>T;
    while(T--){
        cin>>n>>m>>k;

        bool z[Maxn][Maxn];

        cin>>x0>>y0>>d0;

        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                cin>>a[i][j];
        z[x0][y0]++;
        while(k--){
            if(d0==0){
                if(a[x0][y0+1]!='x'&&y0+1<=m){
                    y0++;
                    z[x0][y0]=1;
                    //cout<<"\n@0@\n";
                }
                else d0=(d0+1)%4;
                //cout<<"\n!0!\n";
            }else if(d0==1){
                if(a[x0+1][y0]!='x'&&x0+1<=n){
                    x0++;
                    z[x0][y0]=1;
                    //cout<<"\n@1@\n";
                }
                else d0=(d0+1)%4;
                //cout<<"\n!1!\n";
            }else if(d0==2){
                if(a[x0][y0-1]!='x'&&y0-1>=1){
                    y0--;
                    z[x0][y0]=1;
                    //cout<<"\n@2@\n";
                }
                else d0=(d0+1)%4;
                //cout<<"\n!2!\n";
            }else if(d0==3){
                if(a[x0-1][y0]!='x'&&x0-1>=1){
                    x0--;
                    z[x0][y0]=1;
                    //cout<<"\n@3@\n";
                }
                else d0=(d0+1)%4;
                //cout<<"\n!3!\n";
            }
            //cout<<x0<<" "<<y0<<" "<<d0<<endl;
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(z[i][j]==1)ans++,z[i][j]=0;
            }
        }
        cout<<ans<<endl;

    }
    return 0;
}
