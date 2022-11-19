//
// Created by 16107 on 9/28/2022.
//

#ifndef M2OEP_SWHITE25_ERRAND_H
#define M2OEP_SWHITE25_ERRAND_H
#include "Activity.h"

class Errand: public Activity {
private:
    float cost;
    int total;
    int remaining;
public:
    // constructors
    Errand();
    Errand(string title, int time, downstairs place);
    Errand(float cost, int total, int remaining);
    Errand(string title, int time, downstairs place, float cost, int total, int remaining);

    // getters
    float getCost();
    int getTotal();
    int getRemaining();

    // setters
    void setCost(float cost);
    void setTotal(int total);
    void setRemaining(int remaining);

    // describes errand if title is not descriptive enough
    string describe();

    // methods to get user input for cost, total, and remaining if they choose to add more errands
    void setUCost();
    void setUTotal();
    void setURemaining();
};


#endif //M2OEP_SWHITE25_ERRAND_H
