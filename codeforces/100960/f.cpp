#include <bits/stdc++.h>
using namespace std;
#define ll long long

template <class T> int sgn(T x) { return (x > 0) - (x < 0); }
template <class T>
struct Point {
    typedef Point P;
    T x, y;
    explicit Point(T x = 0, T y = 0): x(x), y(y) {}
    bool operator<(P p) const { return tie(x, y) < tie(p.x, p.y); }
    bool operator==(P p) const { return tie(x, y) == tie(p.x, p.y); }
    P operator+(P p) const { return P(x + p.x, y + p.y); }
    P operator-(P p) const { return P(x - p.x, y - p.y); }
    P operator*(T d) const { return P(x * d, y * d); }
    P operator/(T d) const { return P(x / d, y / d); }
    T dot(P p) const { return x * p.x + y * p.y; }
    T cross(P p) const { return x * p.y - y * p.x; }
    T cross(P a, P b) const { return (a-*this).cross(b-*this); } // basically ccw (a, this, b)
    T dist2() const { return x * x + y * y; }
    double dist() const { return sqrt((double)dist2()); }
    double angle() const { return atan2(y, x); }
    P unit() const { return *this/dist(); }
    P perp() const { return P(-y, x); }
    P normal() const { return perp().unit(); }
    P rotate(double a) const {
        return P(x * cos(a) - y * sin(a), x * sin(a) + y * cos(a)); }
    friend ostream& operator<<(ostream& os, P p) {
        return os << "(" << p.x << "," << p.y << ")"; }
};

typedef Point<long long> P;
ll dist2(P& a, P& b) { // squared distance
    long long x = a.x - b.x;
    long long y = a.y - b.y;
    return x * x + y * y;
}


/*
 * to efficiently cycle between all possibilities
 * consider that our sword is two perpendicular segments that must cover three points.
 * therefore, any solution must have >= 2 points on either the blade or the hilt.
 * we can therefore cycle through each pair of points and try placing both on the blade or the hit, adjusting for the third point.
 */

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        ll lm, lg;
        cin >> lm >> lg; // length of blade, length of each guard
        
        vector<P> pts(3);
        for (int i = 0; i < 3; i++) {
            cin >> pts[i].x >> pts[i].y;
        }
        
        bool works = false;
        if (pts[0].cross(pts[1], pts[2]) == 0) {
            ll tmp = max(lm * lm, lg * lg * 4);
            ll mx = max(dist2(pts[0], pts[1]), max(dist2(pts[1], pts[2]), dist2(pts[0], pts[2])));
            if (tmp >= mx) works = true;
        }
        
        for (int i = 0; i < 3; i++) {
            // pts a and b are the ones we place together
            P a = pts[i], b = pts[(i + 1) % 3], c = pts[(i + 2) % 3]; 

            // try using a and b on hilt.
            bool possible = 1;
            ll a1 = a.y - b.y, b1 = b.x - a.x; // perpendicular segment to (a, b)
            ll c1 = -a1 * a.x - b1 * a.y; // directional vector for c.
                                          
            ll tmp = (a1 * c.x + b1 * c.y + c1) * (a1 * c.x + b1 * c.y + c1); // squared dist between c and the line, scaled by tmp2
            ll tmp2 = (a1 * a1 + b1 * b1); // squared length of a and b
            if (lm * lm * tmp2 < tmp) possible = 0; // length of blade must exceeds distance of c to (a, b)
            if (dist2(a, c) * tmp2 - tmp > lg * lg * tmp2) possible = 0; // dist of intersection must not exceed lg
            if (dist2(b, c) * tmp2 - tmp > lg * lg * tmp2) possible = 0; // dist of intersection must not exceed lg 
            if (possible) works = true;

            possible = 1;
            
            // a and b on blade
            
            // check if at least one angle at a, b is obtuse
            if (dist2(a, b) + dist2(a, c) - dist2(b, c) > 0 && dist2(a, b) + dist2(b, c) - dist2(a, c) > 0) possible = 0;
            if (lg * lg * tmp2 < tmp) possible = 0; // dist of c from (a, b) must not exceed lg
            if (dist2(a, c) * tmp2 - tmp > lm * lm * tmp2) possible = 0; // dist from a to hilt cannot exceed lm
            if (dist2(b, c) * tmp2 - tmp > lm * lm * tmp2) possible = 0; // dist from b to hilt must not exceed lm
            if (possible) works = true;
        }

        cout << (works ? "YES" : "NO") << '\n';
    }
}


                


