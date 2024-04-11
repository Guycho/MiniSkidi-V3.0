namespace Utils{
    double map_double(double x, double in_min, double in_max, double out_min, double out_max)
    {
        return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
    }
    double constrain_double(double x, double min, double max){
        if (x < min){
            x = min;
        }
        else if (x > max)
        {
            x = max;
        }
        return x;
    }
}