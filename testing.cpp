//
// Created by 16107 on 9/28/2022.
//
#include <iostream>
#include "Helper.h"
#include "Chore.h"
#include "Schedule.h"
using namespace std;


bool test_Helper();
bool test_Chore();
bool test_Errand();
bool test_Activity();
bool test_Schedule();

// main program to call functions to test all classes in order of what is used - components then schedule class
int main() {
    if (test_Helper()){
        cout << "Passed all Helper tests" << endl;
    }
    if (test_Activity()) {
        cout << "Passed all Test tests" << endl;
    }
    if (test_Chore()){
        cout << "Passed all Chore tests" << endl;
    }
    if (test_Errand()) {
        cout << "Passed all Errand tests" << endl;
    }
    if (test_Schedule()) {
        cout << "Passed all Schedule tests" << endl;
    }
    return 0;
}

// tests helper objects
bool test_Helper() {
    Helper h1;
    bool passed = true;
    if (h1.getName() != " ") {
        cout << "Failed getName() default constructor test" << endl;
        passed = false;
    }
    string test = "test";
    h1.setName(test);
    if (h1.getName() != test) {
        cout << "Failed setName() test" << endl;
        passed = false;
    }
    if (!h1.getDownstairs()) {
        cout << "Failed getDownstairs() default constructor test" << endl;
        passed = false;
    }
    h1.setDownstairs(false);
    if (h1.getDownstairs()) {
        cout << "Failed setDownstairs() test" << endl;
        passed = false;
    }
    if (h1.getChoreMinutes() != 0) {
        cout << "Failed getChoreMinutes() default constructor test" << endl;
        passed = false;
    }
    h1.setChoreMinutes(2);
    if (h1.getChoreMinutes() != 2) {
        cout << "Failed setChoreMinutes() test" << endl;
        passed = false;
    }
    if (h1.getNumChores() != 0) {
        cout << "Failed getNumChores() default constructor test" << endl;
        passed = false;
    }
    h1.setNumChores(7);
    if (h1.getNumChores() != 7) {
        cout << "Failed setNumChores() test" << endl;
        passed = false;
    }
    return passed;
}
// tests activities
bool test_Activity() {
    bool passed = true;
    Activity a1;
    if (a1.getTitle() != " ") {
        cout << "Failed getTitle() default constructor test" << endl;
        passed = false;
    }
    if (a1.getTime() != 0) {
        cout << "Failed getTime() default constructor test" << endl;
        passed = false;
    }
    if (a1.getPlace() != neutral) {
        cout << "Failed getPlace() default constructor test" << endl;
        passed = false;
    }
    a1.setTitle("activity test");
    a1.setTime(4);
    a1.setPlace(up);
    if (a1.getTitle() != "activity test") {
        passed = false;
        cout << "Failed setTitle() test" << endl;
    }
    if (a1.getTime() != 4) {
        passed = false;
        cout << "Failed setTime() test" << endl;
    }
    if (a1.getPlace() != up) {
        passed = false;
        cout << "Failed setPlace() test" << endl;
    }
    // describe test
    string expectedString = a1.getTitle() + " takes " + to_string(a1.getTime()) + " minutes";
    if (a1.describe() != expectedString) {
        passed = false;
        cout << "Failed describe() test" << endl;
    }
    // test overloaded == operator
    Activity a2("activity test", 4, up);
    if (!(a1 == a2)) {
        passed = false;
        cout << "Failed == overloaded operator test" << endl;
    }
    return passed;
}

// then tests child class chore
bool test_Chore() {
    bool passed = true;
    Chore c1;
    if (c1.getTimeline() != 7) {
        cout << "Failed getTimeLine() default constructor test" << endl;
        passed = false;
    }
    if (c1.getThisWeek()) {
        cout << "Failed getThisWeek() default constructor test" << endl;
        passed = false;
    }
    Chore c2("test chore", 5, down);
    c2.setTitle("test chore2");
    if (c2.getTitle() != "test chore2") {
        cout << "Failed setTitle() test" << endl;
        passed = false;
    }
    c2.setTime(8);
    if (c2.getTime() != 8) {
        cout << "Failed setTIme() test" << endl;
        passed = false;
    }
    c2.setPlace(up);
    if (c2.getPlace() != up) {
        cout << "Failed setPlace() test" << endl;
        passed = false;
    }
    c2.setTimeline(14);
    if (c2.getTimeline() != 14) {
        cout << "Failed setTimeline() test" << endl;
        passed = false;
    }
    c2.setThisWeek(true);
    if (!c2.getThisWeek()) {
        cout << "Failed setThisWeek() test" << endl;
        passed = false;
    }
    Chore c3("title", 4, down);
    Chore c4("title", 4, down);
    if (!(c3 == c4)) {
        cout << "Failed overloaded operator == test" << endl;
        passed = false;
    }
    // setUTitle, setUTime, and setUPlace are all tested in main
    return passed;
}

// tests other activity child class errand
bool test_Errand() {
    bool passed = true;
    Errand e1;
    if (e1.getTitle() != " ") {
        cout << "Failed getTitle() default constructor test" << endl;
        passed = false;
    }
    if (e1.getTime() != 0) {
        cout << "Failed getTime() default constructor test" << endl;
        passed = false;
    }
    if (e1.getPlace() != neutral) {
        cout << "Failed getPlace() default constructor test" << endl;
        passed = false;
    }
    Errand e2;
   e2.setCost(20.00);
   e2.setTotal(10);
   e2.setRemaining(3);
    if (e2.getCost() != 20.00) {
        cout << "Failed setCost and getCost test" << endl;
        passed = false;
    }
    if (e2.getTotal() != 10) {
        cout << "Failed setTotal and getTotal test" << endl;
        passed = false;
    }
    if (e2.getRemaining() != 3) {
        cout << "Failed setRemaining and getRemaining test" << endl;
        passed = false;
    }
    return passed;
}

// finally tests schedule which uses all previously tested classes
bool test_Schedule() {
    bool passed = true;
    Schedule s2;
    if (s2.getPeople().size() != 0) {
        cout << "Failed default constructor and getPeople() test" << endl;
        passed = false;
    }
    if (s2.getActivities().size() != 0) {
        cout << "Failed default constructor and getActivites() test" << endl;
        passed = false;
    }
    if (s2.generateSchedule().size() != 0) {
        cout << "Failed default constructor and generateSchedule test" << endl;
        passed = false;
    }
    Helper h1("h1", true);
    Helper h2("h2", false);
    Helper h3("h3", true);
    vector<Helper> peopleVec = {h1, h2, h3};
    s2.setPeople(peopleVec);
    for (int i = 0; i < peopleVec.size(); ++i) {
        if (!(s2.getPeople()[i] == peopleVec[i])){
            cout << "Failed setPeople test" << endl;
            passed = false;
        }
    }
    Activity a1("a1", 3, up);
    Chore c1("c1", 4, down);
    Errand e1("e1", 90, neutral);
    vector<Activity> activityVec = {a1, c1, e1};
    s2.setActivities(activityVec);
    for (int i = 0; i < activityVec.size(); ++i) {
        if (!(s2.getActivities()[i] == activityVec[i])){
            cout << "Failed setActivities test" << endl;
            passed = false;
        }
    }
    vector<vector<string>> expectedPairs;
    expectedPairs = {{"a1", "h1"}, {"c1", "h2"}, {"e1", "h3"}};
    if (s2.generateSchedule() != expectedPairs) {
        cout << "Failed generate schedule test" << endl;
        passed = false;
    }
    if (s2.getPairs() != expectedPairs) {
        cout << "Failed getPairs() test" << endl;
        passed = false;
    }
    // specific helper chore pair
    string result = s2.specificHelperChore(h1, c1);
    if (result != "c1 is now paired with h1") {
        cout << "Failed string return test of specificHelperChore" << endl;
        passed = false;
    }
    vector<string> expected = {"c1", "h1"};
    if (s2.getPairs()[1] != expected){
        cout << "Failed specificHelperChore test" << endl;
        passed = false;
    }
    // specific helper chore pair with a chore that does not exist
    Chore c2;
    result = s2.specificHelperChore(h1, c2);
    if (result != "no such activity") {
        cout << "Failed specificHelperChore with invalid chore test" << endl;
        passed = false;
    }
    // specific helper chore pair with a helper that does not exist
    Helper h7("h7", true);
    result = s2.specificHelperChore(h7, e1);
    if (result != "no such helper") {
        cout << "Failed specificHelperChore with invalid helper test" << endl;
        passed = false;
    }
    // cout and output to file tested in main
    return passed;
}