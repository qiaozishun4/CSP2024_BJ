#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
using namespace std;

struct segment{
    long long l,r;
} seg[100005];

long long n,m,l,mxv;
long long d[100005];
long long v[100005];
long long a[100005];
long long p[100005];

int ans=0,ans2=0;
bool chosen[105];
void dfs(int lvl){
    if(lvl>m){
        int anss=0,cnt=0;
        for(int i=1;i<=m;++i){
            //cout<<chosen[i];
            cnt+=chosen[i];
        }//cout<<endl;
        for(int i=1;i<=n;++i){
            for(int j=1;j<=m;++j){
                if(chosen[j]){
                    if(d[i]<=p[j]){
                        //cout<<i<<' '<<j<<' '<<(sqrt(v[i]*v[i]+2*a[i]*(p[j]-d[i])))<<endl;
                        if(((v[i]*v[i]+2*a[i]*(p[j]-d[i]))>mxv*mxv) && a[i]!=0){
                            ++anss;
                            //cout<<i<<endl;
                            break;
                        }else if(a[i]==0){
                            if(v[i]>mxv){
                                ++anss;
                                //cout<<i<<endl;
                                break;
                            }
                        }
                    }
                }
            }
        }if(anss==ans){
            ans2=min(ans2,cnt);
        }return ;
    }chosen[lvl]=false;
    dfs(lvl+1);
    chosen[lvl]=true;
    dfs(lvl+1);
}

bool cmp(segment a,segment b){
    if(a.r==b.r){
        return a.l<b.l;
    }return a.r<b.r;
}

int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        bool planB=true;
        cin>>n>>m>>l>>mxv;
        for(int i=1;i<=n;++i){
            cin>>d[i]>>v[i]>>a[i];
            if(a[i]){
                planB=false;
            }
        }long long mxp=0;
        for(int i=1;i<=m;++i){
            cin>>p[i];
            mxp=max(mxp,p[i]);
        }if(planB){         //subtask #3 #4
            int ans=0;
            for(int i=1;i<=n;++i){
                if(v[i]>mxv && d[i]<=mxp){
                    ++ans;
                }
            }cout<<ans<<' '<<m-1<<'\n';
        }else if(n<=20){    //subtask #1 #2
            ans=0;
            for(int i=1;i<=n;++i){
                for(int j=1;j<=m;++j){
                    if(d[i]<=p[j]){
                        //cout<<i<<' '<<j<<' '<<(sqrt(v[i]*v[i]+2*a[i]*(p[j]-d[i])))<<endl;
                        if(((v[i]*v[i]+2*a[i]*(p[j]-d[i]))>mxv*mxv) && a[i]!=0){
                            ++ans;
                            //cout<<i<<endl;
                            break;
                        }else if(a[i]==0){
                            if(v[i]>mxv){
                                ++ans;
                                //cout<<i<<endl;
                                break;
                            }
                        }
                    }
                }
            }cout<<ans<<' ';
            ans2=m;
            dfs(1);
            cout<<m-ans2<<'\n';
        }else if(n<=3000){
            sort(p+1,p+m+1);
            ans=0;
            int tn=1;
            for(int i=1;i<=n;++i){
                for(int j=1;j<=m;++j){
                    if(d[i]<=p[j]){
                        //cout<<i<<' '<<j<<' '<<(sqrt(v[i]*v[i]+2*a[i]*(p[j]-d[i])))<<endl;
                        if(((v[i]*v[i]+2*a[i]*(p[j]-d[i]))>mxv*mxv) && a[i]!=0){
                            ++ans;
                            seg[tn].l=j;
                            for(int k=j;k<=m;++k){
                                if((v[i]*v[i]+2*a[i]*(p[k]-d[i]))<0){
                                    break;
                                }if((v[i]*v[i]+2*a[i]*(p[k]-d[i]))>mxv*mxv){
                                    seg[tn].r=k;
                                }else{
                                    break;
                                }
                            }//cout<<i<<endl;
                            ++tn;
                            break;
                        }else if(a[i]==0){
                            if(v[i]>mxv){
                                ++ans;
                                seg[tn].l=j;
                                seg[tn].r=m;
                                ++tn;
                                //cout<<i<<endl;
                                break;
                            }
                        }
                    }
                }
            }cout<<ans<<' ';
            ans2=0;
            //for(int i=1;i<tn;++i){
                //cout<<seg[i].l<<' '<<seg[i].r<<endl;
            //}
            sort(seg+1,seg+tn,cmp);
            seg[tn].l=1e9;
            seg[tn].r=-1;
            int last=1,curp=1,ans=0;
            while(last<tn){
                while(curp<=seg[last].r){
                    ++curp;
                }--curp;
                while(seg[last].l<=curp){
                    ++last;
                }++ans2;
                //cerr<<last<<' '<<curp<<endl;
            }cout<<m-ans2<<'\n';
        }else{
            sort(p+1,p+m+1);
            ans=0;
            int tn=1;
            for(int i=1;i<=n;++i){
                if(a[i]<0){
                    if(v[i]>mxv){
                        seg[tn].l=lower_bound(p+1,p+m+1,d[i])-p;
                        seg[tn].r=upper_bound(p+1,p+m+1,d[i]+(mxv*mxv-v[i]*v[i])*0.5/a[i])-p;
                        if(seg[tn].l<=seg[tn].r){
                            ++tn;
                        }
                    }
                }else if(a[i]==0){
                    if(v[i]>mxv){
                        seg[tn].l=lower_bound(p+1,p+m+1,d[i])-p;
                        seg[tn].r=m;
                        if(seg[tn].l<=seg[tn].r){
                            ++tn;
                        }
                    }
                }else{
                    seg[tn].l=upper_bound(p+1,p+m+1,d[i]+max(0.0,(mxv*mxv-v[i]*v[i])*0.5/a[i]))-p;
                    seg[tn].r=m;
                    if(seg[tn].l<=seg[tn].r){
                        ++tn;
                    }
                }
            }cout<<tn-1<<' ';
            ans2=0;
            //for(int i=1;i<tn;++i){
                //cout<<seg[i].l<<' '<<seg[i].r<<endl;
            //}
            sort(seg+1,seg+tn,cmp);
            seg[tn].l=1e9;
            seg[tn].r=-1;
            int last=1,curp=1,ans=0;
            while(last<tn){
                while(curp<=seg[last].r){
                    ++curp;
                }--curp;
                while(seg[last].l<=curp){
                    ++last;
                }++ans2;
                //cerr<<last<<' '<<curp<<endl;
            }cout<<m-ans2<<'\n';
        }
    }return 0;
}
