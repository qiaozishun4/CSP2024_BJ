#include<bits/stdc++.h>
using namespace std;
struct gs{
    int a,b,c,d;
}r[100000];
bool cmp(gs x,gs y){
    if(x.a!=y.a) return x.a<y.a;
    return x.b<y.b;
}
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>r[i].a; //攻击力&防御力
        r[i].b=i; //序号
        r[i].c=0; //是否攻击
        r[i].d=1; //是否在场
    }
    sort(r,r+n,cmp);
    // for(int i=0;i<n;i++) cout<<r[i].a<<" ";
    // for(int i=0;i<n;i++) cout<<r[i].b<<" ";
    // for(int i=0;i<n;i++) cout<<r[i].c<<" ";
    // for(int i=0;i<n;i++) cout<<r[i].d<<" ";
    bool f=1;
    int sum=n;
    while(f==1){
        f=0;
        bool gc=0;
        for(int i=1;i<n;i++){
            for(int j=i-1;j>=0;j--){
                if(r[i].d==1 && r[j].d==1){
                    if(r[j].a<r[i].a && r[i].c==0 && (j==0 || r[j].a!= r[j-1].a || r[j-2].d==0)){
                        gc=1;
                        sum--;
                        r[j].d=0;
                        r[i].c=1;
                        break;
                    }
                }

            }
        }
        for(int i=0;i<n;i++){
            if(r[i].d==1 && r[i].c==0){
                f=1;
                break;
            }
        }
        // for(int i=0;i<n;i++) cout<<r[i].a<<" ";
        // cout<<endl;
        // for(int i=0;i<n;i++) cout<<r[i].b<<" ";
        // cout<<endl;
        // for(int i=0;i<n;i++) cout<<r[i].c<<" ";
        // cout<<endl;
        // for(int i=0;i<n;i++) cout<<r[i].d<<" ";
        // cout<<endl<<endl;
        if(!gc) break;
        
    }
    cout<<sum;
    return 0;
}