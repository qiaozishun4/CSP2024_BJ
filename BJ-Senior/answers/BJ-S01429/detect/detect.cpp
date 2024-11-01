#include<bits/stdc++.h>
using namespace std;
int t,n,m,l,v;
struct car{
    int d,v,a;
    double tgt;
} a[100005];
int cs[100005];
bool cmp(vector<int> x,vector<int> y){
    return x.size()>y.size();
}
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n>>m>>l>>v;
        vector<int> ablt[100005];
        for(int i=1;i<=n;i++){
            cin>>a[i].d>>a[i].v>>a[i].a;
        }
        for(int i=1;i<=m;i++){
            cin>>cs[i];
        }
        int c=0;
        for(int i=1;i<=n;i++){
            if(a[i].a!=0){
                a[i].tgt=a[i].d+(v*v-a[i].v*a[i].v)/(2.0*a[i].a);
            }
            else if(a[i].v<=v){
                a[i].tgt=1.0/0.0;
            }
            else{
                a[i].tgt=a[i].d;
            }
            if(a[i].a>=0){
                int cc=0;
                int l=upper_bound(cs+1,cs+1+m,a[i].tgt)-cs,r=m;
                for(int j=l;j<=r;j++){
                    ablt[j].push_back(i);
                    cc=1;
                }
                c+=cc;
            }
            else{
                int cc=0;
                int l=lower_bound(cs+1,cs+1+m,a[i].d)-cs,r=upper_bound(cs+1,cs+1+m,a[i].tgt)-cs-1;
                for(int j=l;j<=r;j++){
                    ablt[j].push_back(i);
                    cc=1;
                }
                c+=cc;
            }
        }
        cout<<c<<" ";
        int x[100005]={},usls=0;
        sort(ablt+1,ablt+1+m,cmp);
        for(int i=1;i<=m;i++){
            bool iu=false;
            for(int j=0;j<ablt[i].size();j++){
                if(x[ablt[i][j]]==0){
                    iu=true;
                }
                x[ablt[i][j]]=1;
            }
            if(iu==false){
                usls++;
            }
        }
        cout<<usls<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
