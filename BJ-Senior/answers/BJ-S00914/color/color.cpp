#include <algorithm>
#include <cstring>
#include <cstdio>
#define PROB "color"
namespace FIO{
	const size_t IBufSz = 1048576;
	const size_t OBufSz = 1048576;
	char ibuf[IBufSz],obuf[OBufSz];
	char *ipk,*ied,*opk;
	FILE *inf,*ouf;
	inline void Open(const char *i,const char *o){
		inf = fopen(i,"rb"),ouf = fopen(o,"wb");
		ipk = ied = ibuf,opk = obuf;
	}
	inline void Open(FILE *i,FILE *o){
		inf = i,ouf = o,ipk = ied = ibuf,opk = obuf;
	}
	inline char GetChar(){
		if(ipk == ied)
			ied = (ipk = ibuf) + fread(ibuf,1,IBufSz,inf);
		return ipk == ied?EOF:*(ipk ++);
	}
	inline void Flush(){
		fwrite(obuf,1,opk - obuf,ouf),opk = obuf;
	}
	inline void Close(){
		Flush(),fclose(inf),fclose(ouf);
	}
	struct __IOGuard{~__IOGuard(){Close();}} __IOG;
	inline void PutChar(char c){
		if(opk == obuf + OBufSz) Flush();
		*(opk ++) = c;
	}
	template<typename T>
	inline T ReadInt(){
		char ch = GetChar();
		T res = 0;
		bool sgn;
		do{
			sgn = false;
			while((ch < '0' || '9' < ch) && ch != '-')
				ch = GetChar();
			if(ch == '-') sgn = true,ch = GetChar();
		}while(ch < '0' || '9' < ch);
		while('0' <= ch && ch <= '9'){
			res = (res << 3) + (res << 1) + (ch ^ 48);
			ch = GetChar();
		}
		return sgn?-res:res;
	}
	template<typename T>
	inline void WriteInt(T x){
		if(x < 0)
			return PutChar('-'),WriteInt(-x),void();
		if(x > 9) WriteInt(x / 10);
		PutChar('0' + x % 10);
	}
	inline char ReadChar(){
		char ch = GetChar();
		while(ch == ' ' || ch == '\r' || ch == '\n' || 
				ch == '\t' || ch == '\v')
			ch = GetChar();
		return ch;
	}
}
#define stdmax std::max<long long>
const long long neginf = ~0x3f3f3f3f3f3f3f3f;
struct Case{
	long long seg[2][800010],dp[200010][2],pre[200010];
	int a[200010],val[200010];
	Case(){
		memset(seg,~0x3f,sizeof(seg));
		memset(dp,0,sizeof(dp));
		memset(pre,0,sizeof(pre));
		memset(a,0,sizeof(a));
	}
	inline void Update(long long *seg,int p,int l,int r,int t,long long v){
		if(l == r){
			seg[p] = stdmax(seg[p],v);
			return;
		}
		int mid = (l + r) >> 1;
		if(t <= mid)
			Update(seg,p << 1,l,mid,t,v);
		else Update(seg,p << 1 | 1,mid + 1,r,t,v);
		seg[p] = stdmax(seg[p << 1],seg[p << 1 | 1]);
	}
	inline long long Query(long long *seg,int p,int l,int r,int ql,int qr){
		if(ql > qr) return neginf;
		if(ql <= l && r <= qr) return seg[p];
		int mid = (l + r) >> 1;
		long long ans = neginf;
		if(ql <= mid)
			ans = stdmax(ans,Query(seg,p << 1,l,mid,ql,qr));
		if(mid < qr)
			ans = stdmax(ans,Query(seg,p << 1 | 1,mid + 1,r,ql,qr));
		return ans;
	}
	inline void Work(){
		int n = FIO::ReadInt<int>();
		for(int i = 1;i <= n;i ++){
			val[i] = a[i] = FIO::ReadInt<int>();
			pre[i] = pre[i - 1] + a[i] * (a[i] == a[i - 1]);
		}
		n ++,val[n] = a[n] = 1000001,pre[n] = pre[n - 1];
		std::sort(val + 1,val + n + 1);
		int cnt = std::unique(val + 1,val + n + 1) - val - 1;
		for(int i = 1;i <= n;i ++)
			a[i] = std::lower_bound(val + 1,val + cnt + 1,a[i]) - val;
		for(int i = 1;i <= n;i ++){
			dp[i][0] = pre[i - 1] + stdmax(0,stdmax(stdmax(
					Query(seg[1],1,0,cnt,0,a[i] - 1),
					Query(seg[1],1,0,cnt,a[i] + 1,cnt)
				),Query(seg[1],1,0,cnt,a[i],a[i]) + val[a[i]]));
			dp[i][1] = pre[i - 1] + stdmax(0,stdmax(stdmax(
					Query(seg[0],1,0,cnt,0,a[i] - 1),
					Query(seg[0],1,0,cnt,a[i] + 1,cnt)
				),Query(seg[0],1,0,cnt,a[i],a[i]) + val[a[i]]));
			Update(seg[0],1,0,cnt,a[i - 1],dp[i][0] - pre[i]);
			Update(seg[1],1,0,cnt,a[i - 1],dp[i][1] - pre[i]);
		}
		FIO::WriteInt(stdmax(dp[n][0],dp[n][1])),FIO::PutChar('\n');
	}
};
int main(){
#ifdef DBG
	FIO::Open(stdin,stdout);
#else
	FIO::Open(PROB ".in",PROB ".out");
#endif
	int T = FIO::ReadInt<int>();
	while(T --){
		Case CurCase;
		CurCase.Work();
	}
	return 0;
}