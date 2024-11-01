#include<bits/stdc++.h>
using namespace std;
const int N=2e5+2;
const int S=1e6+2;
int a[N];
int sta[S];
bool color[N];
vector<int> buct[S];
bool cmp(int a,int b){
    return a<b;
}
int Find(int l,int r,int x,int k){
    //cout<<"l:"<<l<<" r:"<<r<<" x:"<<x<<" k:"<<k<<endl;
    if(k<=0||l>r){
        //cout<<"end:"<<endl;
        return 0;
    }
    if(x<=0){
        return 0;
    }
    int lqj=max(buct[x][0],l),rqj=min(buct[x][buct[x].size()-1],r);
    color[lqj]=1;   
    int pre=lqj;
    int mp=lqj;
    int ans=0,fl=1,tk=k;
    //cout<<"ok!!"<<endl;
    //cout<<"!!"<<sta[tk]<<endl;
    //cout<<"buct:"<<buct[sta[tk]][0]<<endl;
    while(buct[sta[tk]][0]>=mp){
        tk--;
        if(!tk){
            fl=0;
        }
        //cout<<"tk:"<<tk<<endl;
    }
    //cout<<"tk:"<<tk<<endl;
    if(fl)ans+=Find(l,buct[x][0]-1,sta[tk],tk-1);
    for(int j=1;j<buct[x].size();j++){
        //cout<<"ok"<<endl;
        if(buct[x][j]>r){
            break;
        }
        if(buct[x][j]<l){
            continue;
        }
        ans+=x;
        color[buct[x][j]]=1;
        pre=mp;
        mp=buct[x][j];
        for(int i=pre+1;i<mp;i++){
            if(a[i]==a[i-1]){
                ans+=a[i];
                }
            }
        }
        //cout<<"ok1"<<endl;
        while(buct[sta[k]][buct[sta[k]].size()-1]<=mp){
            k--;
            if(!k){
                return ans;
            }
        }
        //cout<<"k"<<k<<endl;`
    ans+=Find(buct[x][buct[x].size()-1],r,sta[k],k-1);
    //cout<<"ans:"<<ans<<endl;
    return ans;
}
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        //cout<<"T:"<<T<<endl;
        memset(color,0,sizeof(color));
        memset(buct,0,sizeof(buct));
        int n;
        cin>>n;
        int ans=0;
        int max1=0;
        int k=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            if(buct[a[i]].empty()){
                //cout<<"a[i]"<<a[i]<<endl;
                k++;
                //cout<<"k:"<<k<<endl;
                sta[k]=a[i];
            }
            buct[a[i]].push_back(i);
            if(a[i]>max1){
                max1=a[i];
            }
        }
        //cout<<"ok"<<endl;
        if(n==2){
            if(a[1]==a[2]){
                cout<<a[1]+a[2];
            }
            else cout<<0;
            continue;
        }
        //cout<<"ok1L"<<endl;
        sort(sta+1,sta+k,cmp);
        //cout<<"ok:"<<endl;
        //cout<<"k:"<<k<<endl;
        cout<<Find(1,n,max1,k-1)<<endl;
    }
    return 0;
}