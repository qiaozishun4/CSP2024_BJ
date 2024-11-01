#include<bits/stdc++.h>

using namespace std;

int main(){
    freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int n,m,l,v,d[10001],v0[10001],a[10001],p[10001],ans1=0,ans2=0;
    int t,num=0;
	while(cin>>t){
        cin>>n>>m>>l>>v;
        for(int i = 0;i < n;i++){
            cin>>d[i]>>v0[i]>>a[i];
        }
        for(int i = 0;i<m;i++){
            cin>>p[i];
        }
        sort(p,p+m);
        for(int i = 0;i < n;i++){
            if(v0[i]<v&&a[i]<=0){
                continue;
            }
            if(v<v0[i]&&a[i]<0){
                int x=(v*v-v0[i]*v0[i])/(2*a[i]);
                for(int j = 0;j<m;j++){
                    if(p[j]>=d[i]&&p[j]<=x+d[i]){
                        ans1++;
                        if(j!=m-1)
                            break;
                        num++;
                        break;
                    }
                }
                continue;
            }
            if(v0[i]>v&&a[i]>=0){
                for(int j = 0;j<m;j++){
                    if(d[i]<=p[m]){
                        ans1++;
                        break;
                    }
                }
            }
            for(int j = 0;j<m;j++){
                if(p[j]<=d[i])
                    continue;
                int vt=sqrt(2*a[i]*(p[j]-d[i])+v0[i]*v0[i]);
                if(vt>v){
                    ans1++;
                    break;
                }
            }
        }
        cout<<ans1<<" ";
        if(a[0]>=0){
            cout<<n-1;
        }else{
            cout<<n-num-1;
        }
	}
	return 0;
}