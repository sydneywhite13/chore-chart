//
// Created by 16107 on 9/17/2022.
//

#include "Schedule.h"
#include <iostream>
#include <fstream>
using namespace std;

Schedule:: Schedule() {
    vector<Helper> people = {};
    // set this to the default from the file
    vector<unique_ptr<Activity>> activities = {};
    // string pairs of activity title and chore name
    vector<vector<string>> pairs = {};
}

Schedule:: Schedule(vector<Helper> people, vector<Activity> activities) {
    this->people = people;
    this-> activities = activities;
    pairs = generateSchedule();
}

vector<Helper> Schedule::getPeople(){
    return people;
}
vector<Activity> Schedule::getActivities(){
    vector<Activity> activitiesNonPointer;
    for (int i = 0; i < activities.size(); ++i) {
        activitiesNonPointer.push_back(activities[i]);
    }
    return activitiesNonPointer;
}
void Schedule::setPeople(vector<Helper> people){
    this->people = people;
}
void Schedule::setActivities(vector<Activity> activities){
    this->activities = activities;
}

// write a function to allow you to change the person responsible for one of the chores by chore name

// and by chore index

vector<vector<string>>  Schedule::generateSchedule(){
    // if there are more people than activities
    if (people.size () >= activities.size()) {
        // use activities for the loop because people is bigger and just use the first c people (for now)
        for (int c = 0; c < activities.size(); ++c) {
            //for each chore, for each helper
            // write the chore and helper as a pair in the vector
            pairs.push_back({activities[c].getTitle(), people[c].getName()});
            }
        }
    // if there is more than one person but less than the number of activities
    else if (people.size() > 1) {
        // fill up chore[c] to helper[c] until c runs out (then restart?)
        // if we have less people than chores, but still more than 1
        // for every helper, assign them that chore
        for (int h = 0; h < people.size(); ++h) {
            pairs.push_back({activities[h].getTitle(), people[h].getName()});
        }
        for (int c = people.size(); c < activities.size(); ++c) {
            pairs.push_back({activities[c].getTitle(), people[c % people.size()].getName()});
        }
    }
    // else - there is only one helper
    else {
        for (int c = 0; c < activities.size(); ++c ){
            //pairs[c] = {chores[c].getTitle(), people[0].getName()};
            pairs.push_back({activities[c].getTitle(), people[0].getName()});
        }
    }
    return pairs;
}


vector<vector<string>> Schedule::getPairs(){
    return pairs;
}

// function to manually give a specific user a specific chore
string Schedule:: specificHelperChore(Helper helper, Activity activity) {
    //search through vector chore to get index
    int index = -1;
    for (int i = 0; i < activities.size(); ++i) {
        if (activities[i] == activity) {
            index = i;
        }
    }
    // check that helper also exists
    bool personExists = false;
    for (int i = 0; i < people.size(); ++i) {
        if (people[i] == helper){
            personExists = true;
        }
    }
    if (personExists && index > 0) {
        // set the second (i = 1) index of that index of the vector schedule to given helper.getName()
        pairs[index][1] = helper.getName();
        return (pairs[index][0] + " is now paired with " + pairs[index][1]);
    }
    else if (index < 0) {
        return "no such activity";
    }
    else {
        return "no such helper";
    }

}

ostream& operator << (ostream& outs, Schedule schedule){
    // vector of vectors of strings
    // go through vector - for each vector in the vector
    cout << "Here is the schedule: " << endl;
    for (int i = 0; i < schedule.getPairs().size(); ++i) {
        cout << schedule.getPairs()[i][0] << ": " << schedule.getPairs()[i][1] << endl;
    }
    // print the chore : the person responsible
}

// outputs schedule to file and returns filename to print to console
string Schedule::outputToFile() {
    ofstream f_out;
    string filename = "../Schedule.csv";
    f_out.open(filename);
    f_out << "Activity" << "," << "Helper" << endl;
    for (int i = 0; i < pairs.size(); i++) {
        f_out << pairs[i][0] << "," << pairs[i][1] << endl;
    }
    return filename;
}