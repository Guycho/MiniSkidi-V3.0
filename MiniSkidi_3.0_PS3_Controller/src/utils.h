#ifndef _UTILS_H
#define _UTILS_H
namespace Utils
{
    static double map_double(double x, double in_min, double in_max, double out_min, double out_max)
    {
        return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
    }
    static double constrain_double(double x, double min, double max)
    {
        if (x < min)
        {
            x = min;
        }
        else if (x > max)
        {
            x = max;
        }
        return x;
    }

    enum DIRECTION {
        DOWN = -1,
        STATIC = 0,
        UP = 1
    };
}
#endif