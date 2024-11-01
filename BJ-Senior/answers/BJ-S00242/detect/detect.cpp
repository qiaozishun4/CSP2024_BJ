#include <bits/stdc++.h>
using namespace std;
long long T,n,m,L,p[100005],d[100005],ans,t[1000005],an,a[100005],v[100005],V;
long double s;
bool l = false,z=false,cc = false;
long long ph=0;
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>T;
    for(int i = 0;i<T;i++){
        t[100005] = {0};
        ans = 0;
        an = 0;
        ph=0;
        cin>>n>>m>>L>>V;
        for(int j = 0;j<n;j++) cin>>d[j]>>v[j]>>a[j];
        for(int j = 0;j<m;j++) cin>>p[j];
        sort(p,p+m);
        for(int j = 0;j<n;j++){
            l = false;
            z = false;
            if(a[j]==0){
                if(v[j]>V&&p[m-1]>=d[j]){
                    ph++;
                    ans++;
                }
            }else s = (long double)(V*V-v[j]*v[j])/2/a[j];
            if(a[j]>0){
                if(p[m-1]>s+d[j])ans++;
                    //if(p[m-1]*a[j]*2+v[j]*v[j]>=V*V)ans++;
                /*for(int k = 0;k<m;k++){
                    if(p[k]>s+d[j]){
                        for(int h = k;h<m;h++){
                            l = true;
                            if(t[p[h]]!=0)z=true;
                            t[p[h]]++;
                        }
                        if(l)ans++;
                        if(z==false)an++;
                        break;
                    }
                }*/
            }else if(a[j]<0){


                for(int k = 0;k<m;k++){
                    if(p[k]>=d[j]&&p[k]<s+d[j])ans++;
                    break;
                }
                /*for(int k = 0;k<m;k++){
                    if(p[k]>=d[j]&&p[k]<s+d[j]){
                        l = true;
                        if(t[p[k]]!=0)z=true;
                        t[p[k]]++;
                    }
                }
                if(l)ans++;
                if(z==false&&l)an++;*/
            }
        }
        if(ph==ans)an++;
        if(ans == 0)an--;
        else an++;
        cout<<ans<<" "<<m-an<<endl;
    }
    return 0;
}
