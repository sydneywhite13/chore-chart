//
// Created by 16107 on 9/28/2022.
//
#ifndef M2OEP_SWHITE25_ACTIVITY_H
#define M2OEP_SWHITE25_ACTIVITY_H

# include <iostream>
using namespace std;

enum downstairs{
    down,
    up,
    neutral
};

class Activity {
protected:
    string title;
    int time;
    downstairs place;
public:
    // constructors
    Activity();
    Activity(string title, int time, downstairs place);

    // getters
    string getTitle();
    int getTime();
    downstairs getPlace();

    // setters
    void setTitle(string title);
    void setTime(int time);
    void setPlace(downstairs place);

    // describe in case title is not descriptive enough
    string describe();

    // overloaded == operator for searching and comparing
    friend bool operator == (Activity& lhs, Activity& rhs);

    // get user input for title, time, and place if they choose to add activities
    void setUTitle();
    void setUTime();
    void setUPlace();
};
#endif //M2OEP_SWHITE25_ACTIVITY_H
