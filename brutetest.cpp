/*Template By Parth Sharma*/
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
using ld = long double;

typedef tree<int,null_type,less<int>,rb_tree_tag,
tree_order_statistics_node_update> ordered_set;

#ifndef  ONLINE_JUDGE
#define debug(x) cerr << #x << " = "; deb(x); cerr << endl;
#else
#define debug(x)
#endif

#define rep(i,a,b) for(int i = (a); i < (b); (i)++)
#define repa(i,s) for(auto &i : (s))
#define repr(i,a,b) for(int i = (a); i > (b); (i)--)
#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define F first
#define S second
#define pb push_back
#define pob pop_back
#define mp make_pair
#define sz(s) (int)(s.size())
#define MOD (int) (1e9 + 7)
#define INF (int)9e18
#define eps 0.000000001f

typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
typedef vector< pair<int,int> > vpii;
typedef map<int,int> mii;
typedef map<char,int> mci;
typedef map<int, vi> mivi;
typedef map<string, int> msi;
typedef pair<int,pair<int,int>> piii;

int mod_add(int a, int b, int m){a%=m; b%=m; return ((a+b) %m +m) %m;}
int mod_mul(int a, int b, int m){a%=m; b%=m; return ((a*b) %m +m) %m;}
int mod_sub(int a, int b, int m){a%=m; b%=m; return ((a-b) %m +m) %m;}

void deb(int x)    { cerr << x; }
void deb(string x) { cerr << x; }
void deb(char x)   { cerr << x; }
void deb(bool x)   { cerr << x; }
void deb(ld x)     { cerr << fixed << setprecision(15) << x; }

template<typename T, typename V> void deb(pair<T, V> P){ cerr << "{" ; deb(P.F); cerr << ", "; deb(P.S); cerr << "}";}
template<typename T, typename V> void deb(map <T, V> v) { cerr << "[ "; repa(u, v) { deb(u); cerr << " ";} cerr << "]";}
template<typename T> void deb(vector<T> v)   { cerr << "[ "; repa(u, v) { deb(u); cerr << " ";} cerr << "]"; }
template<typename T> void deb(set<T> v)      { cerr << "[ "; repa(u, v) { deb(u); cerr << " ";} cerr << "]"; }
template<typename T> void deb(multiset <T> v){ cerr << "[ "; repa(u, v) { deb(u); cerr << " ";} cerr << "]"; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef int item;
 
struct segtree{
    int size;
    vector<item> values;
 
    item NEUTRAL_ELEMENT = {0};
 
    item single(int n){
        return {n};
    }
 
    segtree(int n){
        size = 1;
        while(size < n) size *= 2;
        values.resize(2 * size);
    }
 
    item merge(item a, item b){
        return a + b;
    }
 
    void build(vector<int>& v, int x, int lx, int rx){
        if(rx - lx == 1){
            if(lx < sz(v))
                values[x] = single(v[lx]);
            return;
        }
        int m = (lx + rx) / 2;
        build(v, 2 * x + 1, lx, m);
        build(v, 2 * x + 2, m, rx);
        values[x] = merge(values[2 * x + 1], values[2 * x + 2]);
    }
 
    void build(vector<int>& v){
        build(v, 0, 0, size);
    }
 
    void set(int i, int v, int x, int lx, int rx){
        if(rx - lx == 1){
            values[x] += single(v);
            return;
        }
        int m = (lx + rx) / 2;
        if(i < m) {
            set(i, v, 2 * x + 1, lx, m);
        }   
        else{
            set(i, v, 2 * x + 2, m, rx);
        }
        values[x] = merge(values[2 * x + 1], values[2 * x + 2]);
    }
 
    void set(int i, int v){
        set(i, v, 0, 0, size);
    }
 
    item calc(int l, int r, int x, int lx, int rx){
        if(l >= rx or lx >= r) return NEUTRAL_ELEMENT;
        if(lx >= l and rx <= r) return values[x];
        int m = (lx + rx) / 2;
        return merge(calc(l, r, 2 * x + 1, lx, m), calc(l, r, 2 * x + 2, m, rx));
    }
 
    item calc(int l, int r){
        return calc(l, r, 0, 0, size);
    }
 
};
 

int my(vi& v, int n){
    
}

int brute(vi &v, int n){
    repa(i, v) cin >> i;
    int res = 0;
    rep(i, 0, n){
        rep(j, i + 1, n){
            if(v[i] >= v[j]){
                res++;
              //  cout << i + 1 << " " << v[i] << " " << j + 1 << " " << v[j] << endl;
            }
        }
    }
    return res;
}

void run_case(){
    rep(k, 0, 100){
        int n = uniform_int_distribution<int>(1, 10)(rng);
        vi v(n);
        rep(i, 0, n){
            v[i] = uniform_int_distribution<int>(1, n)(rng);
        }
        int r1 = my(v, n);
        int r2 = brute(v, n);
        if(r1 != r2){
            cout << r1 << " " << r2 << " " << endl;
            repa(i, v) cout << i << " ";
            cout << endl;
        }
    }
}
int32_t main(){

    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);  cout.tie(NULL);

    #ifndef ONLINE_JUDGE 
     freopen("Error.txt", "w", stderr);
    #endif

   // freopen("input.txt", "r", stdin);
   // freopen("output.txt", "w", stdout);

    int tt = 1, el = 1;
    //cin >> tt;
    //cout << fixed << setprecision(12);
    while(tt--){
        //cout << "Case #" << el++ << ": ";
        run_case();
    }
    return 0;
}       

 

 
