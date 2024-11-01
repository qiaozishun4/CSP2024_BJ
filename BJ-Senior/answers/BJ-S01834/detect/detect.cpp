#include<bits/stdc++.h>
using namespace std;
int T,n,m,L;
double V;
double d[200005],a[200005],v[200005],h[200005],zhuang[200005];
int chao,guan=0,op=0,need=0,nono[200005];
double endp;
double le;
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>T;
    for(int p=1;p<=T;p++){
            for(int i=0;i<m;i++){
                zhuang[i]=0;
                nono[i]=0;
            }
        cin>>n>>m>>L>>V;
        for(int i=0;i<n;i++){
            cin>>d[i];
            cin>>v[i];
            cin>>a[i];
        }
        for(int i=0;i<m;i++){
            cin>>h[i];
        }
        chao=0;
        guan=0;
        for(int i=0;i<n;i++){

            if(v[i]>V&&a[i]>=0){
                op=0;
                for(int j=0;j<m;j++){
                    if(h[j]>=d[i]){
                        zhuang[j]++;
                        nono[j]=i;
                        op=1;
                    }
                }
                if(op==1){
                    chao++;
                }
            }
            if(v[i]>V&&a[i]<0){
                op=0,endp=V*V;
                le=v[i]*v[i];
                endp-=le;
                endp/=2;
                endp/=a[i];
                endp+=d[i];
                for(int j=0;j<m;j++){
                    if(h[j]>=d[i]&&h[j]<endp){
                        zhuang[j]++;
                        op=1;
                        nono[j]=i;
                    }
                }
                if(op==1){
                    chao++;
                }
            }
            if(v[i]<=V&&a[i]>0){
                op=0;
                endp=V*V;
                le=v[i]*v[i];
                endp-=le;
                endp/=2;
                endp/=a[i];
                endp+=d[i];
                for(int j=0;j<m;j++){
                    if(h[j]>endp){
                        zhuang[j]++;
                        op=1;
                        nono[j]=i;
                    }
                }
                if(op==1){
                    chao++;
                }
            }
        }
        for(int i=1;i<m;i++){
            if(zhuang[i]==zhuang[i-1]&&nono[i]!=nono[i-1]){
                guan++;
            }else if(zhuang[i]<zhuang[i-1]){
                guan++;
            }
        }
        cout<<chao<<" "<<m-guan<<endl;
    }
    fcolse(stdin);
    fclose(stdout);
    return 0;
}
