#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=1e6+7;
const int inf=2147483600;
int n,m,l,lim_v;

int zhuangya[1<<20];

int monitoring[maxn];

struct Monitor{
	int num,cord,car_monitoring_cnt;
	bool enable;
	vector<int> car_linked;
}monitor[maxn];

struct Node{
	int d,v,a,num;
	int reach_lim_pos,reach_lim_pre;
	int pos_monitor,pre_monitor;
}car[maxn];//reach_lim shows that the car will be detected as out of limit on the cordinate of "reach_lim"

bool check(){
	bool ret=1;
	for(int i=1;i<=n;i++)ret&=monitoring[i];
	return ret;
}

inline void read(int &x){
	char c;
	int sign=1;
	x=0;
	while(c=getchar()){
		if(c=='\n'||c==' '||c==EOF)break;
		if(c=='-')sign=-1;
		if(c>='0'&&c<='9')x=(x<<3)+(x<<1)+c-'0';
	}
	x*=sign;
	return;
}
inline int square(int x){
	return x*x;
}
void print_car(Node x){
	printf("Num: %lld, Cordinate of start point: %lld, v = %lld, a = %lld\n       Go beyond in[ %lld , %lld ]\n",x.num,x.d,x.v,x.a,x.reach_lim_pre,x.reach_lim_pos);
	printf("       First detected by monitor at %lld, Last detected by monitor at %lld\n",monitor[x.pre_monitor].cord,monitor[x.pos_monitor].cord);
}

bool operator < (const Monitor &x,const Monitor &y){
	return x.car_monitoring_cnt<y.car_monitoring_cnt;
}
bool operator > (const Monitor &x,const Monitor &y){
	return x.car_monitoring_cnt>y.car_monitoring_cnt;
}
bool operator == (const Monitor &x,const Monitor &y){
	return x.car_monitoring_cnt == y.car_monitoring_cnt;
}

signed main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int t;
	cin >> t;
	getchar();
	while(t--){
		bool point_ab=1,point_n=1;
		read(n);
		read(m);
		read(l);
		read(lim_v);
		vector<Node> car_pos,car_monitored;
		for(int i=1;i<=n;i++){
			
			read(car[i].d);
			read(car[i].v);
			read(car[i].a);
			if(car[i].a<0)point_ab=0;
			car[i].num=i;
//			cout << car[i].a << endl;
			if(car[i].a < 0){
				if(car[i].v <= lim_v)continue;
				car[i].reach_lim_pre = car[i].d;
				car[i].reach_lim_pos = min(l,car[i].d+(square(lim_v)-square(car[i].v))/(2*car[i].a));
				if(square(car[i].v)+2*car[i].a*(car[i].reach_lim_pos-car[i].d) == square(lim_v)) car[i].reach_lim_pos--;
			}//匀减速
			else if(car[i].a == 0){
				if(car[i].v <= lim_v)continue;
				car[i].reach_lim_pre = car[i].d;
				car[i].reach_lim_pos = l;
			}//匀速
			else{
				car[i].reach_lim_pos = l;
				car[i].reach_lim_pre = max(car[i].d,car[i].d+(square(lim_v)-square(car[i].v))/(2*car[i].a));
				if(square(car[i].v)+2*car[i].a*(car[i].reach_lim_pre - car[i].d) == square(lim_v)) car[i].reach_lim_pre++;
//				printf("((%d)^2 + 2 * %d * %d)^2 = %d, %d",car[i].v,car[i].a,car[i].reach_lim_pre - car[i].d,square(square(car[i].v)+2*car[i].a*(car[i].reach_lim_pre - car[i].d)),lim_v);
			}//匀加速
			if(car[i].reach_lim_pre <= l)car_pos.push_back(car[i]);//如果car[i]第一次被判定超速在路段内，那么这辆车就有可能被检测到
		}
		for(int i=1;i<=m;i++){
			read(monitor[i].cord);
			monitor[i].car_linked.clear();
			monitor[i].car_monitoring_cnt=0;
			monitor[i].enable=0;
			monitor[i].num=i;
		}
//		for(int i=1;i<=m;i++)cout << monitor[i] << " " ;
//		cout << endl;
//		for(auto cur : car_pos){print_car(cur);}
		for(int i=0;i<car_pos.size();i++){
			int l=1,r=m+1;
			while(l<r){
				int mid=(l+r)/2;
//				printf("[%lld,%lld]first, mid cordinate: %lld\n",l,r,monitor[mid]);
				if(monitor[mid].cord < car_pos[i].reach_lim_pre)l=mid+1;
				else r=mid;
			}
			car_pos[i].pre_monitor = l;
			if(l==m+1)car_pos[i].pre_monitor=inf;
			l=0,r=m;
			while(l<r){
				int mid=(l+r)/2+1;
//				printf("[%lld,%lld]second, mid cordinate: %lld\n",l,r,monitor[mid]);
				if(monitor[mid].cord > car_pos[i].reach_lim_pos)r=mid-1;
				else l=mid;
			}
			car_pos[i].pos_monitor = l;
//			print_car(car_pos[i]);
		}
		int cars_detected_cnt = 0;
		for(auto cur : car_pos){
			if(cur.pre_monitor<=cur.pos_monitor){
				cars_detected_cnt++;
				car_monitored.push_back(cur);
			}
		}
		printf("%lld ",cars_detected_cnt);
		if(point_ab){
			printf("%lld\n",m-min(1LL,cars_detected_cnt));
			continue;
		}
	}
	return 0;
}
