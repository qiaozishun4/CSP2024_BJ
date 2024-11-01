#include<bits/stdc++.h>
using namespace std;
int t,d[100005],a[100005],p[100005],road[1000005];
long long v[100005];
priority_queue < pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > qe;
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>t;
    for(int q = 0;q<t;q++){
        for(int i = 0;i<qe.size();i++)   qe.pop();
        long long n,m,l,mv;
        cin>>n>>m>>l>>mv;
        for(int i = 1;i<=n;i++){
            cin>>d[i]>>v[i]>>a[i];
        }
        int maxp = 0;
        int minp = 2000000000;
        for(int i = 1;i<=m;i++){
            cin>>p[i];
            maxp = max(maxp,p[i]);
            minp = min(minp,p[i]);
        }
        int x = 1;
        for(int i = 0;i<=1000005;i++)   road[i] = -1;
        for(int i = 0;i<l;i++){
            if(p[x]>=i){
                if(x<=m)   road[i] = x;
            }
            else{
                x++;
                if(x<=m)   road[i] = x;
            }
        }
        int ans = 0;
        int mxl = 0;
        //for(int i = 1;i<=n;i++)   ck[i][0] = -1,ck[i][1] = -1;
        for(int i = 1;i<=n;i++){
            if(a[i]>0){
                if((mv*mv-v[i]*v[i])<(2*a[i]*maxp-2*a[i]*d[i])&&road[d[i]]!=-1){
                    ans++;
                    //<<(mv*mv-v[i]*v[i])/2/a[i]+1;
                    if(mv>v[i])   mxl = max(mxl,road[(mv*mv-v[i]*v[i])/2/a[i]+1]);
                    else   mxl = max(mxl,road[d[i]]);
                    //ck[i][0] = road[(mv*mv-v[i]*v[i])/2/a[i]+1];
                    //ck[i][1] = m;
                }
            }
            else if(a[i]==0){
                if(mv<v[i]&&road[d[i]]!=-1){
                    ans++;
                    mxl = max(mxl,road[d[i]]);
                    //[i][0] = road[d[i]];
                    //k[i][1] = m;
                }
            }
            else{
                if((mv*mv-v[i]*v[i])<(2*a[i]*p[road[d[i]]]-2*a[i]*d[i])&&road[d[i]]!=-1){
                    ans++;
                    if(road[d[i]+(mv*mv-v[i]*v[i])/2/a[i]+1]==-1)   qe.push({m,road[d[i]]});
                    else   qe.push({road[d[i]+(mv*mv-v[i]*v[i])/2/a[i]-1]-1,road[d[i]]});
                }
            }
        }
        cout<<ans<<" ";
        //if(n>3000||m>3000){
         //   if(a[1]==0){
         //       if(ans == 0)   cout<<m<<endl;
         //       else   cout<<m-1<<endl;
        //    }
        //    else if(a[1]>0){
        //        if(ans == 0)   cout<<m<<endl;
         //       else   cout<<m-1<<endl;
        //    }
        //}
        //else{
            int ans2 = 0;
            int mx = 0;
            //cout<<endl;
            while(!qe.empty()){
                int r = qe.top().first,l = qe.top().second;
                //cout<<l<<" "<<r<<endl;
                ans2++;
                qe.pop();
                mx = max(mx,r);
                if(qe.top().second<=r&&!qe.empty())   while(qe.top().second<=r&&!qe.empty()){
                        //cout<<qe.top().second<<" "<<qe.top().first<<endl;
                    qe.pop();
                }
            }
            //cout<<mxl;
            if(mx<mxl)   ans2++;
            cout<<m-ans2<<endl;
        //}
        //else{
         //   int u = 0;
           // u+=n-ans;
          //  int ans2 = 0;
          //  while(u<n){
          //      int mn = 2000000000;
          //      for(int i = 1;i<=n;i++){
          //          if(ck[i][1]!=-1)   mn = min(mn,ck[i][1]);
         //       }
          //      ans2++;
          //      for(int i = 1;i<=n;i++){
          //          if(ck[i][0]<=mn&&mn<=ck[i][1]&&ck[i][1]!=-1&&ck[i][0]!=-1){
          //              ck[i][1]=-1;
           //             u++;
           //         }
           //     }
         //   }
         //   cout<<m-ans2<<endl;
        //}
    }
    return 0;
}