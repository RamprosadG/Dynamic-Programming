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

vi g[N];
int dp[N][2], par[N];

int mvc(int u, int state) {
	if (!g[u].size()) return 0;
	if (dp[u][state] != -1) return dp[u][state];
	int sum = 0;
	for (int i = 0; i < g[u].size(); i++) {
		int v = g[u][i];
		if (v != par[u]) {
			par[v] = u;
			if (!state) sum += mvc(v, 1);
			else sum += min(mvc(v, 0), mvc(v, 1));
		}
	}
	return dp[u][state] = sum + state;
}


int solve() {
	int n = in();
	for (int i = 1; i < n; i++) {
		int u = in(), v = in();
		g[u].pb(v);
		g[v].pb(u);
	}
	fill(dp, -1);
	printf("%d\n", min(mvc(1, 0), mvc(1, 1)));
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
