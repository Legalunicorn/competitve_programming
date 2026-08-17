#include <bits/stdc++.h>
#define int long long
using namespace std;
int T,n,x,y,a[200005],b[200005],mn,k,mx;
struct node {
    int x,l,r,sum;
}ans[800005];
inline int ls(int p) {return p << 1;}
inline int rs(int p) {return (p << 1) | 1;}
inline void upd(int now) {
    ans[now].sum = ans[ls(now)].sum + ans[rs(now)].sum;
    ans[now].x = max(ans[ls(now)].r + ans[rs(now)].l, ans[ls(now)].x);
    ans[now].x = max(ans[now].x,ans[rs(now)].x);
    ans[now].l = max(ans[ls(now)].l,ans[ls(now)].sum + ans[rs(now)].l);
    ans[now].r = max(ans[rs(now)].r,ans[rs(now)].sum + ans[ls(now)].r);
    return;
}
inline void build(int l,int r,int now) {
    if (l == r) {ans[now].x = ans[now].l = ans[now].r = ans[now].sum = a[l];return;}
    int m =  (l + r) >> 1;
    build(l,m,ls(now));
    build(m + 1,r,rs(now));
    upd(now);
    return;
}
inline void add(int p,int t,int l,int r,int now) {
    if (l > t || r < t) return;
    if (l == r && l == t) {
        ans[now].x += p,ans[now].l += p,ans[now].r += p,ans[now].sum += p;
        return;
    }
    int m = (l + r) >> 1;
    add(p,t,l,m,ls(now));
    add(p,t,m + 1,r,rs(now));
    upd(now);
}
signed main()
{
	scanf("%lld",&T);
    while(T--) {
        scanf("%lld%lld",&n,&k);
        for (int i = 1; i <= n; i++) {
            scanf("%lld",&a[i]);
        }
        for (int i = 1; i <= n; i++) {
            scanf("%lld",&b[i]);
        }
        build(1,n,1);
        if (k & 1) {
            int pans = -1e16;
            for (int i = 1; i <= n; i++) {
                add(b[i],i,1,n,1);
                pans = max(pans,ans[1].x);
                add(-b[i],i,1,n,1);
            }
            printf("%lld\n",pans);
        } else {
            printf("%lld\n",ans[1].x);
        }
    }
	return 0;
}