#include<bits/stdc++.h>
using namespace std;
int d[100005],v[100005],a[100005],p[100005];
vector<pair<int,int>>qz;deque<pair<int,int>>dq;
void slove1(int n,int m,int L,int V){
    int cnt=0;
    for(int i=1;i<=n;++i){
		if(d[i]<=p[m]&&sqrt(v[i]*v[i]+2*a[i]*(p[m]-d[i]))>V){++cnt;}
	}cout<<cnt<<' '<<(cnt>0?m-1:m)<<endl;
	return;
}void slove2(int n,int m,int L,int V){
	//cout<<"slove2"<<endl;
	int cnt=0;qz.clear();
	for(int i=1;i<=n;++i){
		if(a[i]>=0){
			int l=1,r=m,mid;
			if(d[i]<=p[m]&&sqrt(v[i]*v[i]+2*a[i]*(p[m]-d[i]))>V){
				while(l<r){
					mid=(l+r)/2;
					if(d[i]>p[mid]||d[i]<=p[mid]&&sqrt(v[i]*v[i]+2*a[i]*(p[mid]-d[i]))<=V)l=mid+1;
					else r=mid;
				}//cout<<i<<" l:"<<l<<" r:"<<m<<endl;
				qz.push_back(make_pair(l,m));++cnt;
			}
		}else{
			if(v[i]<V)continue;
			else{
				int l=1,r=m,mid,tmpl;
				while(l<r){
					mid=(l+r)/2;
					if(v[i]*v[i]+2*a[i]*(p[mid]-d[i])<=V*V)goto next;
					if(d[i]>p[mid]||d[i]<=p[mid]&&v[i]*v[i]+2*a[i]*(p[mid]-d[i])<=V*V){
						l=mid+1;
					}else r=mid;
				}
				r=m,tmpl=l;
				while(l<r){
					mid=(l+r+1)/2;
					if(sqrt(v[i]*v[i]+2*a[i]*(p[mid]-d[i]))>V)l=mid;
					else r=mid-1;
				}//cout<<i<<" l:"<<tmpl<<" r:"<<l<<endl;
				qz.push_back(make_pair(tmpl,l));++cnt;
				next:;
			}
		}
	}
	//cout<<"bend"<<endl;
	sort(qz.begin(),qz.end());
	dq.push_back(qz[0]);
	for(int i=1;i<=qz.size();++i){
		if(qz[i].first<dq.back().second){
			pair<int,int>newqz=make_pair(qz[i].first,dq.back().second);
			dq.pop_back();
			dq.push_back(newqz);
		}else dq.push_back(qz[i]);
		//cout<<dq.back().first<<' '<<dq.back().second<<endl;
	}
	cout<<cnt<<' '<<m-dq.size()<<endl;
}
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    ios::sync_with_stdio(0);
    int t;cin>>t;
    while(t--){
        int n,m,L,V;bool speA=1,speB=1;
        cin>>n>>m>>L>>V;
        for(int i=1;i<=n;++i){
            cin>>d[i]>>v[i]>>a[i];
            if(a[i]!=0)speA=0;
            if(a[i]<=0)speB=0;
        }for(int i=1;i<=m;++i){
            cin>>p[i];
        }
		if(speA||speB)slove1(n,m,L,V);
        else slove2(n,m,L,V);
    }
}