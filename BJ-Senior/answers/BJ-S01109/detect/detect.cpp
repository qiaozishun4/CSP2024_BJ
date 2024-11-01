#include <bits/stdc++.h>
using namespace std;
struct st{
    int st,ed;
}ze[100050];
bool cmp(st a,st b){
    if(a.st==b.st) return a.ed<b.ed;
    return a.st<b.st;
}
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long n,m,l,v,t,v0[100050],a[100050];
    int cs[1000050],p[100050],d[100050],st[100050],ed[100050];
    cin>>t;
    while(t--){
        cin>>n>>m>>l>>v;
        for(int i=1;i<=n;i++){
            cin>>d[i]>>v0[i]>>a[i];
        }
        for(int i=1;i<=m;i++){
            cin>>p[i];
            for(int j=p[i-1];j<=p[i]-1;j++){
                cs[j]=i-1;
            }
        }
        for(int j=p[m]-1;j<=l;j++){
            cs[j]=m;
        }
        int cnt=0;
        for(int i=1;i<=n;i++){
            if(a[i]==0){
                if(v0[i]>v){
                    if(cs[d[i]]!=cs[d[i]-1]){
                        cnt++;
                        st[cnt]=cs[d[i]];
                        ed[cnt]=m;
                    }else if(cs[d[i]]!=m){
                        cnt++;
                        st[cnt]=cs[d[i]]+1;
                        ed[cnt]=m;
                    }
                }
            }else if(a[i]>0){
                long long fini;
                if(v0[i]>v){
                    fini=d[i];
                }else{
                    fini=d[i]+(v*v-v0[i]*v0[i])/(2*a[i])+1;
                }
                if(fini<=l){
                    if(cs[fini]!=cs[fini-1]){
                        cnt++;
                        st[cnt]=cs[fini];
                        ed[cnt]=m;
                    }else if(cs[fini]!=m){
                        cnt++;
                        st[cnt]=cs[fini]+1;
                        ed[cnt]=m;
                    }
                }
            }else{
                if(v0[i]>v){
                    long long fini=d[i]+(v*v-v0[i]*v0[i])/(2*a[i])-((v*v-v0[i]*v0[i])%(2*a[i])==0?1:0);
                    //cout<<"==="<<fini<<"==="<<d[i]<<endl;
                    if(fini>l){
                        fini=l;
                    }
                        if(cs[d[i]]!=cs[d[i]-1]){
                            cnt++;
                            st[cnt]=cs[d[i]];
                            ed[cnt]=cs[fini];
                        }else if(cs[fini]!=cs[d[i]]){
                            cnt++;
                            st[cnt]=cs[d[i]]+1;
                            ed[cnt]=cs[fini];
                        }
                }
            }
        }
        cout<<cnt<<" ";
        int ans=1;
        for(int i=1;i<=cnt;i++){
            //cout<<st[i]<<" "<<ed[i]<<endl;
            ze[i].ed=ed[i];
            ze[i].st=st[i];
        }
        sort(ze+1,ze+1+cnt,cmp);
        //cout<<ze[1].st<<" "<<ze[1].ed<<endl;
        for(int i=2;i<=cnt;i++){
           //cout<<ze[i].st<<"=="<<ze[i].ed<<endl;
            if(ze[i].st<=ze[i-1].ed){
                ze[i].ed=min(ze[i-1].ed,ze[i].ed);
            }else{
                ans++;
            }
        }
        //cout<<endl;
        cout<<m-ans<<endl;
    }
}

