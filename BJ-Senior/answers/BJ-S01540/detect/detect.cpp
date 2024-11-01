#include<bits/stdc++.h>
using namespace std;
int a[100005][5]={};
int monitor[100005]={};
bool mocnt[100005]={};
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int T;
    cin >> T;
    for(int i=1;i<=T;i++){
        memset(a,0,sizeof(a));
        memset(monitor,0,sizeof(monitor));
        memset(mocnt,0,sizeof(mocnt));
        int n,m,L,V;
        cin>>n>>m>>L>>V;
        for(int j=1;j<=n;j++){
            cin >> a[j][1] >> a[j][2] >> a[j][3];
        }
        for(int j=1;j<=m;j++){
            cin >> monitor[j];
        }
        int cnt=0;
        int moni=0;
        int maxn=0;
        for(int j=1;j<=n;j++){
            int x0=a[j][1];
            if(a[j][3]==0){
                int v=a[j][2];
                if(v>V and x0<=monitor[m]){
                    cnt++;
                    maxn = max(maxn,x0);
                }
            }
            else if(a[j][3]>0){
                int v0 = a[j][2];
                for(int k=1;k<=m;k++){
                    /*if(x0<monitor[k]&&x0<=monitor[m]){
                        int cha = monitor[m]-x0;
                        double t = sqrt(pow(v0,2)+cha*2.0*a[j][3]);
                        double vt = v0*t+0.5*pow(a[j][3],2);
                        if(vt>V){
                            cnt++;
                            break;
                        }
                    }*/
                    if(x0==monitor[k]){
                        if(v0>V){
                            cnt++;
                            break;
                        }
                    }
                    else if(x0<=monitor[m]){
                        int cha = monitor[m]-x0;
                        double vt = sqrt(pow(v0,2)+cha*2.0*a[j][3]);
                        //double vt = v0*1.0*t+0.5*pow(t,2)*a[j][3];
                        if(vt>V){
                            cnt++;
                            break;
                        }
                    }
                }
            }
            //else{

            //}
        }
        if(cnt!=0)moni = m-1;
        if(moni==0)moni=m;
        cout<<cnt<<" "<<moni<<endl;
    }

    return 0;
}
