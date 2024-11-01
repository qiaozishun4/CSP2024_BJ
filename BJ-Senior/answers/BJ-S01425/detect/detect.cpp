#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T--){
        int n,m;double L,V;
        cin>>n>>m>>L>>V;
        double d[100005],v[100005],a[100005];
        bool pf[1005][1005];
        int cpf[100005]={0};
        memset(pf,false,sizeof(pf));
        for(int i=1;i<=n;i++){
            cin>>d[i]>>v[i]>>a[i];
        }
        int ans=0;
        int p[100005];
        for(int i=1;i<=m;i++)cin>>p[i];
        for(int i=1;i<=n;i++){
            //double chao=d[i]+(V*V-v[i]*v[i])/(2*a[i]);
            int flag=0;
            for(int j=1;j<=m;j++){
				if(p[j]<d[i])continue;
                int lu=p[j]-d[i];
                /*if(chao<=p[j]&&a[i]>0){
                    ans++;pf[j]=true;
                }*/
                if(sqrt(v[i]*v[i]+2*a[i]*lu)>V){
					if(flag==0){
						ans++;
						flag=1;
					}
                    pf[j][i]=true;cpf[j]++;
                }


            }
        }
        cout<<ans<<" ";
        int sum=0;
        while(ans>0){
			int maxn=0;int id=0;
			for(int i=1;i<=m;i++){
				if(cpf[i]>maxn){
					maxn=cpf[i];id=i;
			    } 
				
			}
			sum++;
			ans-=maxn;
			
			for(int i=1;i<=n;i++){
				if(pf[id][i]==true){
					for(int j=1;j<=m;j++){
				         if(pf[j][i]==true){
							 cpf[j]--;
							 pf[j][i]=false;
						 }
				       
		            }
			    }
		    }
		}
        cout<<n-sum<<endl;
    }
    return 0;
}
