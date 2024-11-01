#include<bits/stdc++.h>
using namespace std;
int n, m, L, V;
int d[100010], v[100010], a[100010];
int p[100010];
int main(){
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    int t;
    cin>>t;
    while(t--){
        int ans1=0, ans2=0;
        cin>>n>>m>>L>>V;
        for(int i=0;i<n;i++){
            cin>>d[i]>>v[i]>>a[i];
        }
        for(int i=1;i<=m;i++){
            cin>>p[i];
        }
        for(int i=0;i<n;i++){
            if(d[i]<=p[m]){
                if(sqrt(v[i]*v[i]+2*a[i]*(p[m]-d[i]))>(double)V){
                    ans1++;
                }
            }
        }
        cout<<ans1<<" "<<m-1<<endl;
    }
    return 0;
}
/*
#include<bits/stdc++.h>
using namespace std;
struct duan{
    double left, right;
};
int n, m, L, V;
int d[100010], v[100010], a[100010];
int p[100010];
duan x[100010];
int numx;
bool cmp(duan aa, duan bb){
    if(aa.right==bb.right) return aa.left<bb.left;
    return aa.right<bb.right;
}
int main(){
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    int t;
    cin>>t;
    while(t--){
        numx=0;
        int ans1=0, ans2=0;
        cin>>n>>m>>L>>V;
        for(int i=0;i<n;i++){
            cin>>d[i]>>v[i]>>a[i];
        }
        for(int i=1;i<=m;i++){
            cin>>p[i];
        }
        p[0]=-1;
        p[m+1]=L+1;
        for(int i=0;i<n;i++){
            if(a[i]==0&&v[i]>V){
                x[numx].left=d[i];
                x[numx].right=L;
                numx++;
            }else if(a[i]>0){
                x[numx].left=d[i]+((double)V*V-(double)v[i]*v[i])/(2.0*(double)a[i]);
                x[numx].right=(double)L;
                numx++;
            }else{
                if(v[i]>V){
                    x[numx].left=(double)d[i];
                    x[numx].right=d[i]+((double)V*V-(double)v[i]*v[i])/(2.0*(double)a[i]);
                    numx++;
                }
            }
        }
        sort(x, x+numx, cmp);
        int xxx=0;
        for(int i=0;i<numx;i++){
            cout<<x[i].left<<" "<<x[i].right<<endl;
            if((double)p[xxx]>=x[i].left&&(double)p[xxx]<=x[i].right){
                ans1++;
            }else{
                int bt=xxx;
                // cout<<"!!!\n";
                while((double)p[xxx+1]<=x[i].right){
                    xxx++;
                }
                // cout<<p[xxx]<<endl;
                if((double)p[xxx]>=x[i].left&&(double)p[xxx]<=x[i].right){
                    // cout<<"###\n";
                    ans1++;
                    ans2++;
                }else{
                    xxx=bt;
                }
            }
            
        }
        cout<<ans1<<" "<<m-ans2<<endl;
    }
    return 0;
}
*/