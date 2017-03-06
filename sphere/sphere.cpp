/* sphere.cpp
 * Experimental solution for sphere tetrahedron problem
 *
 * Pick 4 points arbitrarily from the surface of a sphere. What
 * is the probability that the tetrahedron defined by these points
 * encloses the sphere's centre?
 */
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <random>
#include <utility>

using namespace std;

# define PI 3.141592653589793238462643383279502884L

random_device rd;
mt19937 gen(rd());
uniform_real_distribution<> dis(0, 1);

long double dih(long double a, long double b, long double c) {
    return acos((cos(a) - cos(b) * cos(c)) / (sin(b) * sin(c)));
}

bool pick() {
    long double t = dis(gen) * PI;
    long double u = dis(gen) * 2 * PI;
    long double v = acos(2 * dis(gen) - 1);

    long double c = t;
    long double b = acos(cos(u) * cos(v));
    long double a = acos(cos(u) * cos(v - t));

    long double A = dih(a, b, c);
    long double B = dih(b, c, a);
    long double C = dih(c, a, b);

    long double area = A + B + C;
    
    if (area > 3 * PI)
        area = 6 * PI - area;

    area -= PI;
    area /= 4 * PI;

    long double prob = dis(gen);
    return prob < area;
}

int main() {
    int trials = 1000000;
    int count = 0;

    for (int i = 0; i < trials; i++)
        if (pick()) count++;

    printf("%f\n", (double) count / trials);
}
