#include<bits/stdc++.h>
#define int long long
#define ld long double
using namespace std;

struct nn{
    int l,r;

    bool operator < (const nn x) const{
        if(x.l==l){
            return r<x.r;
        }

        return l<x.l;

    }
};

const ld eps=1e-7;

ld d[100005];
ld v[100005];
ld a[100005];
ld p[100005];
int a1[100005];

inline ld calc(ld v,ld a,ld s){
    ld x; x=2.0*a*1.0*s;
    return sqrt(v*v+x);
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen("detect.in" ,"r",stdin);
    freopen("detect.out","w",stdout);

    int t; cin>>t;

    while(t--){
        memset(a1,0,sizeof a1);
        int n,m; cin>>n>>m;
        ld L,V; cin>>L>>V;

        if(n<3000 && m<3000){
            for(register int i=1;i<=n;i++){
                cin>>d[i]>>v[i]>>a[i];
            }

            for(register int i=1;i<=m;i++){
                cin>>p[i];
            }

            int far; far=p[m];
            p[m+1]=LLONG_MAX;

            //cout<<"V:"<<V<<endl;
            int ans1; ans1=0;
            for(register int i=1;i<=n;i++){
                if(a[i]==0){
                    if(v[i]-V>eps){
                        ans1++;
                        a1[i]=1;
                    }
                    continue;
                }

                ld v1; v1=calc(v[i],a[i],far-d[i]);
                int l,r; l=1,r=m;
                int near; near=-1;

                while(l<=r){
                    int mid; mid=l+r>>1;
                    if(p[mid]<d[i]){
                        l=mid+1;
                    }
                    else{
                        r=mid-1;
                        near=mid;
                    }
                }

                ld v2; v2=calc(v[i],a[i],p[near]-d[i]);

                if(v1-V>eps || v2-V>eps){
                    ans1++;
                    a1[i]=1;
                }
            }

            //cout<<endl;
            cout<<ans1<<" ";

            //----------------------------------------------------------------------------------------------------
            //----------------------------------------------------------------------------------------------------

            priority_queue <nn> q;
            // int o; o=0;

            for(register int i=1;i<=n;i++){
                if(!a1[i]){
                    continue;
                }

                int cnt; cnt=0;
                int l,r; l=-1;

                for(int j=1;j<=m;j++){
                    if(p[j]>=d[i] && calc(v[i],a[i],p[j]-d[i])-V>eps){
                        //cout<<i<<" "<<j<<" "<<calc(v[i],a[i],p[j]-d[i])<<" "<<V<<endl;
                        if(l==-1){
                            l=j;
                        }

                        cnt++;
                    }
                }

                r=l+cnt-1;
                q.push({l,r});
                //cout<<i<<" "<<l<<" "<<r<<endl;
            }

            int ans2; ans2=0;
            if(!q.empty()){
                int nl,nr; nl=q.top().l,nr=q.top().r;
                while(!q.empty()){
                    nn x=q.top(); q.pop();

                    //cout<<"x:"<<x.l<<" "<<x.r<<endl;
                    //cout<<nl<<" "<<nr<<endl;

                    if(x.l<=nr && x.r>=nl){
                        nl=max(x.l,nl),nr=min(nr,x.r);
                    }
                    else{
                        ans2++;
                        nl=x.l,nr=x.r;
                    }
                }
            }

            cout<<m-ans2-1<<endl;
            continue;
        }

        for(int i=1;i<=n;i++){
            cin>>d[i]>>v[i]>>a[i];
        }

        for(int i=1;i<=m;i++){
            cin>>p[i];
        }

        int far; far=p[m];
        p[m+1]=LLONG_MAX;

        //cout<<"V:"<<V<<endl;
        int ans1; ans1=0;
        for(int i=1;i<=n;i++){
            ld v1; v1=calc(v[i],a[i],far-d[i]);
            int l,r; l=1,r=m;
            int near; near=-1;

            while(l<=r){
                int mid; mid=l+r>>1;
                if(p[mid]<d[i]){
                    l=mid+1;
                }
                else{
                    r=mid-1;
                    near=mid;
                }
            }

            ld v2; v2=calc(v[i],a[i],p[near]-d[i]);

            if(v1-V>eps || v2-V>eps){
                ans1++;
                a1[i]=1;
            }
        }

        //cout<<endl;
        cout<<ans1<<" ";

        //----------------------------------------------------------------------------------------------------
        //----------------------------------------------------------------------------------------------------

        priority_queue <nn> q;
        // int o; o=0;
        for(int i=1;i<=n;i++){
            if(!a1[i]){
                continue;
            }

           // o++;
            int ll,rr; ll=1,rr=m;
            int near; near=-1;

            while(ll<=rr){
                int mid; mid=ll+rr>>1;
                if(p[mid]<d[i]){
                    ll=mid+1;
                    near=mid;
                }
                else{
                    rr=mid-1;
                }
            }

            ld l=p[near]-1,r=far+1;
            ld bound; bound=l;
            int L,R;

            if(a[i]<0){
                while(r-l>=eps){
                    ld mid; mid=(l+r)/2.0;

                    if(calc(v[i],a[i],mid-d[i])>V){
                        l=mid+eps;
                        bound=mid;
                    }
                    else{
                        r=mid-eps;
                    }
                }

                L=near;

                ll=1,rr=m+1;

                while(ll<=rr){
                    int mid; mid=ll+rr>>1;
                    ld tmp; tmp=p[mid]*1.0;
                    if(tmp-bound<eps){
                        ll=mid+1;
                    }
                    else{
                        rr=mid-1;
                        R=mid;
                    }
                }

                //cout<<bound<<endl;
                //cout<<"*"<<i<<" "<<L<<" "<<R<<endl;
            }
            else{
                while(r-l>=eps){
                    //cout<<l<<" "<<r<<"lr"<<endl;
                    ld mid; mid=(l+r)/2.0;
                    //cout<<mid<<" "<<calc(v[i],a[i],mid-d[i])<<endl;

                    if(calc(v[i],a[i],mid-d[i])>V){
                        r=mid-eps;
                        bound=mid;
                    }
                    else{
                        l=mid+eps;
                    }
                }

                //cout<<l<<" "<<r<<" "<<bound<<endl;
                R=m; L=m;
                ll=1,rr=m;
                //cout<<bound<<endl;
                while(ll<=rr){
                    int mid; mid=ll+rr>>1;
                    ld tmp; tmp=p[mid]*1.0;
                    if(bound-tmp<eps){
                        rr=mid-1;
                    }
                    else{
                        ll=mid+1;
                        L=mid;
                    }
                }

                //cout<<i<<" "<<L<<" "<<R<<endl;
            }

            //cout<<"bound:"<<bound<<endl;
            q.push({L,R-1});/*
            cout<<i<<" "<<L<<" "<<R<<endl;
            cout<<calc(v[i],a[i],p[L]-d[i])<<" "<<calc(v[i],a[i],p[R-1]-d[i])<<endl;
            if(p[L-1]>=d[i] && calc(v[i],a[i],p[L-1]-d[i])-V>eps){
                cout<<a[i]<<" WrongL:";
                cout<<p[L-1]<<" "<<calc(v[i],a[i],p[L-1]-d[i])<<endl;
            }

            if(R+1<=m && calc(v[i],a[i],p[R+1]-d[i])-V>eps){
                cout<<a[i]<<" WrongR:";
                cout<<p[R+1]<<" "<<calc(v[i],a[i],p[R+1]-d[i])<<endl;
            }*/
        }

        //cout<<o<<" "<<q.size()<<endl;

        int ans2; ans2=0;
        if(!q.empty()){
            int nl,nr; nl=q.top().l,nr=q.top().r;
            while(!q.empty()){
                nn x=q.top(); q.pop();

                //cout<<"x:"<<x.l<<" "<<x.r<<endl;
                //cout<<nl<<" "<<nr<<endl;

                if(x.l<=nr && x.r>=nl){
                    nl=max(x.l,nl),nr=min(nr,x.r);
                }
                else{
                    ans2++;
                    nl=x.l,nr=x.r;
                }
            }
        }

        cout<<m-ans2-1<<endl;
    }
    return 0;
}
