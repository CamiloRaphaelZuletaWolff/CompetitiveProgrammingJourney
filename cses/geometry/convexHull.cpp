#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ld EPS = 1e-9;
const ld PI = acosl(-1.0L);

template<class T> int sgn(T x) { return (x > EPS) - (x < -EPS); }

template<class T> struct Point {
    T x, y;
    Point(T x = 0, T y = 0) : x(x), y(y) {}
    Point operator+(const Point& o) const { return Point(x + o.x, y + o.y); }
    Point operator-(const Point& o) const { return Point(x - o.x, y - o.y); }
    Point operator*(T k) const { return Point(x * k, y * k); }
    Point operator/(T k) const { return Point(x / k, y / k); }
    bool operator<(const Point& o) const { return tie(x, y) < tie(o.x, o.y); }
    bool operator==(const Point& o) const { return x == o.x && y == o.y; }
    T dot(const Point& o) const { return x * o.x + y * o.y; }
    T cross(const Point& o) const { return x * o.y - y * o.x; }
    T cross(const Point& b, const Point& c) const { return (b - *this).cross(c - *this); }
    T norm2() const { return x * x + y * y; }
    ld norm() const { return sqrtl((ld)norm2()); }
    ld angle() const { return atan2l((ld)y, (ld)x); }
    Point perp() const { return Point(-y, x); }          // rota 90° CCW
    Point<ld> toD() const { return Point<ld>((ld)x, (ld)y); }
    friend istream& operator>>(istream& in, Point& p) { return in >> p.x >> p.y; }
    friend ostream& operator<<(ostream& out, const Point& p) { return out << p.x << ' ' << p.y; }
};
using P  = Point<ll>;   
using PD = Point<ld>;   

template<class T> int orient(const Point<T>& a, const Point<T>& b, const Point<T>& c) {
    return sgn(a.cross(b, c));
}

template<class T> bool onSegment(const Point<T>& p, const Point<T>& a, const Point<T>& b) {
    return orient(a, b, p) == 0 && sgn((a - p).dot(b - p)) <= 0;
}

template<class T> bool segIntersect(const Point<T>& a, const Point<T>& b,
                                    const Point<T>& c, const Point<T>& d) {
    int o1 = orient(a, b, c), o2 = orient(a, b, d);
    int o3 = orient(c, d, a), o4 = orient(c, d, b);
    if (o1 * o2 < 0 && o3 * o4 < 0) return true;              
    return onSegment(c, a, b) || onSegment(d, a, b) ||
           onSegment(a, c, d) || onSegment(b, c, d);
}
template<class T> vector<Point<T>> convexHull(vector<Point<T>> pts, bool keepCollinear = true) {
    sort(pts.begin(), pts.end());
    pts.erase(unique(pts.begin(), pts.end()), pts.end());
    int n = pts.size();
    if (n <= 2) return pts;
    if (keepCollinear) {                       
        bool all = true;
        for (int i = 1; i < n - 1 && all; i++) all = orient(pts[0], pts[n - 1], pts[i]) == 0;
        if (all) return pts;
    }
    auto bad = [&](int o) { return keepCollinear ? o < 0 : o <= 0; };
    vector<Point<T>> h(2 * n); int k = 0;
    for (int i = 0; i < n; i++) {                          
        while (k >= 2 && bad(orient(h[k - 2], h[k - 1], pts[i]))) k--;
        h[k++] = pts[i];
    }
    for (int i = n - 2, t = k + 1; i >= 0; i--) {          
        while (k >= t && bad(orient(h[k - 2], h[k - 1], pts[i]))) k--;
        h[k++] = pts[i];
    }
    h.resize(k - 1);
    return h;
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
    

    ll t,m; cin >>t; 
    
    vector<P> puntitos;
    while (t--)
    {
        P a; cin>>a;
        puntitos.push_back(a);        
    }

    vector<P> lu = convexHull(puntitos);

    cout<<lu.size()<<endl;
    for(auto x : lu){
        cout<<x<<endl;
    }
    
    // cout << fixed << setprecision(10);   // si imprimes ld

    return 0;
}