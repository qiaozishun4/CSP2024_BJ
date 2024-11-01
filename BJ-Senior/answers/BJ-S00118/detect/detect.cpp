#include<iostream>
using namespace std;
int d[100001],v[100001],a[100001],p[100001],bixu[100001];
int qsort(int l,int ri){
    int i=l,j=ri,x;
    int mid=p[(i+j)/2];
    do{
        while(p[i]<mid) i++;
        while(p[j]>mid) j--;
        if(i<=j){
            x=p[i];
            p[i]=p[j];
            p[j]=x;
            i++;j--;
        }
    }while(i<=j);
    if(l<j) qsort(l,j);
    if(i<ri) qsort(i,ri);
    return 0;
}
int ss(int le,int ri,int num){
    int mid=(le+ri)/2;
    if(le==ri){
        if(p[le]>=num) return le;
        else return -1;
    }
    if(num>p[mid]) return ss(mid+1,ri,num);
    else if(num==p[mid]) return mid;
    else if(num<p[mid]) return ss(le,mid,num);
}
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int t;
    int n,m,l,vmax;
    int i,i1;
    cin>>t;
    for(int ii=0;ii<t;ii++){
        int bx=0,en=0,cs=0,zsyg=0,dyg,yn;
        double ti,x;
        cin>>n>>m>>l>>vmax;
        for(i=1;i<=n;i++){
            cin>>d[i]>>v[i]>>a[i];
        }
        for(i=1;i<=m;i++){
            cin>>p[i];
        }
        qsort(1,m);
        for(i=1;i<=n;i++){
            if(a[i]>0){
                if(v[i]>vmax){
                    cs++;
                    en=1;
                }
                else{
                    ti=(vmax-v[i])/a[i];
                    x=v[i]*ti+0.5*(a[i]*ti*ti);
                    if(x<p[m]-d[i]){
                        cs++;
                        en=1;
                    }
                }
            }
            else if(a[i]<0){
                if(v[i]<vmax);
                else if(v[i]>=vmax){
                    ti=-(v[i]-vmax)/a[i];
                    x=v[i]*ti+0.5*a[i]*ti*ti;
                    dyg=ss(0,m,d[i]);
                    if(dyg!=-1){
                        if(x>p[dyg]-d[i]){
                            cs++;
                            if(p[dyg]==p[m]);
                            else{
                                yn=1;
                                for(int i1=1;i1<=bx;i1++){
                                    if(bixu[i1]>=d[i]&&bixu[i1]<d[i]+x)
                                        yn=0;
                                }
                                if(yn==1){
                                    for(i1=dyg;i1<m;i1++){
                                        if(p[i1]>=d[i]+x)
                                            break;
                                    }
                                    bixu[++bx]=p[i1-1];
                                }
                            }
                        }
                    }
                }
            }
            else if(a[i]==0){
                if(v[i]>vmax&&d[i]<=p[m]){
                    cs++;
                    zsyg=1;
                }
            }
        }
        cout<<cs<<" ";
        if(bx+en==0&&zsyg==1)
            bx++;
        cout<<m-(bx+en)<<endl;
    }
    return 0;
}
