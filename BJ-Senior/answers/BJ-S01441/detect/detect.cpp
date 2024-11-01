#include <iostream>
#define int long long
using namespace std;
int z[100001][5],biao[10005],b[100005];
signed main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int n,m,l,v;
        cin>>n>>m>>l>>v;
        int cnt=0;
        for(int i=1;i<=n;i++){
            int d,v,a;
            cin>>d>>v>>a;
            if(a==0){
                if(v<=3) continue;
                else {
                    z[++cnt][1]=d;
                    z[cnt][2]=l;
                }
            }
            if(a>0){
                if(v>3){
                    z[++cnt][1]=d;
                    z[cnt][2]=l;
                }else if(v==3){
                    z[++cnt][1]=d+1;
                    z[cnt][2]=l;
                }else{
                    double dx=(9-v*v)*1.0/(2.0*a);
                    if(d+dx>=l) continue;
                    else{
                        z[++cnt][1]=d+dx+1;
                        z[cnt][2]=l;
                    }
                }
            }
            else if(a<0){
                if(v<=3) continue;
                else if(v>3){
                    double dx=(9-v*v)*1.0/(2.0*a);
                    if(d+dx>l){
                        z[++cnt][1]=d;
                        z[cnt][2]=l;
                    }else if(d+dx==l){
                        z[++cnt][1]=d;
                        z[cnt][2]=l-1;
                    }
                    else{
                        z[++cnt][1]=d;
                        z[cnt][2]=d+dx-1;
                    }
                }
            }
        }
        cout<<1;
        int cnt2=0;
        for(int i=1;i<=m;i++){
            cin>>biao[i];
            for(int j=1;j<=cnt;j++){
                if(z[j][1]<=biao[i]&&biao[i]<=z[j][2]&&z[j][3]==0){
                    cnt2++;
                    z[j][3]=1;
                    b[i]++;
                }
            }
        }
        for(int i=1;i<=m;i++){
            if(b[i]==cnt2) ans=m-1;
            else ans=m-cnt2+1;
        }
        cout<<cnt2<<" "<<ans<<endl;
    }
    
    fclose(stdin);
    fclose(stdout);
    return 0;
}

