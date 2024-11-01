#include<bits/stdc++.h>
using namespace std;
int T,n,m,l,v,cnt,cnt1,cnt2=1;
int a[100004];
//int b[1000004];
struct node1{
    int b,e;
}s[100005];
struct node{
    int d,a,v;
    double ma;
}c[100005];
bool cmp(node1 a,node1 b){
    if(a.b!=b.b) return a.b<b.b;
    return a.e<b.e;
}
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>T;
    while(T--){
        cnt=cnt1=0;
        cnt2=1;
        cin>>n>>m>>l>>v;
        for(int i=0;i<n;i++) cin>>c[i].d>>c[i].v>>c[i].a;
        for(int i=0;i<m;i++) cin>>a[i];
        //a[m]=l+1;
        /*int coun=m-1;
        for(int i=l;i>=1;i++){
            b[i]=b[i+1];
            if(a[coun]==i){
                b[i]=i;
                coun--;
            }
        }*/
        for(int i=0;i<n;i++){
            if(c[i].d<=a[m-1]){
               if(c[i].a>0){
                    c[i].ma=sqrt(2*c[i].a*(a[m-1]-c[i].d)+c[i].v*c[i].v);
                    if(c[i].ma>v) cnt1++;
                }else if(c[i].a==0) if(c[i].v>v) cnt1++;
                else{
                    //if(c[i].v>v){
                        for(int i=m-1;i>=0;i--){
                            c[i].ma=sqrt(2*c[i].a*(a[i]-c[i].d)+c[i].v*c[i].v);
                            if(c[i].ma>v){
                                s[cnt].e=a[i];
                                for(int k=0;k<m;k++) if(a[k]>c[i].d){s[cnt].b=a[k];break;}
                                if(s[cnt].e<s[cnt].b){s[cnt].e=s[cnt].b=0;continue;}
                                cnt1++;
                                cnt++;
                                break;
                            }
                        }

                    //}
                }
            }
        }
        sort(s,s+cnt,cmp);
        int be=s[0].b,en=s[0].e;
        for(int i=1;i<cnt;i++){
            if(s[i].b<=en){
                be=s[i].b;
                en=min(s[i].e,en);
            }else{
                be=s[i].b,en=s[i].e;
                cnt2++;
            }
        }
        cout<<cnt1<<' '<<m-cnt2-1<<endl;
    }
    return 0;
}
