#include<bits/stdc++.h>
using namespace std;
int T,n,m,L,V,sck[100005],spdck[1000005],num,tp,pt[1000005],w,ans,ct;
struct car{
    int d;
    int v;
    int a;
    int zz;//chaosu->begin to buchaosu || buchaosu->begin to chaosu's time, -1:in->out meichaosu
}cars[100005];
pair<int,int>qj[100005],bd[1000005];
void calcv(int x){
    double b;
    if(cars[x].a>0){
        if(cars[x].v>V)cars[x].zz=L;
        else if(cars[x].v==V)cars[x].zz=cars[x].d+1;
        else {
            b=((V*V*1.0)-(cars[x].v*cars[x].v*1.0))/(cars[x].a*2.0);
            if(b+cars[x].v<=L)cars[x].zz=ceil(b)+cars[x].d;
            else cars[x].zz=-1;
        }
    }
    else if(cars[x].a==0){
        if(cars[x].v>V)cars[x].zz=L;
        else cars[x].zz=-1;
    }
    else {
        if(cars[x].v<=V)cars[x].zz=-1;
        else{
            b=((V*V*1.0)-(cars[x].v*cars[x].v*1.0))/(cars[x].a*2.0);
            int c=ceil(b);
            cars[x].zz=min(c+cars[x].d,L+1);
        }
    }
    return;
}
int main(){
    //freopen("detect.in","r",stdin);
    //freopen("detect.out","w",stdout);
    cin>>T;
    while(T--){
        num=0;
        w=1;
        tp=0;
        ans=0;
        cin>>n>>m>>L>>V;
        for(int i=1;i<=n;i++){
            cin>>cars[i].d>>cars[i].v>>cars[i].a;
        }
        for(int i=1;i<=m;i++){
            cin>>sck[i];
        }
        for(int i=1;i<=L+2;i++){
            spdck[i]=spdck[i-1];
            if(i==sck[w]){
                w++;
                spdck[i]++;
            }
        }
        for(int i=1;i<=n;i++){
            calcv(i);
            if(cars[i].a<0 && cars[i].zz==L){
                num++;
                continue;
            }
            if(cars[i].a>0 && cars[i].zz!=-1){
                if(spdck[cars[i].zz]<spdck[L]){
                    num++;
                    qj[++tp].first=cars[i].zz;
                    qj[tp].second=L;
                }
            }
            else if(cars[i].a==0 && cars[i].zz!=-1){
                if(spdck[cars[i].d]<spdck[L]){
                    num++;
                    qj[++tp].first=cars[i].d;
                    qj[tp].second=L;
                }
            }
            else if(cars[i].zz!=-1){
                if(spdck[cars[i].d]<spdck[cars[i].zz-1]){
                    num++;
                    qj[++tp].first=cars[i].d;
                    qj[tp].second=cars[i].zz-1;
                    //cout<<num<<endl;//test
                }
            }
            //cout<<num<<' ';//test
        }
        //cout<<endl;//test
        //for(int i=1;i<=n;i++){//test
        //    cout<<i<<' '<<cars[i].zz<<endl;
        //}
        cout<<num<<endl;
        sort(qj+1,qj+tp+1);
        for(int i=1;i<=tp;i++){
            pt[qj[tp].first]++;
            pt[qj[tp].second]--;
        }
        int contin=0;
        bd[++ct].first=1;
        for(int i=1;i<=L;i++){
            pt[i]+=pt[i-1];
            if(pt[i-1]==pt[i])contin++;
            if(pt[i]>pt[i-1] && pt[i-1]<=pt[i-2]){
                bd[ct].second=i-1;
                bd[++ct].first=i;
            }
            else if(pt[i]<pt[i-1]&& pt[i-1]>=pt[i-2]){
                bd[ct].second=i-1;
                bd[++ct].first=i-1-contin;
            }
            if(pt[i-1]!=pt[i])contin=0;
        }
        bd[ct].second=L;
        for(int i=1;i<=ct;i++){
            ans+=max(0,spdck[bd[i].second]-spdck[bd[i].first-1]-1);
            //cout<<bd[i].first<<' '<<bd[i].second<<endl;
        }
        cout<<ans<<endl;
        for(int i=1;i<=L+2;i++)spdck[i]=0;
    }
    return 0;
}
