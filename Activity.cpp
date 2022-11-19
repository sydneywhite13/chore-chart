//
// Created by 16107 on 9/28/2022.
//

#include "Activity.h"
using namespace std;

Activity:: Activity(){
    title = " ";
    time = 0;
    place = neutral;
}
Activity::Activity(string title, int time, downstairs place){
    this->title = title;
    this-> time = time;
    this->place = place;
}

// getters
string Activity::getTitle(){
    return title;
}
int Activity::getTime(){
    return time;
}
downstairs Activity::getPlace(){
    return place;
}

// setters
void Activity::setTitle(string title){
    this->title = title;
}
void Activity:: setTime(int time){
    this->time = time;
}
void Activity::setPlace(downstairs place){
    this->place = place;
}

string Activity:: describe() {
    return title + " takes " + to_string(time) + " minutes";
}

bool operator == (Activity& lhs, Activity& rhs){
    return (lhs.getTitle() == rhs.getTitle()) and (lhs.getTime() == rhs.getTime()) and (lhs.getPlace() == rhs.getPlace());
}

void Activity::setUTitle(){
    // doesn't allow for spaces and is funky inside while loop
    string input;
    string junk;
    //fix this so you don't need it (remove new line character from cin)
    getline(cin, junk);
    cout << "Enter activity name: ";
    getline(cin, input);
    bool nameness;
    nameness = true;
    // names must be alphabetical
    for (int i = 0; i < input.length(); ++i) {
        if (!isalpha(input[i]) and !isspace(input[i])) {
            nameness = false;
        }
    }
    while (!cin or !nameness) {
        getline(cin, junk);
        cout << "Invalid input. Names may only contain alphabet letters. Enter chore's name as a string: ";
        getline(cin, input);
        for (int i = 0; i < input.length(); ++i) {
            if (!isalpha(input[i]) and !isspace(input[i])) {
                nameness = false;
            }
        }
    }
    setTitle(input);
}
void Activity::setUTime(){
    cin.clear();
    int time;
    cout << "Enter the time this activity takes in minutes: ";
    cin >> time;
    // add some validation for maximum integer (120)
    while (!cin) {
        cout << "Invalid input. Please enter an integer: ";
        cin >> time;
    }
    setTime(time);
}
void Activity::setUPlace(){
    // infinite loop somewhere
    downstairs place;
    char choice;
    cout << "Is this activity upstairs, downstairs, or shared? Enter a char 'u', 'd', or 'n' for neutral: ";
    cin >> choice;
    while (choice != 'u' and choice != 'd' and choice != 'n'){
        string junk;
        getline(cin, junk);
        cout << "Please enter 'u', 'd' or 'n' (upstairs, downstairs, or neutral): ";
        cin >> choice;
    }
    if (choice == 'u') {
        setPlace(up);
    }
    if (choice == 'd') {
        setPlace(down);
    }
    if (choice == 'n') {
        setPlace(neutral);
    }
}
