#ifndef DIST_FROM_LL_HPP
#define DIST_FROM_LL_HPP

extern const double f;
extern const double a;

double deg2rad(double deg);
double hubenys_formula(double lat1, double lon1, double lat2, double lon2);
double hubenys_formula_fast(double dx, double dy, double M2, double N2);

#endif
