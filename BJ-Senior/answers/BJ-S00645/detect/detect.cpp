#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
int n,m,L,V;
int d[100010],v[100010],a[100010];
int p[100010];
int sum[1000010];
long double L_[100010],R_[100010];
int up(long double x){
    int tmp=x;
    if(x>tmp){
        return tmp+1;
    }
    else{
        return tmp;
    }
}
set<int> need;
bool C[30];
int dfs(int x){
    if(x==m+1){
        for(int i=1;i<=n;i++){
            if(need.find(i)==need.end()){
                continue;
            }
            bool flag=0;
            for(int j=1;j<=m;j++){
                if(!C[j]){
                    continue;
                }
                if(p[j]>=L_[i]&&p[j]<=R_[i]){
                    //cout << i << "," << j << endl;
                    flag=1;
                    break;
                }
            }
            if(!flag){
                return 0;
            }
        }
        int bac=0;
        for(int i=1;i<=m;i++){
            //cout << C[i] << " ";
            if(!C[i]){
                bac++;
            }
        }
        //cout << ",";
        //cout << endl;
        return bac;
    }
    C[x]=0;
    int bac=dfs(x+1);
    C[x]=1;
    return max(bac,dfs(x+1));
}
signed main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        memset(sum,0,sizeof(sum));
        memset(L_,0,sizeof(L_));
        memset(R_,0,sizeof(R_));
        need.clear();
        cin >> n >> m >> L >> V;
        bool flag=1;
        for(int i=1;i<=n;i++){
            cin >> d[i] >> v[i] >> a[i];
            if(a[i]==0){
                if(v[i]>V){
                    L_[i]=d[i];
                    R_[i]=L;
                }
                else{
                    L_[i]=1e9;
                }
            }
            else if(a[i]>0){
                if(v[i]>V){
                    L_[i]=d[i];
                    R_[i]=L;
                }
                else{
                    L_[i]=d[i]+0.0001+(long double)(1)*(V*V-v[i]*v[i])/(2*a[i]);
                    R_[i]=L;
                    if(L_[i]>L){
                        L_[i]=1e9;
                    }
                }
            }
            else{
                flag=0;
                if(v[i]>V){
                    L_[i]=d[i];
                    R_[i]=min((long double)L,d[i]+(long double)(1)*(V*V-v[i]*v[i])/(2*a[i])-0.0001);
                }
                else{
                    L_[i]=1e9;
                }
            }
            //cout << L_[i] << " " << R_[i] << endl;
        }//cout << endl;
        for(int i=1;i<=m;i++){
            cin >> p[i];
            sum[p[i]]=1;
        }
        for(int i=1;i<=L;i++){
            sum[i]+=sum[i-1];
        }

        int ans1=0;
        for(int i=1;i<=n;i++){
            if(L_[i]>L||R_[i]<0){
                continue;
            }

            if(L_[i]==0){
                if(sum[(int)R_[i]]){
                    //cout << up(L_[i]) << " " << (int)R_[i] << endl;
                    //cout << i << endl;
                    ans1++;
                    need.insert(i);
                }
            }
            else if(sum[(int)R_[i]]-sum[(int)ceil(L_[i])-1]>0){
                //cout << up(L_[i]) << " " << (int)R_[i] << endl;
                need.insert(i);
                //cout << i << endl;
                ans1++;
            }
        }
        //cout << up(L_[4]) << " " << (int)R_[4] << endl;
        cout << ans1 << " ";
        if(m<=20){
            cout << dfs(1) << endl;
            continue;
        }
        if(flag){
            if(ans1==0){
                cout << m << endl;
            }
            else{
                cout << m-1 << endl;
            }
            continue;
        }

    }
    return 0;
}
