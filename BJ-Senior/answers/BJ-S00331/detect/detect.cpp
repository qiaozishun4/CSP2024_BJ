#include<bits/stdc++.h>
using namespace std;
int t,n,m,L,V,d[100005],v[100005],a[100005],p[100005],hv[100005],hvcnt,ulco[100005],ulal,usf[100005],hv2[100005],hvcnt2;
int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>t;
    while(t--){
        for(int i=0;i<100005;i++){
            d[i]=0;v[i]=0;a[i]=0;p[i]=0;hv[i]=-1;ulco[i]=-1;usf[i]=-1;hvcnt=0;ulal=0;hv2[i]=-1;hvcnt2=0;
        }
        cin>>n>>m>>L>>V;
        for(int i=0;i<n;i++){
            cin>>d[i]>>v[i]>>a[i];
        }
        for(int i=0;i<m;i++){
            cin>>p[i];
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(p[j]>=d[i])if(sqrt((double)2*a[i]*(p[j]-d[i])+v[i]*v[i])>V){
                    if(hv[i]==-1){
                        hv[i]=j;
                        //cout<<i<<" ";
                        //usf[j]=1;
                        hvcnt++;
                        ulco[j]=0;
                        /*if(ulco[j]==1){
                            ulco[j]=-1;
                            ulal--;
                        }*/
                    }
                    else if(ulco[j]==-1&&usf[j]!=1){
                        ulco[j]=1;
                        ulal++;
                    }

                }
            }
        }
        for(int i=0;i<m;i++){
            if(ulco[i]==-1){
                ulal++;
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(ulco[j]!=1)if(p[j]>=d[i])if(sqrt((double)2*a[i]*(p[j]-d[i])+v[i]*v[i])>V){
                    if(hv[i]==-1){
                        hv2[i]=j;
                        hvcnt2++;
                    }

                }
            }
        }
        if(hvcnt2<hvcnt)ulal--;
        cout<<hvcnt<<" "<<ulal<<endl;
    }

    return 0;
}
