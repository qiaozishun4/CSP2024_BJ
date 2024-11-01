#include<iostream>
#include<fstream>
#include<iomanip>
int T;
int n,m,k;
int x_0,y_0,d_0,x_r,y_r,d_r,x_t,y_t;
char mappe[2005][2005];
int passe[2005][2005];
int passcnt;
using namespace std;
int main() {
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>T;
    while(T--) {
        cin>>n>>m>>k>>x_0>>y_0>>d_0;
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=m;j++) {
                cin>>mappe[i][j];
            }
        }
        x_r=x_0;
        y_r=y_0;
        d_r=d_0;
        passe[x_0][y_0]=1;
        for(int i=0;i<k;i++) {
            x_t=x_r;
            y_t=y_r;
            if(d_r==0) {
                y_t++;
            } else if(d_r==1) {
                x_t++;
            } else if(d_r==2) {
                y_t--;
            } else if(d_r==3) {
                x_t--;
            }
            if(x_t<=0 || x_t>n || y_t<=0 || y_t>m || mappe[x_t][y_t]=='x') {
                d_r=(d_r+1)%4;
            } else if(mappe[x_t][y_t]=='.') {
                x_r=x_t;
                y_r=y_t;
                passe[x_r][y_r]=1;
            }
            //cout<<"xryr "<<x_r<<" "<<y_r<<" "<<d_r<<endl;
        }
        passcnt=0;
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=m;j++) {
                if(mappe[i][j]=='.' && passe[i][j]==1) {
                    //cout<<"passe "<<i<<" "<<j<<endl;
                    passcnt++;
                }
            }
        }
        cout<<passcnt<<endl;
    }
    return 0;
}
