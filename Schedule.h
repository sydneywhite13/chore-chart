// Created by 16107 on 9/17/2022.
//

#ifndef M1AP_SCHEDULE_H
#define M1AP_SCHEDULE_H

#include "Helper.h"
#include "Chore.h"
#include "Activity.h"
#include "Errand.h"
#include <memory>

class Schedule {
private:
    vector<Helper> people;
    vector<Activity> activities;
    vector<vector<string>> pairs;
public:
    Schedule();
    Schedule(vector<Helper> people, vector<Activity> activities);
    vector<Helper> getPeople();
    vector<Activity> getActivities();
    void setPeople(vector<Helper> people);
    void setActivities(vector<Activity> activities);
    vector<vector<string>> generateSchedule();
    string specificHelperChore(Helper helper, Activity activity);
    vector<vector<string>> getPairs();
    friend ostream& operator << (ostream& outs, Schedule schedule);
    string outputToFile();

};

#endif //M1AP_SCHEDULE_H

