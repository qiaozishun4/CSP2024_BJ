#include<bits/stdc++.h>
using namespace std;
int t;
struct r{
    int way,vt,sum;
    long double ans;
};vector<int>less_ans[100010];
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>t;
    for(int i=0;i<t;i++){
        int lessest=0;
        int n,m,l,v,num_sum=0;
        r a[100010]={};
        bool vis[100010]={};
        int cnt[100010]={};
        cin>>n>>m>>l>>v;
        for(int j=1;j<=n;j++){
            cin>>a[j].way>>a[j].vt>>a[j].sum;
            if(a[j].sum!=0)a[j].ans=a[j].way+1.0*(v*v-a[j].vt*a[j].vt)/(2*a[j].sum);
            else a[j].ans=-1;
        }for(int j=1;j<=m;j++){
            cin>>cnt[j];
        }for(int j=1;j<=n;j++){
            if(a[j].ans==-1){
                if(a[j].vt>v){
                    num_sum++;
                    int l=1,r=m,mid,answer=0;
                    bool tmp=false;
                    while(l<=r){
                        mid=(l+r)>>1;
                        if(cnt[mid]<a[j].way){
                            l=mid+1;
                            answer=mid;
                        }else if(cnt[mid]>a[j].way){
                            r=mid-1;
                        }else{
                            less_ans[mid].push_back(j);
                            tmp=true;
                            break;
                        }
                    }if(tmp)continue;
                    for(int w=answer+1;w<=m;w++){
                        less_ans[w].push_back(j);
                    }
                }continue;
            }else if(a[j].sum<0){
                int l=1,r=m,mid,answer=0;
                bool tmp=false;
                while(l<=r){
                    mid=(l+r)>>1;
                    if(cnt[mid]<a[j].way){
                        l=mid+1;
                        answer=mid;
                    }else if(cnt[mid]>a[j].way){
                        r=mid-1;
                    }else{
                        less_ans[mid].push_back(j);
                        tmp=true;
                        num_sum++;
                        break;
                    }
                }if(tmp)continue;
                int l1=1,r1=m,answer1=0;
                while(l1<=r1){
                    mid=(l1+r1)>>1;
                    if(cnt[mid]<=a[j].ans){
                        l1=mid+1;

                    }else{
                        r1=mid-1;
                        answer1=mid;
                    }
                }if(answer+1==answer1||answer1==0)continue;
                num_sum++;
                for(int w=answer+1;w<answer1;w++){
                    less_ans[w].push_back(j);
                }

        }else{
                int l=1,r=m,mid,answer=0;
                while(l<=r){
                    mid=(l+r)>>1;
                    if(cnt[mid]>a[j].way){
                        r=mid-1;
                        answer=mid;
                    }else if(cnt[mid]<=a[j].way){
                        l=mid+1;
                    }
                }if(a[j].way>=cnt[m])continue;
                else{
                    num_sum++;
                    for(int w=answer+1;w<=m;w++){
                        less_ans[w].push_back(j);
                    }
                }
            }
        }for(int j=1;j<=m;j++){
                int decide_pop=less_ans[j].size();
                if(decide_pop==n){lessest=m-1;break;}
                int sum_pop=0;
                while(less_ans[j].size()>0){

                    if(vis[less_ans[j].back()]!=true){
                        vis[less_ans[j].back()]=true;
                    }else{
                        sum_pop++;
                    }less_ans[j].pop_back();
                }if(sum_pop==decide_pop)lessest++;
            }
        cout<<num_sum;
        cout<<lessest<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}