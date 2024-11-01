#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5+7,maxm=1e5+7;
int n,m,L;
long double v;
int ans=-1;
int p[maxm];

vector<int> pv;

struct car{
    int d,v,a;
    long double cac(int x){
        if(d > x)
            return -2;
        long double k=double(v)*v+2*a*(x-d);
        if(k < 0)
            return -1;
        //cout<<"   []"<<a<<"      "<<x-d<<endl;
        return sqrt(k);
    }
}c[maxn];

int pfind(int x){
    int l=0,r=pv.size()-1;
    while(l < r){
        int mid=(l+r)/2;
        if(pv[mid] < x)
            l = mid+1;
        else
            r = mid;
        //cout<<"   "<<l<<endl;
    }
    return l;
}

int check(){  //how many
    if(pv.size() == 0)
        return 0;
    int cnt=0;
    for(int i=0;i<n;i++){
        if(c[i].a >= 0){
            if(c[i].cac(pv[pv.size()-1]) > v)
                cnt++;
        }
        else{
            int now=pfind(c[i].d);
            if(c[i].cac(pv[now]) > v)
                cnt++;
            //if(did  &&  i == 7)
            //cout<<now<<" "<<c[i].cac(pv[now])<<endl;
        }
        //if(did)
            //cout<<cnt<<endl;
    }
    return cnt;
}


void dfs(int ind,int num){  //for solve0
    if(ind >= m){
        //for(int i=0;i<pv.size();i++)
            //cout<<pv[i]<<" ";
        //cout<<endl;
        int cnt=check();
        if(cnt == num){
            ans = max(ans,int(m-pv.size()));
        }
        return;
    }
    pv.push_back(p[ind]);
    dfs(ind+1,num);
    pv.erase(pv.end()-1);
    dfs(ind+1,num);
    return;
}

void solve0(){
    for(int i=0;i<m;i++)
        pv.push_back(p[i]);
    int num=check();
    //cout<<"       "<<num<<endl;

    pv.clear();
    dfs(0,num);
    cout<<num<<" "<<ans<<endl;
    pv.clear();
    ans = -1;
    return;
}


void solveA(){
    for(int i=0;i<m;i++)
        pv.push_back(p[i]);
    int num=check();

    pv.clear();
    dfs(m-1,num);
    cout<<num<<" "<<ans<<endl;
    pv.clear();
    ans = -1;
    return;
}


int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int T;
    cin>>T;
    for(int t=0;t<T;t++){
        cin>>n>>m>>L>>v;
        bool flagA=true,flagB=true,flagC=true;
        for(int i=0;i<n;i++){
            cin>>c[i].d>>c[i].v>>c[i].a;
            if(c[i].a < 0)
                flagA = flagB = false;
            if(c[i].a > 0)
                flagA = flagC = false;
            if(c[i].a == 0)
                flagB = flagC = false;
        }
        for(int i=0;i<m;i++)
            cin>>p[i];

        if(n <= 20  &&  m <= 20)
            solve0();
        else if(flagA)
            solveA();
        else if(flagB)
            solveA();
        else
            solve0();
    }
    return 0;
}
