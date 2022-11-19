//
// Created by 16107 on 9/7/2022.
//

#include <iostream>
#include "Helper.h"
#include "Chore.h"
#include "Schedule.h"
#include <vector>
#include <memory>
#include <fstream>
using namespace std;

//TODO: ask user if they would like to describe any of the activities

// functions
char getChoice(char c1, char c2);
Helper createHelper();
Activity createActivity();
void choresAndErrands(vector<Activity> &activities, int originalSizeA);
void helpers(vector<Helper> &newUserHelpers, int originalHelperSize);
// function to get activities from while is not used in main - but helpers are read in from a file
vector<Activity> getActivitiesFromFile(const string& file);
vector<Helper> getHelpersFromFile(string file);

int main () {
    cout << "Welcome to Chore Chart! Would you like to enter chores (c) or helpers (h) first? " << endl;

    // create some default chores
    vector<Activity> activities;
    activities.push_back(Chore("vacuum", 20, neutral));
    activities.push_back(Chore("dishes", 5, neutral));
    activities.push_back(Chore("upstairs bathroom", 20, up));
    activities.push_back(Chore("downstairs bathroom", 20, down));
    activities.push_back(Chore("laundry", 15, neutral));
    activities.push_back(Errand("downstairs toilet paper", 20, down, 7.59, 12, 12));
    activities.push_back(Errand("upstairs toilet paper", 20, up, 7.59, 12, 12));
    activities.push_back(Errand("paper towels", 20, neutral, 5.99, 6, 5));
    activities.push_back(Activity("take out compost", 2, neutral));
    activities.push_back(Activity("take out trash", 5, neutral));

    // create a vector of activities and store the original size
    int originalSizeA = activities.size();
    // create a vector of helpers
    vector<Helper> newUserHelpers = getHelpersFromFile("../helpers.csv");
    int originalHelperSize = newUserHelpers.size();
    // get user choice for what to input first
    char choice;
    choice = getChoice('c', 'h');
    // chore first
    if (choice == 'c') {
        choresAndErrands(activities,originalSizeA);
        cout << "Now let's enter some helpers!" << endl;
        helpers(newUserHelpers, originalHelperSize);
    }
    // helpers first
    if (choice == 'h') {
        helpers(newUserHelpers, originalHelperSize);
        cout << "Now for the chores!" << endl;
        choresAndErrands(activities, originalSizeA);
    }
    // generate schedule- compare work loads for helpers (overloaded operator)
    Schedule schedule1(newUserHelpers, activities);
    // print the schedule
    cout << schedule1;
    cout << "The schedule can also be found at: " << schedule1.outputToFile() << endl;
    return 0;
}

// function to take in two characters and prompt user until they enter one of the two!
char getChoice(char c1, char c2) {
    char choice;
    cin >> choice;
    // input validation
    while (choice != c1 and choice !=c2) {
        string junk;
        getline(cin, junk);
        cout << "Invalid input. Please enter either " << c1 << " or " << c2 << " : " << endl;
        cin >> choice;
    }
    return choice;
}

// createHelper function to create new object and set fields
Helper createHelper() {
    Helper newHelper;
    newHelper.setUName();
    newHelper.setUDownstairs();
    // add newHelper.setUFavoriteChores() when schedule has this logic
    return newHelper;
}

//createActivity function to create new object and set fields
Activity createActivity() {
    //get user input on whether it is a chore, errand, or activity
    cout << "Would you like to add a chore (c), errand (e), or activity (a)? " << endl;
    char choice;
    cin >> choice;
    while (choice != 'c' && choice != 'e' && choice != 'a') {
        string junk;
        getline(cin, junk);
        cout << "Enter c, e, or a: " << endl;
        cin >> choice;
    }
    if (choice == 'c') {
        Chore newChore;
        newChore.setUTitle();
        newChore.setUPlace();
        newChore.setUTime();
        newChore.setUTimeline();
        return newChore;
    }
    else if (choice == 'e') {
        Errand newErr;
        newErr.setUTitle();
        newErr.setUPlace();
        newErr.setUTime();
        newErr.setUCost();
        newErr.setUTotal();
        newErr.setURemaining();
        return newErr;
    }
    else {
        Activity newAct;
        newAct.setUTitle();
        newAct.setUPlace();
        newAct.setUTime();
        return newAct;
    }
}

// logic of printing chores, asking for more, validating input, and concluding
void choresAndErrands(vector<Activity> &activities, const int originalSizeA) {
    // provide a list of chores
    cout << "The default list of chores includes: " << endl;
    for (int i = 0; i < activities.size(); ++i) {
        cout << i+1 << " " << activities[i].getTitle() << endl;
    }
    // would they like to describe any of them?
    cout << "Would you like a description of any activities? Enter 'y' or 'n': ";
    char describeChoice = getChoice('y', 'n');
    int index;
    while (describeChoice == 'y') {
        string junk;
        getline(cin, junk);
        cout << "What activity would you like to describe? ";
        string choreName;
        getline(cin, choreName);
        bool input = false;
        for (int i =0; i < activities.size(); ++i) {
            if (choreName == activities[i].getTitle()){
                input = true;
                index = i;
            }
        }
        while (!input) {
            cout << "That is not an activity you may describe. Try again with the activity title: ";
            getline(cin, choreName);
            for (int i =0; i < activities.size(); ++i) {
                if (choreName == activities[i].getTitle()){
                    input = true;
                    index = i;
                }
            }
        }
        if (input == true) {
            cout << activities[index].describe()<< endl;
        }
        cout << "Would you like a description of any other activities? Enter 'y' or 'n': ";
        describeChoice = getChoice('y', 'n');
    }
    // would they like to add more? - using function to get and validate input
    cout << "Would you like to add more activities? Enter 'y' or 'n': ";
    char more = getChoice('y', 'n');
    while (more == 'y') {
        activities.push_back(createActivity());
        // check loop condition
        cout << "Would you like to add more activities? Enter 'y' or 'n': ";
        more = getChoice('y', 'n');
    }
    // print the chores they added (if they added chores)
    if (activities.size() > originalSizeA) {
        cout << "You added the following chores: " << endl;
        for (int i = 0; i < activities.size(); ++i) {
            cout << i + 1 << ". " << activities[i].getTitle() << endl;
        }
    }
}

// logic of getting user input helpers, validating input, and concluding
void helpers(vector<Helper> &newUserHelpers, int originalSize) {
    // provide a list of chores
    cout << "The helpers in the file are: " << endl;
    for (int i = 0; i < newUserHelpers.size(); ++i) {
        cout << i+1 << " " << newUserHelpers[i] << endl;
    }
    // would they like to add more? - using function to get input
    cout << "Would you like to add more helpers? Enter 'y' or 'n': ";
    char more = getChoice('y', 'n');
    while (more == 'y') {
        // prompt them to add a new helper
        newUserHelpers.push_back(createHelper());
        // check loop condition
        cout << "Would you like to add more helpers? Enter 'y' or 'n': ";
        more = getChoice('y', 'n');
    }
    // print the helpers
    if (newUserHelpers.size() > originalSize) {
        cout << "You added the following helpers: " << endl;
        for (int i = 0; i < newUserHelpers.size(); ++i) {
            cout << i + 1 << ". " << newUserHelpers[i] << endl;
        }
    }
}

// functoin not used in main but helpers are read in from a file!
vector<Activity> getActivitiesFromFile(const string& file){
    vector<Activity> activitiesFromFile;
    ifstream fIn;
    fIn.open(file);
    string labels;
    if (fIn){
        getline(fIn, labels);
    }
    string title, type;
    int time, timeline, total;
    double cost;
    downstairs place;
    char comma, junk, newLine;
    string placeString;
    while (fIn && fIn.peek() != EOF) {
        getline(fIn, type, ',');
        getline(fIn, title, ',');
        fIn >> time;
        fIn >> comma;
        getline(fIn, placeString, ',');
        if (placeString == "down") {
            place = down;
        }
        if (placeString == "up") {
            place = up;
        }
        else {
            place = neutral;
        }
        if (type == "chore") {
            // get timeline
            fIn >> timeline;
            fIn >> comma;
            // if its empty, use default constructor
            if (timeline == 0) {
                activitiesFromFile.push_back((Chore(title, time, place)));
            }
            else {
                activitiesFromFile.push_back(Chore(title, time, place, timeline));
            }
            // ignore cost and total
            fIn >> cost;
            fIn >> comma;
            fIn >> total;
            getline(fIn, title, '\n');
            //fIn >> junk;
            // push to activitiesFromFile
        }
        else if (type == "errand") {
            // ignore timeline
            fIn >> timeline;
            fIn >> comma;
            // get cost and total
            fIn >> cost;
            fIn >> comma;
            fIn >> total;
            // if either are empty, use default constructor
            // push to activitiesFromFile
        }
        else {
            // ignore timeline, cost, and total - just an activity with no extra fields
            activitiesFromFile.push_back((Activity(title, time, place)));
        }
    }
    fIn.close();
    return activitiesFromFile;
}

// function to read in helper objects from file
vector<Helper> getHelpersFromFile(string file){
    // define vector of Helper objects
    vector<Helper> helpersFromFile;
    ifstream fIn;
    fIn.open(file);
    // read in labels
    string labels;
    if (fIn){
        getline(fIn, labels);
    }
    // define fields to be read in
    string name, downstairsString;
    bool downstairs;
    char comma;
    // while the file is not at the end
    while (fIn && fIn.peek() != EOF) {
        // read in name and downstairsString
        getline(fIn, name, ',');
        getline(fIn, downstairsString, '\n');
        // convert the string into the boolean field for Helper
        if (downstairsString == "upstairs") {
            downstairs = false;
        }
        else if (downstairsString == "downstairs") {
            downstairs = true;
        }
        else {
            downstairs = true;
        }
        // create this heler object and add it to the vector
        helpersFromFile.push_back(Helper(name, downstairs));
    }
    fIn.close();
    return helpersFromFile;
}