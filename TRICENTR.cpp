#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;
int main() {
int t; 
scanf("%d", &t);
while (t--) {
double a, b, c, da, db, dc, s, r, m;
scanf("%lf%lf%lf%lf", &a, &da, &db, &dc);
s = 3.0*a*da/2.0;	//s is area
b = 2.0*s/3.0/db;	//side b
c = 2.0*s/3.0/dc;	//side c
r = a*b*c/4.0/s;	//incentre radius
m = 4.0*(r*r-(a*a+b*b+c*c)/9.0);
m = max(0.0, m);
printf("%.3lf %.3lf\n", s, sqrt(m));
}
return 0;
} 
