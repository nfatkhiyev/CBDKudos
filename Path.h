#include <vector>
#include <tuple>
#include <math.h>
#include <stdio.h>
#include <stdarg.h>
#include <Waypoint.h>

#ifndef PATH_H
#define PATH_H
class Path{
    public:
        Path(int n, Waypoint point ...);
        std::vector<Waypoint> generateCurve(int index, int lookahead);
        void setCurveResolution(int resolution);
};
#endif