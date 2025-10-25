#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;

vector<pii> p(4);
vector<pii> q(4);

vector<pair<pii, ll>> plines;
vector<pair<pii, ll>> qlines;



pair<pii, ll> ptl(pii one, pii two) {
    if(one.first == two.first) { // x1 == y1
        return make_pair(make_pair(1, 0), -one.first);
    }
    if(one.second == two.second) { // x2 == y2
        return make_pair(make_pair(0, 1), -one.second);
    }
    ll a1 = two.second-one.second;
    ll b1 = one.first-two.first;
    ll c1 = -one.first*a1 - one.second*b1;
    return make_pair(make_pair(a1, b1), c1);
}

pii check(pair<pii, ll>& tline, pii& one, pii& two, bool& found, bool& within) {
    ll t1 = one.first*tline.first.first + one.second*tline.first.second + tline.second; // x1*a + y1*b + c
    ll t2 = two.first*tline.first.first + two.second*tline.first.second + tline.second; // x2*a + y2*b + c
    if(t1 == 0) {
        found = true;
        if(t2 == 0) {
            within = true;
        }
        return one;
    }
    if(t2 == 0) {
        found = true;
        return two;
    }

    found = false;
    within = (t1*t2 < 0);

    return make_pair(-1, -1);

}

bool same(pair<pii, ll>& t1, pair<pii, ll>& t2) {
    if(t1.second*t2.first.first == t2.second*t1.first.first && t1.second*t2.first.second == t2.second*t1.first.second) {
        return true;
    }
    return false;
}

ostream& operator<<(ostream& o, const pii& p) {
    o << p.first << " " << p.second;
    return o;
}

int main() {

    ifstream cin("equal-squares.in");
    ofstream cout("equal-squares.out");

    ll x1, y1, x2, y2, x3, y3, x4, y4;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
    x1 *= 2;
    y1 *= 2;
    x2 *= 2;
    y2 *= 2;
    x3 *= 2;
    y3 *= 2;
    x4 *= 2;
    y4 *= 2;

    p[0] = make_pair(x1, y1);
    p[2] = make_pair(x2, y2);
    q[0] = make_pair(x3, y3);
    q[2] = make_pair(x4, y4);

    // compute other corners

    ll mx = (x2 + x1)/2;
    ll my = (y2 + y1)/2;
    ll dx = (x2 - x1)/2;
    ll dy = (y2 - y1)/2;
    
    p[1] = make_pair(mx + dy, my - dx);
    p[3] = make_pair(mx - dy, my + dx);

    mx = (x4 + x3)/2;
    my = (y4 + y3)/2;
    dx = (x4 - x3)/2;
    dy = (y4 - y3)/2;

    q[1] = make_pair(mx + dy, my - dx);
    q[3] = make_pair(mx - dy, my + dx);

    // find lines of squares

    for(int i = 0; i<4; i++) {
        ll j = (i+1)%4;
        plines.push_back(ptl(p[i], p[j]));
        qlines.push_back(ptl(q[i], q[j]));
        // cout << "p" << i << ": " << p[i].first << " "  << p[i].second << " : q" << i << ": " << q[i].first << " " << q[i].second << endl; 
    }
    // cout << endl;

    // find tlines 

    set<pair<pii, ll>> tlines;

    for(int i = 0; i<4; i++) {
        for(int j = 0; j<4; j++) {
            if(p[i] == q[j]) {
                // points are the same, if neither of the segments are the same then there are infinite solutions.
                // if segment is same, it shares both points bc side length of squares is exactly the same. 
                int i1 = (i+1)%4;
                int i2 = (i+3)%4;
                int j1 = (j+1)%4;
                int j2 = (j+3)%4;
                // cout << p[i1] << " " << p[i2] << " " << q[j1] << " " << q[j2] << endl;
                if(p[i1] == q[j1] || p[i2] == q[j1] || p[i1] == q[j2] || p[i2] == q[j2]) {
                    continue;
                }
                else {
                    cout << "Infinity" << endl;
                    return 0;
                }
            }
            pair<pii, ll> t = ptl(p[i], q[j]);
            // cout << i << " " << j << ": " << t.first.first << " " << t.first.second << " " << t.second << endl;


            // keep track of which points intersect line: this set cannot get bigger than 2.
            set<pii> intp;
            vector<bool> ip(4, false);
            bool reject = false;
            for(int k = 0; k<4; k++) {
                bool found = false;
                bool within = false;
                pii temp = check(t, p[k], p[(k+1)%4], found, within);
                if(found) {
                    if(within) {
                        intp.insert(p[k]);
                        intp.insert(p[(k+1)%4]);
                        ip[k] = true;
                        ip[(k+1)%4] = true;
                    }    
                    else {
                        intp.insert(temp);
                        if(temp == p[k]) ip[k] = true;
                        else ip[(k+1)%4] = true;
                    }
                }
                else { // does not intersect either point; either in segment or outside of segment.
                    if(within) {
                        reject = true;
                        break;
                    }
                }
                if(intp.size() > 2) {
                    cout << "what the heck" << endl;
                    reject = true;
                    break;
                }
            }
            if(reject) continue;
            if(ip[0] && ip[2]) continue;
            if(ip[1] && ip[3]) continue;

            set<pii> intq;
            vector<bool> iq(4, false); // which points of square does line intersect
            for(int k = 0; k<4; k++) {
                bool found = false;
                bool within = false;
                pii temp = check(t, q[k], q[(k+1)%4], found, within);
                if(found) {
                    if(within) {
                        intq.insert(q[k]);
                        intq.insert(q[(k+1)%4]);
                        iq[k] = true;
                        iq[(k+1)%4] = true;
                    }    
                    else {
                        intq.insert(temp);
                        if(temp == q[k]) iq[k] = true;
                        else iq[(k+1)%4] = true;
                    }
                }
                else { // does not intersect either point; either in segment or outside of segment.
                    if(within) {
                        reject = true;
                        break;
                    }
                }
                if(intq.size() > 2) {
                    cout << "what the heck" << endl;
                    reject = true;
                    break;
                }
            }
            if(reject) continue;
            if(iq[0] && iq[2]) continue;
            if(iq[1] && iq[3]) continue;
            
            tlines.insert(t);

        }
    }

    set<pair<pii, ll>> ans;
    
    for(pair<pii, ll> tp : tlines) {
        // cout << tp.first.first << " " << tp.first.second << " " << tp.second << endl;
        
        bool unique = true;
        for(pair<pii, ll> tq : ans) {
            if(same(tp, tq)) {
                unique = false;
                break;
            }
        }
        if(unique) {
            ans.insert(tp);
            // cout << "unique" << endl;
        }
    }

    cout << ans.size() << endl;

}