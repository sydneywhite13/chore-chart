//
// Created by 16107 on 9/15/2022.
//

#include "Helper.h"
#include <vector>
#include <iomanip>

Helper::Helper(){
    name = " ";
    downstairs = true;
    vector<Chore> favoriteChores;
    vector<Chore> lastWeek;
    vector<Chore> thisWeek;
    int choreMinutes = 0;
    int numChores = 0;
}

Helper::Helper(string name, bool downstairs){
    this->name = name;
    this->downstairs = downstairs;
    vector<Chore> favoriteChores;
    vector<Chore> lastWeek;
    vector<Chore> thisWeek;
    int choreMinutes = 0;
    int numChores = 0;
}


// getters
string Helper::getName() {
    return name;
}

bool Helper::getDownstairs() {
    return downstairs;
}

vector<Chore> Helper::getFavoriteChores(){
    return favoriteChores;
}

vector<Chore> Helper::getLastWeek(){
    return lastWeek;
}

vector<Chore> Helper:: getThisWeek(){
    return thisWeek;
}

int Helper:: getChoreMinutes() {
    return choreMinutes;
}

int Helper:: getNumChores() {
    return numChores;
}

// setters

void Helper::setName(string name) {
    this->name = name;
}

void Helper::setDownstairs(bool downstairs) {
    this->downstairs = downstairs;
}

void Helper::setFavoriteChores(vector<Chore> &chores){
    favoriteChores = chores;
}

void Helper::setLastWeek(vector<Chore> &chores) {
    lastWeek = chores;
}

void Helper:: setThisWeek(vector<Chore> &chores) {
    thisWeek = chores;
}

void Helper:: setChoreMinutes(int choreMinutes) {
    this->choreMinutes = choreMinutes;
}

void Helper::setNumChores(int numChores) {
    this->numChores = numChores;
}

// function newWeek to cycle the weeks
void Helper:: newWeek() {
    setLastWeek(thisWeek);
    // set this week to an empty array
}

// function to get user inputted name and call setName
void Helper::setUName() {
    // clear whatever is there
    string junk;
    getline(cin, junk);
    string input;
    // get name
    cout << "Enter helper name: ";
    getline(cin, input);
    // check name on specific conditions: must be alphabetic characters
    bool nameness;
    nameness = true;
    // names must be alphabetical
    for (int i = 0; i < input.length(); ++i) {
        if (!isalnum(input[i])) {
            nameness = false;
        }
    }
    // input validation loop
    while (!cin or !nameness) {
        // clear
        getline(cin, junk);
        // prompt for new input
        cout << "Invalid input. Names may only contain alphabet letters. Enter helper's name as a string: ";
        getline(cin, input);
        // check nameness again
        for (int i = 0; i < input.length(); ++i) {
            if (!isalpha(input[i])) {
                nameness = false;
            }
        }
    }
    setName(input);
}

// function to get user inputted downstairs value
void Helper::setUDownstairs() {
    // bool input for downstairs and char letter for input
    bool input;
    char letter;
    // prompt for input
    cout << "Downstairs or upstairs? Enter 'd' for down or 'u' for up: ";
    cin >> letter;
    // input validation loop
    while (letter != 'd' and letter != 'u'){
        string junk;
        getline(cin, junk);
        // reprompt
        cout << "Please enter 'd' or 'u': ";
        cin >> letter;
    }
    // set value accordingly (d - downstairs is true, u - downstairs is false)
    if (letter == 'd') {
        setDownstairs(true);
    }
    if (letter == 'u'){
        setDownstairs(false);
    }
}

void Helper::setUFavoriteChores(vector<Chore> &chores){
    // ask for favorite chores from list (maybe by index and print every chore (from another function) line by line
}

// overloaded operator to print Helper nicely to console for user
ostream& operator << (ostream& outs, Helper helper) {
    outs << left << setw(12) << helper.getName();
    // how to write an overloaded operator for an enumerated type
    // or do i need a function that returns it as a string? string getPlaces() -> if (place == neutral) return "neutral";
    outs << left << setw(4) << helper.getDownstairs();
    return outs;
}

bool operator ==(Helper& lhs, Helper& rhs) {
    return lhs.getChoreMinutes() == rhs.getChoreMinutes();
}
