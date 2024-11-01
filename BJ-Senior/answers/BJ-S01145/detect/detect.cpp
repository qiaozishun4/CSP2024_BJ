#include<bits/stdc++.h>
using namespace std;
struct car{
    int d,v,a;
    double s;
    bool flag=0;
}b[10001];
struct kk{
    int s,e;
}c[10001];
bool cmp(kk a,kk b){
    return a.e<b.e;
}
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int t;
    cin>>t;
    for(int k=0;k<t;k++){
        int n,m,l,v0;
        int sum=0;
        int p[10001];
        int f[10001]={},num=0;
        for(int i=0;i<n;i++){
            cin>>b[i].d>>b[i].v>>b[i].a;
            if(b[i].v<=3 && b[i].a<=0){
                b[i].flag=1;
            }else{
                b[i].s=(v0*v0-b[i].v*b[i].v)/2*b[i].a;
                b[i].s+=b[i].d;
            }
        }
        for(int i=0;i<m;i++){
            cin>>p[i];
        }
        for(int i=0;i<n;i++){
            num=0;
            if(b[i].flag==1){
                continue;
            }
            for(int j=0;j<m;j++){
                if(p[j]>=b[i].d && p[j]<=b[i].s){
                    sum++;
                    break;
                }
            }
            for(int j=0;j<m;j++){
                if(p[j]>=b[i].d && p[j]<=b[i].s){
                        f[num++]=p[j];
                }
            }
            c[i].s=f[0];
            c[i].e=f[num-1];
        }
        cout<<sum;
        int cnt=1;
        sort(c,c+num-1,cmp);
        int end=c[0].e;
        for(int i=1;i<n;i++){
            if(c[i].s>end){
                end=c[i].e;
                cnt++;
            }
        }
        cout<<m-cnt;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
