//
// Created by 16107 on 9/28/2022.
//

#include "Errand.h"

Errand:: Errand() : Activity(), cost(0.01), total(100), remaining(100) {
}

Errand::Errand(string title, int time, downstairs place) : Activity(title, time, place), cost(0.01), total(100), remaining(100) {
}

Errand:: Errand(float cost, int total, int remaining) : Activity(), cost(cost), total(total), remaining(remaining) {
}

Errand:: Errand(string title, int time, downstairs place, float cost, int total, int remaining) : Activity(title, time, place), cost(cost), total(total), remaining(remaining) {
}

float Errand::getCost() {
    return cost;
}

int Errand::getTotal(){
    return total;
}

int Errand::getRemaining(){
    return remaining;
}

void Errand::setCost(float cost){
    this->cost = cost;
}

void Errand::setTotal(int total) {
    this->total = total;
}

void Errand::setRemaining(int remaining){
    this->remaining = remaining;
}

string Errand::describe() {
    string returnString;
    returnString.append(title);
    returnString.append(" is an errand that");
    if (place = up) {
        returnString.append(" must be done for upstairs");
    }
    else if (place = down) {
        returnString.append(" must be done for downstairs");
    }
    else {
        returnString.append(" must be done");
    }
    returnString.append(" if there are less than " + to_string(total/2) + " " + title + " left");
    returnString.append(".There are currently " + to_string(remaining) + " left");
    if (remaining < total/2.0) {
        returnString.append(" so" + title + " needs to be bought!");
    }
    return returnString;
}

void Errand::setUCost(){
    float cost;
    cout << "Enter the cost: " << endl;
    cin >> cost;
    setCost(cost);
}
void Errand::setUTotal(){
    int total;
    cout << "How many should be bought? " << endl;
    cin >> total;
    setTotal(total);
}

void Errand::setURemaining(){
    int remaining;
    cout << "How many are currently remaining? " << endl;
    cin >> remaining;
    setRemaining(remaining);
}