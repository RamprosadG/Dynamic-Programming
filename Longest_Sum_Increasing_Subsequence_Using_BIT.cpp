#include<bits/stdc++.h>
using namespace std;

#define ll             long long
#define LL             long long
#define gcd(a,b)       __gcd(a, b)
#define lcm(a,b)       a * (b / gcd(a, b))
#define pii            pair<int, int>
#define pll            pair<ll, ll>
#define pil            pair<int, ll>
#define pli            pair<ll, int>
#define vi             vector<int>
#define vl             vector<ll>
#define vii            vector<pii>
#define vll            vector<pll>
#define vil            vector<pil>
#define vli            vector<pli>
#define pb             push_back
#define ppb            pop_back
#define mp             make_pair
#define ff             first
#define ss             second
#define all(v)         v.begin(), v.end()
#define fill(a, b)     memset(a, b, sizeof a)
#define smax(a, b)     a = max(a, b)
#define smin(a, b)     a = min(a, b)
#define sqr(x)         x * x
#define cube(x)        x * x * x
#define endl           '\n'

int in() {
	int n;
	scanf("%d", &n);
	return n;
}

ll Lin() {
	ll n;
	scanf("%lld", &n);
	return n;
}

double Din() {
	double n;
	scanf("%lf", &n);
	return n;
}

const ll inf = (ll)1e17;
const ll mod = (ll)1e9 + 7;
const int N = 2e5 + 5;

ll tree[N];
ll a[N];
int b[N];

void compress(int n) {
	vli tem;
	for (int i = 1; i <= n; i++) {
		tem.pb({a[i], i});
	}
	sort(all(tem));
	int cur = 1;
	for (int i = 0; i < n; i++) {
		if (i > 0 && tem[i].ff != tem[i - 1].ff) cur++;
		b[tem[i].ss] = cur;
	}
}

void update(int n, int x, ll val) {
	while (x <= n) {
		tree[x] = max(tree[x], val);
		x += (x & -x);
	}
}

ll query(int x) {
	ll mx = 0;
	while (x > 0) {
		mx = max(mx, tree[x]);
		x -= (x & -x);
	}
	return mx;
}

int solve() {
	int n = in();
	for (int i = 1; i <= n; i++) {
		a[i] = Lin();
	}
	compress(n);
	for (int i = 1; i <= n; i++) {
		update(n, b[i], query(b[i] - 1) + a[i]);
	}
	ll ans = query(n);
	printf("%lld\n", ans);
	return 0;
}

int main() {
	int test = 1, tc = 0;
	while (test--) {
		//printf("Case %d: ", ++tc);
		solve();
	}
	return 0;
}