#include<bits/stdc++.h>
using namespace std;
struct node{
    int d,u,a;
    bool flag=false,flag1=false;
}sum[100001];
vector<int>a[100001];
bool b[100001];
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        int sum1=0,sum2=0;
        int n,m,l,v;
        cin>>n>>m>>l>>v;
        for(int i=1;i<=m;i++){
            fill(a[i].begin(),a[i].begin()+a[i].size(),0);
        }
        for(int i=1;i<=n;i++){
            sum[i].flag=false;
            sum[i].flag1=false;
        }
        fill(b,b+n+1,0);
        for(int j=1;j<=n;j++){
            cin>>sum[j].d>>sum[j].u>>sum[j].a;
        }
        for(int j=1;j<=m;j++){
            int temp1;
            cin>>temp1;
            for(int k=1;k<=n;k++){
                if(sum[k].flag1)continue;
                if(sum[k].d>temp1)continue;
                else if(sum[k].d==temp1){
                    if(sum[k].u>v){
                        a[j].push_back(k);
                        if(sum[k].flag)continue;
                        sum[k].flag=true;
                        sum1++;
                    }
                }else{
                    int l=temp1-sum[k].d;
                    int temp=sum[k].u+l*sum[k].a;
                    if(temp<=0){
                        sum[k].flag1=true;
                        continue;
                    }
                    if(temp>v){
                        a[j].push_back(k);
                        if(sum[k].flag)continue;
                        sum[k].flag=true;
                        sum1++;
                    }
                }
            }
        }
        for(int i=m;i>0;i--){
            if(a[i].empty())sum2++;
            else{
                bool flag=false;
                for(int j=0;j<a[i].size();j++){
                    if(!b[a[i][j]]){
                        flag=true;
                        b[a[i][j]]=true;
                    }
                }
                if(!flag)sum2++;
            }
        }
        cout<<sum1<<" "<<sum2<<endl;
        fclose(stdin);
        fclose(stdout);
    }
    return 0;
}
