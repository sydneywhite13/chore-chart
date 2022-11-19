//
// Created by 16107 on 9/15/2022.
//

#ifndef M1AP_CHORE_H
#define M1AP_CHORE_H
#include <iostream>
#include <vector>
#include "Activity.h"
using namespace std;

class Chore : public Activity{
private:
    int timeline;
    bool thisWeek;
public:
    // cosntructor
    Chore();

    Chore(string title, int time, downstairs place);

    Chore(string title, int time, downstairs place, int timeline);

    // getters
    int getTimeline() const;
    bool getThisWeek() const;

    // setters
    void setTimeline(int timeline);
    void setThisWeek(bool thisWeek);

    friend ostream& operator << (ostream& outs, Chore chore);
    friend bool operator == (Chore& lhs, Chore& rhs);

    // function to get timeline from user if they are inputting more chores
    void setUTimeline();

    // function to describe a chore if the title is not descriptive enough
    string describe();
};
#endif //M1AP_CHORE_H
