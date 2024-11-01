#include<bits/stdc++.h>
using namespace std;
int T,n,m,k,sx,sy,sd;
int v[1010][1010][4];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
	cin>>T;
	while(T--){
    	int ans=0;
    	memset(v,0,sizeof v);
	    cin>>n>>m>>k;
	    cin>>sx>>sy>>sd;
	    for(int i=1;i<=n;i++){
	        for(int j=1;j<=m;j++){
	            char c;
	            cin>>c;
	            if(c=='x'){
	                v[i][j][0]=-1;
	                v[i][j][1]=-1;
	                v[i][j][2]=-1;
	                v[i][j][3]=-1;
	            }
	        }
	    }
	  
	    v[sx][sy][sd]=1;
	    queue<int>q;
	    while(!q.empty()){
	        q.pop();
	    }
	    q.push(sx);
	    q.push(sy);
	    q.push(sd);
	    int i=0;
	    
	    while(!q.empty()){
	        if(i==k){
	            break;
	        }
	        int nx=q.front();
	        q.pop();
	        int ny=q.front();
	        q.pop();
	        int nd=q.front();
	        q.pop();
	        //cout<<nx<<' '<<ny<<' '<<nd<<endl;
	        //cout<<i<<endl;
	        if(nd==0){
	            ny++;
	            if(ny>m||(v[nx][ny][nd]==-1)){
	                ny--;
	                nd=(nd+1)%4;
	            }
	            q.push(nx);
	            q.push(ny);
	            q.push(nd);
	        }else if(nd==1){
	            nx++;
	            if(nx>n||(v[nx][ny][nd]==-1)){
	                nx--;
	                nd=(nd+1)%4;
	            }
	            q.push(nx);
	            q.push(ny);
	            q.push(nd);
	        }else if(nd==2){
	            ny--;
	            if(ny<1||(v[nx][ny][nd]==-1)){
	                ny++;
	                nd=(nd+1)%4;
	            }
	            q.push(nx);
	            q.push(ny);
	            q.push(nd);
	        }else if(nd==3){
	            nx--;
	            if(nx<1||(v[nx][ny][nd]==-1)){
	                nx++;
	                nd=(nd+1)%4;
	            }
	            q.push(nx);
	            q.push(ny);
	            q.push(nd);
	        }
	        v[nx][ny][nd]=1;
	        i++;
	    }
	    for(int i=1;i<=n;i++){
	        for(int j=1;j<=m;j++){
	            if(v[i][j][0]==-1){
	                ans--;
	            }
	            ans+=(v[i][j][0]||v[i][j][1]||v[i][j][2]||v[i][j][3]);
	        }
	    }
	    cout<<ans<<endl;
	}
	return 0;
}