#include<iostream>
#include<vector>
#include<stack>
using namespace std;
int T;
double n,m,L,V;
double d[10001],v[10001],a[10001],p[10001];
vector<int> vec[100001];
int over[1000001];
int cnt[1000001];
stack<vector<int> >stk;
vector<vector<int> >vct;
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>T;
    while(T--){
        int ans1=0;
        cin>>n>>m>>L>>V;
        for(int i=1;i<=n;i++){
            cin>>d[i]>>v[i]>>a[i];
        }
        for(int i=1;i<=m;i++){
            cin>>p[i];
        }
        for(int i=1;i<=n;i++){
            int flag=0;
            if(v[i]>V&&a[i]>=0){
                for(int j=1;j<=m;j++){
                    if(p[j]>=d[i]){
                        vec[j].push_back(i);

                        flag=1;
                    }
                }
            }else if(v[i]>V&&a[i]<0){
                double fs=(V*V-v[i]*v[i])/(2*a[i]);
                for(int j=1;j<=m;j++){
                    if(p[j]>=d[i]&&p[j]<fs+d[i]){
                        vec[j].push_back(i);

                        flag=1;
                    }
                }
            }else if(v[i]==V&&a[i]>0){

                for(int j=1;j<=m;j++){
                    if(p[j]>d[i]){
                        vec[j].push_back(i);

                        flag=1;
                    }
                }
            }else if(v[i]==V&&a[i]<=0){
                continue;
            }else if(v[i]<V&&a[i]>0){
                double fs=(V*V-v[i]*v[i])/(2*a[i]);
                for(int j=1;j<=m;j++){
                    if(p[j]>fs+d[i]){
                        vec[j].push_back(i);

                        flag=1;
                    }
                }
            }else if(v[i]<V&&a[i]<=0){
                continue;
            }
            if(flag){
                ans1++;
                over[i]=1;
            }
        }

        cout<<ans1<<' ';
        int top=0;
        int bottom=0;
        for(int i=1;i<=m;i++){
            int cntmove=0;
            vct.push_back(vec[i]);
            bottom++;
            while(1){
                if(cntmove==bottom-top-1){
                    break;
                }
                    int newflag=0;
                for(int j=0;j<vct[top].size();j++){
                    if(over[vct[top][j]]==1&&cnt[vct[top][j]]-1<=0){
                        newflag=1;
                    }
                }
                if(newflag==0){
                    for(int j=0;j<=vct[top].size();j++){
                        over[vct[top][j]]--;
                    }
                    top=top+1;
                }else{
                    vct.push_back(vct[top]);
                    bottom++;
                    top=top+1;
                    cntmove++;
                }
            }
            if(i==m&&cntmove==bottom-top-1){
                cout<<m-cntmove<<endl;
                break;
            }
        }
    }
    return 0;
}
