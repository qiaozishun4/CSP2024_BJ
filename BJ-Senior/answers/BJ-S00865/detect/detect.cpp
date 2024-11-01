//PASS
#include <bits/stdc++.h>
#define int long long
using namespace std;
const double eps=1e-6;
int n,m,l,v;
struct Car{
    int d,v,a;
}a[111111];
struct Node{
    int l,r;
};//每辆车被摄像头看到的区间
int b[111111];
double calleavetime(Car x){
    if(x.a>=0)return 1e9;
    double t=x.v*1.0/(-x.a);
    return t;
}
double calpos(Car x,double t){
    return min(x.d+t*x.v+0.5*t*t*x.a,(double)(l));
}
double calspeed(Car x,double pos){
    pos-=x.d;
    return sqrt(x.v*x.v+2*x.a*pos);
}
bool judge(Car x,double y){//x是否被y位置的摄像头拍到超速
    double leavepos=calpos(x,calleavetime(x));
    if(!(y+eps>=x.d&&y<=leavepos+eps))return 0;
    return calspeed(x,y)>v;
}
bool cmp(Node x,Node y){
    return x.r<y.r;
}
int solve(vector<Node> vv){//选择关闭哪些摄像头
    sort(vv.begin(),vv.end(),cmp);
    int ret=0,lst=-1;
    for(int i=0;i<vv.size();i++){
        if(vv[i].l>lst){
            lst=vv[i].r;
            ret++;
        }
    }
    return m-ret;
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int ttt;
    cin>>ttt;
    while(ttt--){
        cin>>n>>m>>l>>v;
        for(int i=1;i<=n;i++){
            cin>>a[i].d>>a[i].v>>a[i].a;
        }
        for(int i=1;i<=m;i++){
            cin>>b[i];
        }
        sort(b+1,b+m+1);
        int ans1=0;
        vector<Node> vv;
        for(int i=1;i<=n;i++){
            //cout<<"Car "<<i<<": ";
            /*int mn=1e9,mx=-1;
            for(int j=1;j<=m;j++){
                if(judge(a[i],b[j])){
                    mn=min(mn,j);
                    mx=max(mx,j);
                }
            }
            if(mn!=1e9){
                ans1++;
                v.push_back({mn,mx});
            }*/
            int mn,mx;
            double s=a[i].d,t=calpos(a[i],calleavetime(a[i]));//本辆车进入，离开位置
            mn=lower_bound(b+1,b+m+1,s)-b;
            mx=upper_bound(b+1,b+m+1,t)-b-1;
            //cout<<"Enter: "<<s<<"("<<mn<<") Exit: "<<t<<"("<<mx<<") Spotted section:cams No.[";
            if(lower_bound(b+1,b+m+1,s)==b+m+1||s>t){

            }
            else{
                int lt=mn,rt=mx,ans=-1;
                if(a[i].a>0){//FFFFTTTT
                             //    ^
                    while(lt<=rt){
                        int mid=(lt+rt)/2;
                        if(judge(a[i],b[mid])){
                            ans=mid;
                            rt=mid-1;
                        }
                        else{
                            lt=mid+1;
                        }
                    }
                    if(ans!=-1){
                        vv.push_back({ans,mx});
                        //cout<<ans<<","<<mx<<"]";
                        ans1++;
                    }
                }
                else{ //TTTTFFFFF
                      //   ^
                    while(lt<=rt){
                        int mid=(lt+rt)/2;
                        if(judge(a[i],b[mid])){
                            ans=mid;
                            lt=mid+1;
                        }
                        else{
                            rt=mid-1;
                        }
                    }
                    if(ans!=-1){
                        vv.push_back({mn,ans});
                        //cout<<mn<<","<<ans<<"]";
                        ans1++;
                    }
                }
            }
            //cout<<"\n";
        }
        cout<<ans1<<" "<<solve(vv)<<"\n";
    }
    return 0;
}
/*
diff detect1.out detect1.ans
diff detect2.out detect2.ans
diff detect3.out detect3.ans
diff detect4.out detect4.ans
diff detect5.out detect5.ans

*/
