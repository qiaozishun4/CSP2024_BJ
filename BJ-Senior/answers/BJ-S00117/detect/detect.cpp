#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5,M=1e5+5,DIS=1e6+5;
ll n,m,L,V;
vector<ll>Sakuya;
struct node{ll d,v,a;}c[N];
vector<node>c1,c2;vector<pair<ll,ll> >f;
bool operator<(node a,node b){return a.d<b.d;}
inline ll cal(node c,ll d){//the velocity^2 of car i when driving at d
	if(c.d>d)return -1e10;
	return c.v*c.v+2*c.a*(d-c.d);
}
inline ll find(node c){
	ll l=lower_bound(Sakuya.begin(),Sakuya.end(),c.d)-Sakuya.begin(),r=Sakuya.size()-1;
	while(l<r){
		ll mid=(l+r+1)>>1;
		if(cal(c,Sakuya[mid])>V*V){l=mid;}
		else r=mid-1;
	}
	return l;
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T;cin>>T;while(T--){
		//long long tn,tm,tL,tV;
		//cin>>tn>>tm>>tL>>tV;
		//n=tn,m=tm,L=tL,V=tV;
		cin>>n>>m>>L>>V;
		Sakuya.clear();c1.clear();c2.clear();f.clear();
		for(int i=1;i<=n;i++){cin>>c[i].d>>c[i].v>>c[i].a;}
		for(int i=1;i<=m;i++){ll x;cin>>x;Sakuya.push_back(x);}
		ll Flandre=0;
		for(int i=1;i<=n;i++){
			if(c[i].a<0){
				ll j=lower_bound(Sakuya.begin(),Sakuya.end(),c[i].d)-Sakuya.begin();
				ll speed=cal(c[i],Sakuya[j]);
				if(speed>V*V){
					Flandre++;
					c1.push_back(c[i]);
					/*cout<<"i"<<i<<endl;*/
				}
			}
			else{
				ll speed=cal(c[i],Sakuya[Sakuya.size()-1]);
				if(speed>V*V){
					Flandre++;
					c2.push_back(c[i]);
					/*cout<<"i"<<i<<endl;*/
				}
			}
		}n=Flandre;//only these
		cout<<Flandre<<' ';int c1len=c1.size();
		for(int i=0;i<c1len;i++){f.push_back(make_pair(find(c1[i]),c1[i].d));}
		sort(f.begin(),f.end());ll Remilia=0,last=-1;
		int flen=f.size(),c2len=c2.size();
		for(int i=0;i<flen;i++){
			Remilia++;last=f[i].first;//exit(0);
			while(i+1<flen&&f[i+1].first>=last&&f[i+1].second<=Sakuya[last]){i++;}
		}
		if(last==-1){
			if(c2len>0){Remilia++;}
		}
		else{
			for(int i=0;i<c2len;i++){
				if(cal(c2[i],Sakuya[last])<=V*V){
					Remilia++;break;	
				}
			}
		}
		cout<<(m-Remilia)<<endl;//' '<<m<<' '<<flen<<' '<<c1len<<' '<<c2len<<endl;
	}
	return 0;
}
//一路向北～
/*
现在我们可以把整个题目转换成有几个点可以管辖一部分点，问最少需要几个管辖点。
分成两类，一类是<0，感觉考虑完这部分就做完了。另一类>0跟着就行
对于小于0的，先找到距离最远的可以检测的。
1
10 10 175391 226
31181 234 -546
32757 670 -9
43723 775 -3
78541 862 -4
26626 961 -13
54690 759 -998
56165 659 -3
56531 776 -34
32860 950 -6
86709 145 47
31182 33025 46753 52673 57685 60635 99569 124240 162898 170704
*/
