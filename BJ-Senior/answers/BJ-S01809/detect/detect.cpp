#include<bits/stdc++.h>
using namespace std;
int n,m,T,l;
double V;
bool f0,f1,f2;
double d[100010],v[100010],a[100010];
int pt[100010];
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    
	cin>>T;
	while(T--){
	    f0=1,f1=1,f2=1;
	    cin>>n>>m>>l>>V;
	    for(int i=1;i<=n;i++){
            cin>>d[i]>>v[i]>>a[i];
            if(a[i]){
                f1=0;
            }
            if(a[i]<=0){
                f2=0;
            }
            if(a[i]>=0){
                f0=0;
            }
	    }
	    for(int i=1;i<=m;i++){
	        cin>>pt[i];
	    }
	    if(f1){
	        int cnt=0;
	        for(int i=1;i<=n;i++){
	            if(v[i]>V&&d[i]<=pt[m]){
	                cnt++;
	            }
	        }
	        if(cnt){
	            cout<<cnt<<' '<<m-1<<endl;
	        }else{
	            cout<<cnt<<' '<<m<<endl;
	        }
	        
	    } 
	    if(f2){
	        int cnt=0;
	        for(int i=1;i<=n;i++){
	            if(V<v[i]){
	            	if(d[i]<=pt[m]){
	            		cnt++;
	           	    }
	            
	            }else{
	            	double t=(V-v[i])/a[i];
	            	double s=d[i]+v[i]*t+0.5*a[i]*t*t;
	            	s=floor(s)+1;
	            	if(s<=pt[m]){
	               	 cnt++;
	           	 }
	            } 
	        }
	        if(!cnt){
	            cout<<cnt<<' '<<m<<endl;
	        }else{
	            cout<<cnt<<' '<<m-1<<endl;
	        }   
	    }
	  
	}
    return 0;
}