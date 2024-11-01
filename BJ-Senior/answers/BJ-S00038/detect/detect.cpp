#include<bits/stdc++.h>
#define maxn 100001
using namespace std;
int t,n,m,L,V,photo[maxn],ans1,ans2;
int d[maxn],v[maxn],a[maxn];
bool exc(int i,int last){//wether  at last
    double kkk=sqrt(v[i]*v[i]+2.0*a[i]*(last-d[i]))*1.0;
    if(kkk>V&&d[i]<=last)return true;
    return false;
}
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin >>t;
    for(int mm=0;mm<t;mm++){
            ans1=0;
        ans2=0;
        cin >>n>>m>>L>>V;
        for(int i=0;i<=m;i++)photo[i]=0;

        for(int kk=0;kk<n;kk++){
            cin >>d[kk]>>v[kk]>>a[kk];
        }
        for(int i=1;i<=m;i++){
            cin >>photo[i];
        }
        if(a[0]==0){
            for(int i=0;i<n;i++){
                if(v[i]>V&&d[i]<=photo[m]){
                    ans1++;
                }
            }
        }else{
            for(int i=0;i<n;i++){
                if(v[i]>V&&d[i]<=photo[m]){
                    ans1++;
                }
                else if(exc(i,photo[m])){
                    ans1++;
                }
            }
        }
        if(ans1==0)m++;
        cout <<ans1<<" "<<m-1<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
