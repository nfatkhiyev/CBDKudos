#include <Path.h>

class Path{

    private:

    float curveResolution = 0.05;

    std::vector<Waypoint> rawWaypoints;

    Path(int n, Waypoint points ... ){
        rawWaypoints.push_back(points);
    }

    std::vector<Waypoint> generateCurve(int index, int lookAhead){
        const int n = lookAhead;
        int tInterval = curveResolution*1;

        std::vector<Waypoint> controlPoints;

        for(int i = 0 ; i < n + 1 ; i++){
            controlPoints.push_back(rawWaypoints[index + i]);
        }

        std::vector<Waypoint> curvePoints;

        for(int t = 0 ; t <= 1 ; t = t+tInterval){
            for(int i = 0 ; i <= n ; i++){
                float x = controlPoints[i].getXCoordinate*combination(n, i)*pow(t, i)*pow(1-t, n-i);
                float y = controlPoints[i].getYCoordinate*combination(n, i)*pow(t, i)*pow(1-t, n-i);
                Waypoint point = Waypoint(x,y);
                curvePoints.push_back(point);
            }
        }

        return curvePoints;
    }

    void setCurveResolution(int resolution){
        if (resolution > 0 && resolution <= 1){
            curveResolution = resolution*0.1;
        }
        else {
            curveResolution = 0.05;
        }
    }

    int factorial(int number){
        for(int i = 1 ; i <= number ; i++){
            number = number * (number - i);
        }
        return number;
    }

    float combination(int n, int i){
        float combination =
            factorial(n)/(factorial(i) * factorial(n-1));
        return combination;
    }
};
