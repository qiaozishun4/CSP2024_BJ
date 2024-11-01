#include<bits/stdc++.h>
using namespace std;
//#define int long long
//#define endl '\n'
#define ll long long
int cnt;

int n,m,L,lim;
const int MAXN =1e5+5;
const int MAXM =1e5+5;
const double eps =1e-5;
const double equ =1e-6;
int T;
struct Node{
    double l,r;
}f[MAXN];
int p[MAXN];
void get(double d,double v,double a){
    //cout<<d<<' '<<v<<' '<<a<<endl;
    if(a<=eps&&a>=-eps){
        if(v>1.0*lim){
            f[++cnt]={d,L};
        }
        return ;
    }
    else if(a<0){
        if(v>1.0*lim){
            double temp=(lim*lim-v*v)/(2*a)-eps;
            f[++cnt]={d,min(d+temp,1.0*L)};
            /*if(d+temp<1.0*L){f[++cnt]={d,d+temp};}
            else {f[++cnt]={d,L};}*/
            //f(f[cnt].l>f[cnt].r)cout<<"ERR"<<endl;
        }
    }
    else if(a>0){
        if(v<1.0*lim){
            double temp=(lim*lim-v*v)/(2*a)+eps;
            if(d+temp<1.0*L){
                f[++cnt]={d+temp,L};
            }
        }
        else if(1.0*lim-eps<v&&v<1.0*lim+eps){f[++cnt]={d+eps,L};}
        else if(v>1.0*lim){f[++cnt]={d,L};}
    }
}

void csh(){
    cnt=0;
}

bool cmp(Node a,Node b){
    if(a.r-equ<b.r&&b.r<a.r+equ){
        return a.l<b.l;
    }
    else{
        return a.r<b.r;
    }
}

int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    //freopen("data.in","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>T;
    while(T--){
        cin>>n>>m>>L>>lim;
        int d,v,a;
        for(int i=1;i<=n;i++){
            cin>>d>>v>>a;
            get(d,v,a);
            //if(bf<cnt)printf("%.4lf %.4lf \n",f[cnt].l,f[cnt].r);
        }
        for(int i=1;i<=m;i++){
            cin>>p[i];
            //cout<<p[i]<<' ';
        }
        p[m+1]=1e6+5;
        //cout<<endl;
        sort(f+1,f+cnt+1,cmp);
        int tempans=0;double temppos =-1;int unjudged=0;
        int i,j=0;
        for(i=1;i<=cnt;i++){
            if(f[i].l>temppos){
                while(1.0*p[j]<f[i].l&&j<=m){j++;}
                if(1.0*p[j]>f[i].r){unjudged++;continue;}
                while(1.0*p[j+1]<=f[i].r+equ&&j<=m){j++;}
                //printf("%.4lf %.4lf ",f[i].l,f[i].r);cout<<"by"<<p[j]<<endl;
                tempans++;
                temppos=p[j];
            }
        }
        cout<<cnt-unjudged<<' '<<m-tempans<<endl;
        csh();
    }
    return 0;
}
