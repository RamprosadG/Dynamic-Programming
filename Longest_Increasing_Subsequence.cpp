#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define ll                 long long
#define LL                 long long
#define pii                pair<int, int>
#define pll                pair<ll, ll>
#define pil                pair<int, ll>
#define pli                pair<ll, int>
#define vi                 vector<int>
#define vl                 vector<ll>
#define vii                vector<pii>
#define vll                vector<pll>
#define vil                vector<pil>
#define vli                vector<pli>
#define pb                 push_back
#define ppb                pop_back
#define mp                 make_pair
#define ff                 first
#define ss                 second
#define sz(x)              (int)x.size()
#define TN                 typename
#define all(v)             v.begin(), v.end()
#define fill(a, b)         memset(a, b, sizeof(a))
#define endl               '\n'
#define policy_set         tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define policy_multiset    tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>

template <TN T> T gcd(T a, T b) {return !b ? a : gcd(b, a % b);}
template <TN T> T lcm(T a, T b) {return a * (b / gcd(a, b));}
template <TN T> T sqr(T a) {return a * a;}
template <TN T> T cube(T a) {return a * a * a;}
template <TN T> inline void smin(T &a, T b) {a = a < b ? a : b;}
template <TN T> inline void smax(T &a, T b) {a = a > b ? a : b;}

template <TN T> inline void Int(T &n) {
	n = 0; int f = 1; register int ch = getchar();
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') f = -1;
	for (; isdigit(ch); ch = getchar()) n = (n << 3) + (n << 1) + ch - '0';
	n = n * f;
}

#define error(args...) {vector <string> _v = split(#args, ','); err(_v.begin(), args); cout << endl;}
vector <string> split(const string &s, char c) {
	vector <string> v;
	stringstream ss(s); string x;
	while (getline(ss, x, c)) v.emplace_back(x);
	return move(v);
}
void err(vector <string> :: iterator it) {}
template <typename T, typename... Args>
void err(vector <string> :: iterator it, T a, Args... args) {
	cout << it -> substr((*it)[0] == ' ', it -> length()) << " = " << a << ", ";
	err(++it, args...);
}

inline int in() {int n; scanf("%d", &n); return n;}
inline ll Lin() {ll n; scanf("%lld", &n); return n;}
inline double Din() {double n; scanf("%lf", &n); return n;}

inline int add(int a, int b, int mod) {a += b; return a >= mod ? a - mod : a;}
inline int sub(int a, int b, int mod) {a -= b; return a < 0 ? a + mod : a;}
inline int mul(int a, int b, int mod) {return (ll)a * b % mod;}

const int mod        = (int)1e9 + 7;
const ll  Mod        = (ll)1e9 + 7;

inline int add(int a, int b) {a += b; return a >= mod ? a - mod : a;}
inline int sub(int a, int b) {a -= b; return a < 0 ? a + mod : a;}
inline int mul(int a, int b) {return (ll)a * b % mod;}

const int inf        = (int)2e9 + 5;
const ll  Inf        = (ll)1e18 + 5;
const int N          = 2e5 + 5;

int a[N];

struct Longest_Increasing_Subsequence {

	std::vector<int> dp;
	std::vector<pii> tem;
	std::vector<int> mx;

	Longest_Increasing_Subsequence() {
		dp.resize(N, 1);
	}

	int bs(int x) {
		int low = 0, high = tem.size() - 1, ans = 0;
		while (low <= high) {
			int mid = (low + high) >> 1;
			if (tem[mid].ff < x) ans = mx[mid], low = mid + 1;
			else high = mid - 1;
		}
		return ans;
	}

	void calc(int left, int right) {
		tem.clear(), mx.clear();
		int mid = (left + right) >> 1;
		for (int i = left; i <= mid; i++) {
			tem.pb({a[i], dp[i]});
		}
		sort(all(tem));
		for (int i = 0; i < tem.size(); i++) {
			if (i == 0) mx.pb(tem[i].ss);
			else mx.pb(max(mx.back(), tem[i].ss));
		}
		for (int i = mid + 1; i <= right; i++) {
			dp[i] = max(dp[i], bs(a[i]) + 1);
		}
	}

	void divide(int left, int right) {
		if (left == right) return;
		int mid = (left + right) >> 1;
		divide(left, mid);
		calc(left, right);
		divide(mid + 1, right);
	}

	int get_result(int n) {
		divide(1, n);
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			smax(ans, dp[i]);
		}
		return ans;
	}
};

int solve() {
	int n = in();
	for (int i = 1; i <= n; i++) {
		a[i] = in();
	}
	Longest_Increasing_Subsequence lis;
	printf("%d\n", lis.get_result(n));
	return 0;
}

int main() {
	//ios_base::sync_with_stdio(false); cin.tie(NULL);
	int test = 1, tc = 0;
	//scanf("%d", &test);
	//cin >> test;
	while (test--) {
		//printf("Case %d: ", ++tc);
		solve();
	}
	return 0;
}
