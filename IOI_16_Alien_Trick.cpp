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

struct CHT_DEC_MIN {
    vl m, b, d;
    int ptr;
    CHT_DEC_MAX() {
        ptr = 0;
    }

    bool bad(int f1, int f2, int f3) {
        return 1.0 * (b[f2] - b[f1]) * (m[f1] - m[f3]) >= 1.0 * (b[f3] - b[f1]) * (m[f1] - m[f2]);
    }

    void add(ll M, ll B, ll D) {
        m.pb(M), b.pb(B), d.pb(D);
        int sz = (int)m.size();
        while(sz >= 3 && bad(sz - 3, sz - 2, sz - 1)) {
            m.erase(m.end() - 2);
            b.erase(b.end() - 2);
            d.erase(d.end() - 2);
            sz--;
        }
    }

    ll f(int idx, ll X) {
        return m[idx] * X + b[idx];
    }

    pll query(ll x) {
        if(ptr >= (int)m.size()) ptr = (int)m.size() - 1;
        while(ptr < m.size() - 1 && f(ptr, x) > f(ptr+1, x)) ptr++;
        return {f(ptr, x), d[ptr] + 1};
    }
};

ll a[N], p[N];

pll call(int n, ll C) {
    CHT_DEC_MIN dp;
    dp.add(0LL, 0LL, 0LL);
    pll cur = {inf, inf};
    for(int i = 1; i <= n; i++) {
        cur = dp.query(2 * p[i]);
        cur.ff = cur.ff + p[i] * p[i] + C;
        dp.add(-p[i], cur.ff + p[i] * p[i], cur.ss);
    }
    return cur;
}

ll bs(int n, int k) {
    ll low = 0LL, high = p[n] * p[n];
    ll ans = p[n];

    while(low <= high) {
        ll mid = (low + high) / 2;
        if(call(n, mid).ss <= k) {
            ans = mid;
            high = mid - 1;
        } else low = mid + 1;
    }
    pll x = call(n, ans);
    return x.ff - (ll)k * ans;
}

int solve() {
    int n = in(), k = in();
    for(int i = 1; i <= n; i++) {
        a[i] = Lin();
        p[i] = p[i - 1] + a[i];
    }
    printf("%lld\n", bs(n, k));
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
