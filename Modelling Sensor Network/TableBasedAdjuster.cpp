#include "TableBasedAdjuster.h"
using namespace std;
TableBasedAdjuster& TableBasedAdjuster::addBreakpoint(float x, float y) {

    breakpoints.insert(make_pair(x,y));
    return *this;
}

float TableBasedAdjuster::adjust(float value) const {
    if (breakpoints.empty())
    { return value;}
    else{
        float k_min = breakpoints.begin()->first;
        float k_max = breakpoints.rbegin()->first;
        float v_min = breakpoints.begin()->second;
        float v_max = breakpoints.begin()->second;

        if(value <= k_min)
        {return std::round((v_min - (k_min - value))* 10.0)/10.0;}

        else if (value >= k_max)
        {return std::round((v_max + (value - k_max)) * 10.0)/10.0;}

        else
        {
            for(auto it=breakpoints.begin();it!=breakpoints.end();it++)
            {
                auto Next_it = next(it);
                if (Next_it!=breakpoints.end())
                {   float k_n = it->first;
                    float v_n = it->second;
                    float k_n1 = Next_it->first;
                    float v_n1 = Next_it->second;

                    if ( (k_n < value) && (value<= k_n1))
                       {return   std::round(((value - k_n) / (k_n1 - k_n) * (v_n1 - v_n) + v_n) * 10.0)/10.0;}
                }
            }

        }

    }
    return value;

}
