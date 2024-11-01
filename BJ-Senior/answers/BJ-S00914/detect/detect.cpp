#include <algorithm>
#include <cstring>
#include <cstdio>
#define PROB "detect"
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
#define sq(x) ((x) * (x))
struct Case{
	int d[100010],v[100010];
	int a[100010],p[100010];
	int l[100010],s[100010];
	inline void Work(){
		int n = FIO::ReadInt<int>();
		int m = FIO::ReadInt<int>();
		int L = FIO::ReadInt<int>();
		int V = FIO::ReadInt<int>();
		for(int i = 1;i <= n;i ++){
			d[i] = FIO::ReadInt<int>();
			v[i] = FIO::ReadInt<int>();
			a[i] = FIO::ReadInt<int>();
		}
		for(int i = 1;i <= m;i ++)
			p[i] = FIO::ReadInt<int>();
		int ans1 = 0;
		for(int i = 1;i <= n;i ++){
			int nume = sq(V) - sq(v[i]),deno = 2 * a[i];
			if(a[i] > 0 && v[i] <= V){
				int frc = nume / deno + d[i];
				int pos = std::upper_bound(p + 1,p + m + 1,frc) - p;
				if(pos <= m) ans1 ++,l[m] = std::max(l[m],pos);
			}else if(a[i] < 0 && v[i] > V){
				int frc = nume / deno + bool(nume % deno) + d[i];
				int posr = std::lower_bound(p + 1,p + m + 1,frc) - p - 1;
				int posl = std::lower_bound(p + 1,p + m + 1,d[i]) - p;
				if(posl <= posr) ans1 ++,l[posr] = std::max(l[posr],posl);
			}else if(a[i] >= 0 && v[i] > V){
				int pos = std::lower_bound(p + 1,p + m + 1,d[i]) - p;
				if(pos <= m) ans1 ++,l[m] = std::max(l[m],pos);
			}
		}
		FIO::WriteInt(ans1),FIO::PutChar(' ');
		for(int i = 1;i <= m;i ++)
			s[i] = s[i - 1] + (l[i] && s[i - 1] == s[l[i] - 1]);
		FIO::WriteInt(m - s[m]),FIO::PutChar('\n');
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
		memset(&CurCase,0,sizeof(Case));
		CurCase.Work();
	}
	return 0;
}