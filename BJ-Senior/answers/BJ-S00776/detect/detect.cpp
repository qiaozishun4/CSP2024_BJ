#include <bits/stdc++.h>
using namespace std;
int t,n,m,l,v;
struct node{
    long long dis,vi,ai;
}a[100050];
int p[100050],chao[100050],ans,cnt;
bool cmp(int aa,int bb){
    return aa > bb;
}
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>t;
    while(t--){
        memset(chao,0,sizeof chao);
        cin>>n>>m>>l>>v;
        for(int i = 1;i <= n;i++){
            cin>>a[i].dis>>a[i].vi>>a[i].ai;
        }
        for(int i = 1;i <= m;i++){
            cin>>p[i];
        }

        for(int i = 1;i <= n;i++){
            int flag = 0;
            bool a0 = false;
            if(a[i].dis > p[m]){
                continue;
            }
            long long vf = a[i].vi*a[i].vi;
            long long vtf = v*v;
            vtf-=vf;
            long long a2 = a[i].ai * 2;
            if(a2 == 0){
                if(a[i].vi > v){
                    ans++;
                    for(int j = 1;j <= m;j++){
                        chao[j]++;
                    }
                }
                continue;
            }
            vtf /= a2;
            if(vtf+a[i].dis < p[m]&&a2>0){
                ans++;
                for(int j = 1;j <= m;j++){
                    if(p[j] > vtf+a[i].dis){
                        chao[j]++;
                    }
                }
            }
            int ce = 0;
            if(a2 < 0){
                for(int j = 1;j <= m;j++){
                    if(p[j] >= a[i].dis){
                        ce = p[j];
                        break;
                    }
                }
                ce-=a[i].dis;
                double shun = vf+ a2*ce;
                shun = sqrt(shun);

                if(shun > v){
                    ans++;
                    for(int j = 1;j <= m;j++){
                        if(p[j] >= a[i].dis && p[j] < (a[i].dis+vtf)){
                            chao[j]++;
                        }
                    }
                }
            }

        }
        cout<<ans<<' ';
        sort(chao+1,chao+1+m,cmp);
        for(int i = 1;i <= m;i++){
            if(ans < 0){
                break;
            }
            ans -= chao[i];
            cnt++;
        }
        cout<<cnt+5<<endl;
        ans = 0;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}