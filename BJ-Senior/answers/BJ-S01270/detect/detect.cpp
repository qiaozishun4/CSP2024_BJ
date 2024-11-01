#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
long long t,n,m,l,vm,cnt=0,cnt2=0,d[100005],v[100005],a[100005],p[100005];
int pi[1000005],di[1000005];
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>t;
    a[0]=-1;
    for(int o=1;o<=t;o++){
        cin>>n>>m>>l>>vm;
        l=l+1;
        cnt=0;
        cnt2=0;
        memset(pi,0,sizeof(pi));
        memset(di,0,sizeof(di));
        bool flag2=1;
        for(int i=1;i<=n;i++){
            scanf("%lld %lld %lld",&d[i],&v[i],&a[i]);
            //cin>>d[i]>>v[i]>>a[i];
            d[i]+=1;
            di[d[i]]=1;
            if(a[i]!=0){
                flag2=0;
            }
        }
        for(int i=1;i<=m;i++){
            scanf("%lld",&p[i]);
            p[i]+=1;
        }
        if(flag2){
            sort(p+1,p+m+1,greater<long long>());
            for(int i=1;i<=m;i++){
                bool flag=1;
                for(int j=p[i];j>=1;j--){
                    if(!pi[j]){
                        if(di[j]){
                            flag=0;
                        }
                        pi[j]=1;
                    }else{
                        break;
                    }
                }/*for(int i=1;i<=l;i++){
                    cout<<pi[i]<<' ';
                }*/
                if(flag){
                    cnt2++;
                }
            }
            for(int i=1;i<=n;i++){
                if(pi[d[i]]&&v[i]>vm){
                    cnt++;
                }
            }
            if(cnt==0)cnt2++;
            cout<<cnt<<' '<<cnt2<<endl;
        }else{
            sort(p+1,p+m+1);
            for(int i=1;i<=m;i++){
                pi[p[i]]=1;
            }/*
            for(int i=1;i<=l;i++){
                cout<<pi[i]<<' ';
            }cout<<endl;*/
            for(int i=1;i<=n;i++){
                long long index=0;
                for(int j=d[i];j<=l;j++){
                    long long s=j-d[i];
                    double db=1.0*v[i]*v[i]+2.0*a[i]*s;
                    if(db<0)break;
                    if(a[i]<=0&&sqrt(db)<=vm)break;
                    //cout<<db<<' ';
                    if(pi[j]&&sqrt(db)>vm){
                        index=j;
                        //cout<<v[i]<<' '<<a[i]<<' '<<s<<' '<<sqrt(db)<<' '<<j<<endl;
                    }
                }//cout<<endl;

                if(index){
                    cnt++;
                    pi[index]=2;
                }
            }
            for(int i=1;i<=l;i++){
                if(pi[i]==2){
                    cnt2++;
                    //cout<<i<<endl;
                }
            }
            cout<<cnt<<' '<<m-cnt2<<endl;
        }
    }
    return 0;
}