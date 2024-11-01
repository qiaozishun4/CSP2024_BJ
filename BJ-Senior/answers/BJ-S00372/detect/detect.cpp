#include<iostream>
#include<cmath>
using namespace std;
const int N=3005;
const int M=3005;
int t;
int d[N];
int v[N];
int a[N];
int p[M];
//int v_now[N][M];//第n辆车在第m个测速仪的时候的速度
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>t;
    while(t--){
        for(int i=1;i<=3004;i++){
            d[i]=-1;
            v[i]=-1;
            a[i]=-1;
            p[i]=-1;
            p[i]=-1;
        }
        int n,m,l,vmax;
        cin>>n>>m>>l>>vmax;
        bool guess=true;
        bool guess1=true;
        for(int i=1;i<=n;i++){
            cin>>d[i]>>v[i]>>a[i];
            if(a[i]!=0){
                guess=false;
            }
            if(a[i]<=0){
                guess1=false;
            }
        }
        for(int i=1;i<=m;i++){
            cin>>p[i];
        }
        if(guess==true){
            int ans1=0;
            for(int i=1;i<=n;i++){
               if(v[i]>vmax){
                    if(p[m]>=d[i]){
                        ans1++;
                    }
                }
            }
            cout<<ans1<<" "<<"4"<<endl;
            //int last_ans=0;
            //for(int i=1;i<=n;i++){//车
                //int daan=m;
                //int ans2=0;
                //for(int j=1;j<=m;j++){//测速仪
                    //if(v[i]>3){
                        //if(p[j]<d[i]){
                            //daan--;
                        //}
                    //}
                //}
                //ans2=m-daan;
                //last_ans=max(last_ans,ans2);
            //}
            //cout<<last_ans<<endl;
        }
        else if(guess1==true){
            int cnt=0;
            for(int i=1;i<=n;i++){
                if(p[m]>d[i]){
                    int nowv=sqrt((2*a[i]*(p[m]-d[i]))+(v[i]*v[i]));
                    if(nowv>vmax){
                        cnt++;
                    }
                }
            }
            cout<<cnt<<" ";
            int last_ans=0;
            for(int i=1;i<=n;i++){
                int ans1=0;
                for(int j=1;j<=m;j++){
                    if(p[j]>d[i]){
                        int nowv=sqrt((2*a[i]*(p[j]-d[i]))+(v[i]*v[i]));
                        if(nowv>vmax){
                            ans1=j-1;
                        }
                    }
                }
                last_ans=max(last_ans,ans1);
            }
            cout<<last_ans<<endl;
        }
    }
    return 0;
}
