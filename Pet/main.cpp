//
//  main.cpp
//  Pet and its driver
//
//  Created by Jessica Dunford on 11/7/17.
//  Copyright © 2017 Jessica Dunford. All rights reserved.
//

#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>

using namespace std;

// Pet class with a name, id, numLimbs
// also has a static population member
class Pet {
private:
    string name;
    long id;
    int numLimbs;
    static const int POPULATION =10*1000;
    
public:
    
    Pet();
    Pet(string name, long id, int numLimbs);
    
    long getID() const;
    string getName();
    int getNumLimbs();
    
    bool setID(long id);
    bool setName(string name);
    bool setNumLimbs(int numLimbs);
    
    string toString();  // returns "Pet: name. ID: 1024; number of limbs: limbs."
    
};

char pickConsonant () {
    string consonants = "bcdfghjklmnpqrstvwxz";
    return consonants[rand() % consonants.length()];
}

char pickVowel () {
    string vowels = "aeiouy";
    return vowels[rand() % vowels.length()];
}

// Global function to generate a cool sounding name by picking
// consanants and vowels in alternate fashion
string makeCoolName(int len) {
    
    bool lastWasVowel = rand() > RAND_MAX / 2;
    
    string name = "";
    for (int i = 0; i < len; i++) {
        char c = lastWasVowel? pickConsonant() : pickVowel();
        name += c;
        lastWasVowel = !lastWasVowel;
    }
    
    return name;
}

long makeId(){
    long num;
    
    num = rand() % 11000 + 1;
    return num;
}

int makeNumLimbs(){
    int num;
    
    num = rand() % 4 + 0;
    return num;
}
bool findId(Pet pet[], int size){
    string userInputStr;
    long id;
    
    cout << "Please enter an ID: (Quit = 0): ";
    getline(cin, userInputStr);
    istringstream(userInputStr) >> id;
    if (id <= 0) {
        exit(2);
    }
        for (int a = 0; a < size; a++) {
            if (pet[a].getID() == id) {
                cout << "\n" << pet[a].toString() << endl;
                return true;
            }
        }
    cout << "\nId does not exists" << "\n" << endl;
    return true;
}

// in this main driver, we initialize an array of STORE_SIZE pets

int main() {
    const int STORE_SIZE = 10*1000;
    srand((unsigned) time(NULL));
    int number;
    // Declare an array of pets
    Pet Pet[STORE_SIZE];
    
    // loop over the pets to initialize each pet
    for (int i = 0; i < STORE_SIZE; i++) {
        Pet[i] = Pet::Pet();
        number = rand() % 5 + 3;
        Pet[i].setName(makeCoolName(number));
        Pet[i].setID(makeId());
        Pet[i].setNumLimbs(makeNumLimbs());
        
        cout << Pet[i].toString() << endl;
        
    }
    bool exist;
    do {
        
        exist = findId(Pet, STORE_SIZE);
    } while (exist);
    
    // enter a user interaction loop in which we
    // - prompt the user for an ID
    // - scan the array of pets for a pet with that id
    // - if found, print the details of the pet
    // - if not found, say "No such pet exists in this store"
    // - if the user entered 0 or a negative number in his/her ID search quit
    
    
    
    return 0;
}

    
Pet::Pet() {
    string name = "";
    long id = 0;
    int numLimbs = 0;
    
}
Pet::Pet(string name, long id, int numLimbs) {
    this->name = name;
    this->id = id;
    this->numLimbs = numLimbs;

}
    
long Pet::getID() const {
    
    return id;
}

string Pet::getName() {
    
    return name;
}

int Pet::getNumLimbs() {
    
    return numLimbs;
}
    
bool Pet::setID(long id) {
    if (id > 0) {
        this->id = id;
        return true;
    }
    else
        return false;
        
}

bool Pet::setName(string name) {
    if (name.length() > 0) {
        this->name = name;
        return true;
    }
    else
        return false;
    
}


bool Pet::setNumLimbs(int numLimbs) {
    if (numLimbs > 0 && numLimbs < 10) {
        this->numLimbs = numLimbs;
        return true;
    }
    else
        return false;
    
}
    // returns "Pet: name. ID: 1024; number of limbs: limbs."
string Pet::toString() {
    string petInfo;
    petInfo = "Pet: " + name + ". ID: " + to_string(id) + ". Number of limbs: "
        + to_string(numLimbs) + "\n";
    return petInfo;
}
    

