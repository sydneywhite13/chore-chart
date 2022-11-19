# Chore Chart with C++

## Project Summary
This project is a chore generator, originally inspired by my roommates.
It includes four classes:
* Activity: an activity that requires a person responsible for it on the schedule, including a title, time it takes, and downstairs (an enumerated type that holds upstairs, downstairs, or neither)
  * Chore: a chore is an activity. It has a title, time, and downstairs enumerated type from Activity as well as an integer timeline for how often it needs to be done and a boolean value for whether it has been done this week 
  * Errand: an errand is an activity. It has a title, time, and downstairs enumerated type from Activity as well as a cost, the total amount, and the amount remaining
* Helper: a person who will help with the chores who has a name, upstairs or downstairs indication, chore time, and more
* Schedule: a schedule has activities and helpers. A schedule matches activities to helpers in pairs depending on various factors. 

The project has basic chores, errands, and activities that already exist and asks for user input if they would like to add more. It loads in helpers from an input file but also accepts user input if the user would like to add more. 
Then, it takes the activities and helpers and generates pairs to match the activity to a helper responsible to complete it and outputs to the console and a file. 
It has both a main executable and a testing executable to test methods of various classes. 

## Class Relationships 
* Is-A Relationship: A chore and an errand are activities. Chore and Errand are subclasses that inherit from Activity. 
  * In simpler terms, an acitivy is a broad category that both completing a chore and completing an errand fall under, so they can share some functionality. 
* Has-A Relationship: A schedule has helpers and activities. Helper and Activity are component classes to Schedule. 
  * A schedule includes helpers and activities, therefore the details of those items, helpers and activities, are included in schedules. 

## File Implementation 
* File input: An input file of helpers is read in to a vector of Helper objects used in the Schedule class 
* File output: An output file is used to output the pairs of activities and helpers generated in the Schedule class 

## Future Work 
The algorithm which pairs helpers to activities, thus creating the schedule, is very basic, just functional now. In the future, I would like to develop the algorithm to accept specific helper's favorite chores and account for them. 
I would also like to make Activity an abstract class or at least the vector of activities a vector of pointers so that I can implement polymorphism by calling different functions like describe() on Chores and Errands to customize their functionality. In other words, I wish activity was not a functional class but rather purely a concept which provided details and functioning for chores and errands without being used itself. 
I would also like to allow for a more customized experience, for example inputting if someone has already done a chore that week without it being assigned and accounting for that in the schedule.
