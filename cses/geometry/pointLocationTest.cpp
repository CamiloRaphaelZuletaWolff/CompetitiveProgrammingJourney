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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    
    // freopen("../../input.txt", "r", stdin);
    // freopen("../../output.txt", "w", stdout);
    

    ll t; cin >>t; 

    while (t--)
    {
        P a,b,c; cin>>a>>b>>c;
        ll x = sgn(a.cross(b,c)); 
        if(x == 0){
            cout<< "TOUCH";
        }else{
            if(x >= 1){
                cout<<"LEFT";
            }else{
                cout<<"RIGHT";
            }
        }
        cout<<endl;

        
    }
    
    // cout << fixed << setprecision(10);   // si imprimes ld

    return 0;
}
// ============================== FIN MAIN ==============================