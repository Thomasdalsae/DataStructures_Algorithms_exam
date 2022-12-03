

enum Day {sun,mon,tue,wed,thu,fri,sat };
Day operator++(Day& d)
{
    return d = (sat==d) ? sun : Day(d+1);
}