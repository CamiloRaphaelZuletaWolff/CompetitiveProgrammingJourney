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

template<class T> T area2(const vector<Point<T>>& p) {
    T s = 0; int n = p.size();
    for (int i = 0; i < n; i++) s += p[i].cross(p[(i + 1) % n]);
    return s;
}
template<class T> ld perimeter(const vector<Point<T>>& p) {
    ld s = 0; int n = p.size();
    for (int i = 0; i < n; i++) s += (p[(i + 1) % n] - p[i]).norm();
    return s;
}

template<class T> int pointInPolygon(const vector<Point<T>>& poly, const Point<T>& p) {
    int n = poly.size(); bool in = false;
    for (int i = 0; i < n; i++) {
        Point<T> a = poly[i], b = poly[(i + 1) % n];
        if (onSegment(p, a, b)) return 2;
        if ((a.y > p.y) != (b.y > p.y)) {          
            int o = orient(a, b, p);
            if (b.y > a.y ? o > 0 : o < 0) in = !in;
        }
    }
    return in ? 1 : 0;
}
pair<ll, ll> latticePoints(const vector<P>& p) {
    ll B = 0, A2 = llabs(area2(p)); int n = p.size();
    for (int i = 0; i < n; i++) {
        P d = p[(i + 1) % n] - p[i];
        B += gcd(llabs(d.x), llabs(d.y));
    }
    return {(A2 - B + 2) / 2, B};
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    
    // freopen("../../input.txt", "r", stdin);
    // freopen("../../output.txt", "w", stdout);
    

    ll t,m; cin >>t>>m; 
    
    vector<P> puntitos;
    while (t--)
    {
        P a; cin>>a;
        puntitos.push_back(a);        
    }
    
    for (ll i = 0; i < m; i++)
    {
        P punto; cin>>punto;
        ll a =pointInPolygon(puntitos,punto);
        if(a == 0){
            
            cout<<"OUTSIDE";
            
        } else{
            if(a == 1){
                cout<<"INSIDE";
            }else{
                cout<<"BOUNDARY";
            }
        }
        cout<<endl;
    }
    
    // cout << fixed << setprecision(10);   // si imprimes ld

    return 0;
}