#include<bits/stdc++.h>
using namespace std;
int a[100002],b[100002];
struct car{
    int d;
    int v;
    int a;
    float l;
    float r;
    bool b;
}c[100001];
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int t,op;
    cin>>t;
    for(op=0;op<t;op++){
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        int n,m,i,j,k,l,v,s=0;
        cin>>n>>m>>l>>v;l++;
        for(i=0;i<n;i++){
            cin>>c[i].d>>c[i].v>>c[i].a;
        }
        for(i=0;i<m;i++){
            cin>>a[i];
        }
        for(i=0;i<n;i++){
            if(c[i].v>v){
                c[i].l=c[i].d;
                if(c[i].a>=0){
                    c[i].r=20000000;//1 1 4       3
                }else{
                    c[i].r=(1.0*(pow(v,2)-pow(c[i].v,2))/(2.0*c[i].a))+c[i].d;
                    if(c[i].r==int(c[i].r))c[i].r-=0.5;
                }
            }else{
                c[i].l=(1.0*(pow(v,2)-pow(c[i].v,2))/(2.0*c[i].a))+c[i].d;
                if(c[i].l>l)c[i].l=-1;
                if(c[i].l==int(c[i].l))c[i].l+=0.5;
                if(c[i].a<=0){
                    c[i].r=-1;
                    c[i].l=-1;
                }else{
                    c[i].r=20000000;
                }
            }


        }for(i=0;i<n;i++){
            if(c[i].l<0)continue;
            k=0;
            for(j=0;j<m;j++){
                if(a[j]>=c[i].l&&a[j]<=c[i].r){
                    b[j]++;
                    k=1;
                    c[i].b=1;
                }

            }
                s+=k;
        }
        cout<<s<<' ';
        int mx=0,maxk=0;s=0;

        for(;1==1;){
            mx=0,maxk=0;
            for(i=0;i<m;i++){
                if(b[i]>mx){
                    mx=b[i];
                    maxk=i;
                }
            }
            for(i=0;i<n;i++){
                for(int iop=0;iop<10000;iop++);
                if(c[i].b==0)continue;
                if(c[i].l<=a[maxk]&&c[i].r>=a[maxk]){

                    for(j=0;j<m;j++){

                        if(a[j]>c[i].r ||c[i].l>a[m-1]||c[i].l<0)break;
                        if(a[j]>=c[i].l)b[j]--;
                    }c[i].b=0;
                }
            }
            if(mx==0)break;s++;
        }cout<<m-s<<endl;
    }

}
