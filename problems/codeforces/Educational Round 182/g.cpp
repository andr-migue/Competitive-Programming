#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

typedef pair<long double, long double> point;
#define x first
#define y second

struct Rect {
    long double a, b, c;

    Rect(long double a_, long double b_, long double c_)
    : a(a_), b(b_), c(c_) {}
};


Rect get_m(point p1, point p2) {
    point v = {p2.x - p1.x, p2.y - p1.y};
#define a v.x
#define b v.y
    point midpoint = {(p1.x + p2.x) / 2.0, (p1.y + p2.y) / 2.0};

    long double A = b;
    long double B = -a;
    long double C = b * midpoint.x - a * midpoint.y;

#undef a
#undef b

    return Rect(A, B, C);
}

bool is_collinear(point a, point b, point c) {
    return a.x * b.y - b.x * a.y;
}

bool has_solution(Rect m1, Rect m2, Rect md) {
    return fabs(m1.a * m2.b * md.c
        + m2.a * md.b * m1.c
        + md.a * m1.b * m2.c
        - md.a * m2.b * m1.c
        - md.b * m2.c * m1.a
        - md.c * m2.a * m1.b) < 1E-9;
}

int main() {
    while (true) {
        int n;
        cin >> n;

        if (n == 0)
            break;

        vector<point> points(n);
        for (int i = 0; i < n; i++) {
            long double x, y;
            cin >> x >> y;

            points.push_back({x, y});
        }

        int ans = 0;
        for (int i = 0; i < n; i++) for (int j = i + 1; j < n; j++) for (int k = j + 1; k < n; k++) {
            if (is_collinear(points[i], points[j], points[k]))
                continue;

                Rect m1 = get_m(points[i], points[j]);
                Rect m2 = get_m(points[i], points[k]);

                int s = 3;
                for (int d = k + 1; d < n; d++) {
                    Rect md = get_m(points[i], points[d]);

                    if (has_solution(m1, m2, md))
                        s++;
                }

                ans = max(ans, s);
        }

        cout << ans << "\n";
    }

    return 0;
}