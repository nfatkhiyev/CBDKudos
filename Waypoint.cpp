#include <tuple>
#include <Waypoint.h>

class Waypoint{
    float xCoordinate;
    float yCoordinate;
    Waypoint(float x, float y){
        xCoordinate = x;
        yCoordinate = y;
    }

    std::tuple<float, float> getWaypoint(){
        std::tuple<float, float> waypoint = {xCoordinate, yCoordinate};
        return waypoint;
    }

    float getXCoordinate(){
        return xCoordinate;
    }

    float getYCoordinate(){
        return yCoordinate;
    }
};