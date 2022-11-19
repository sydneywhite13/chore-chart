//
// Created by 16107 on 9/15/2022.
//

#ifndef M1AP_HELPER_H
#define M1AP_HELPER_H

#include <iostream>
#include <vector>
#include "Chore.h"
using namespace std;

class Helper{
private:
    string name;
    bool downstairs;
    vector<Chore> favoriteChores;
    vector<Chore> lastWeek;
    vector<Chore> thisWeek;
    int choreMinutes;
    int numChores;
public:
    // constructor
    Helper();
    Helper(string name, bool downstairs);

    // getters
    string getName();
    bool getDownstairs();
    vector<Chore> getFavoriteChores();
    vector<Chore> getLastWeek();
    vector<Chore> getThisWeek();
    int getChoreMinutes();
    int getNumChores();

    // setters
    void setName(string name);
    void setDownstairs(bool downstairs);
    void setFavoriteChores(vector<Chore> &chores);
    void setLastWeek(vector<Chore> &chores);
    void setThisWeek(vector<Chore> &chores);
    void setChoreMinutes(int choreMinutes);
    void setNumChores(int numChores);

    // new week
    void newWeek();

    // get user input for Helper
    void setUName();
    void setUDownstairs();
    void setUFavoriteChores(vector<Chore> &chores);

    // overloaded operator
    friend ostream& operator << (ostream& outs, Helper helper);
    friend bool operator ==(Helper& lhs, Helper& rhs);
};

#endif //M1AP_HELPER_H
