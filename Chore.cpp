//
// Created by 16107 on 9/15/2022.
//

#include "Chore.h"
#include <iomanip>
using namespace std;

Chore::Chore() : Activity(), timeline(7), thisWeek(false) {
}

Chore::Chore(string title, int time, downstairs place) : Activity(title,time, place),  timeline(7), thisWeek(false) {
}

Chore::Chore(string title, int time, downstairs place, int timeline) : Activity(title,time, place),  timeline(timeline), thisWeek(false) {
}

// getters
int Chore::getTimeline() const{
    return timeline;
}
bool Chore::getThisWeek() const{
    return thisWeek;
}

// setters
void Chore::setTimeline(int timeline){
    this->timeline = timeline;
}
void Chore::setThisWeek(bool thisWeek){
    this->thisWeek = thisWeek;
}

ostream& operator << (ostream& outs, Chore chore) {
    outs << left << setw(25) << chore.getTitle();
    outs << left << setw(4) << chore.getTime() << "minutes " ;
    string placeS;
    if (chore.getPlace() == up) {
        placeS = "upstairs";
    }
    if (chore.getPlace() == down) {
        placeS = "downstairs";
    }
    else {
        placeS = "neutral";
    }
    outs << setw(10) << placeS;
    outs << setw(2) << chore.getTimeline() << " days";
    return outs;
}

bool operator == (Chore& lhs, Chore& rhs){
    return (lhs.getTitle() == rhs.getTitle()) and (lhs.getTime() == rhs.getTime()) and (lhs.getPlace() == rhs.getPlace()) and (lhs.getTimeline() == rhs.getTimeline());
    // time place and timeline
}

string Chore::describe() {
    string returnString;
    returnString.append(title);
    returnString.append(" is a chore that");
    if (place = up) {
        returnString.append("must be done upstairs");
    }
    if (place = down) {
        returnString.append("must be done downstairs");
    }
    else {
        returnString.append("must be done");
    }
    returnString.append("every" +to_string(timeline) + " days and has");
    if (thisWeek) {
        returnString.append("been done this week.");
    }
    else {
        returnString.append("not been done this week.");
    }
    return returnString;
}

void Chore::setUTimeline(){
    int timeline;
    cout << "How often does this chore need to be done (in days)? "<< endl;
    cin >> timeline;
    setTimeline(timeline);
}