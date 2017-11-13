// Specs:
// enter a user interaction loop in which we
// - prompt the user for an ID
// - scan the array of pets for a pet with that id
// - if found, print the details of the pet
// - if not found, say "No such pet exists in this store"
// - if the user entered 0 or a negative number in his/her ID search quit

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
    
public:
    
    Pet();
    Pet(string name, long id, int numLimbs);
    
    long getID() const;
    string getName();
    int getNumLimbs();
    int getPopulation();
    bool setID(long id);
    bool setName(string name);
    bool setNumLimbs(int numLimbs);
    string toString();  // returns "Pet: name. ID: 1024; number of limbs: limbs."
    
};

// Helper methods
char pickConsonant ();
char pickVowel ();
string createName(int len);
long createID();
int createNumLimbs();
bool findId(Pet pet[], int size);

// in this main driver, we initialize an array of STORE_SIZE pets
int main() {
    const int STORE_SIZE = 10*1000;
    srand((unsigned) time(NULL));
    int number;
    
    // Declare an array of pets
    Pet Pet[STORE_SIZE];
   
    // loop over the pets to initialize each pet
    for (int i = 0; i < STORE_SIZE; i++) {
        number = rand() % 5 + 3;
        Pet[i] = Pet::Pet(createName(number),createID(),createNumLimbs());
        cout << Pet[i].toString() << endl;
    }
    
    return 0;
}
// chooses a consonant for random name
char pickConsonant () {
    string consonants = "bcdfghjklmnpqrstvwxz";
    return consonants[rand() % consonants.length()];
}
// chooses a vowel for the random name
char pickVowel () {
    string vowels = "aeiouy";
    return vowels[rand() % vowels.length()];
}

// Global function to generate a cool sounding name by picking
// consanants and vowels in alternate fashion
string createName(int len) {
    bool lastWasVowel = rand() > RAND_MAX / 2;
    string name = "";
    
    for (int i = 0; i < len; i++) {
        char c = lastWasVowel? pickConsonant() : pickVowel();
        name += c;
        lastWasVowel = !lastWasVowel;
    }
    
    return name;
}
// generates an id
long createID(){
    long num;
    num = rand() % 11000 + 1;
    return num;
}
//generates number of limbs
int createNumLimbs(){
    int num;
    num = rand() % 4 + 0;
    return num;
}
// method to find id
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

 // constructors
Pet::Pet() {
    name = "";
    id = 0;
    numLimbs = 0;
}

Pet::Pet(string name, long id, int numLimbs) {
    setName(name);
    setID(id);
    setNumLimbs(numLimbs);

}

// setters and getters for class variables
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
    string toString;
    toString = "Pet: " + name + "\n" + "ID: " + to_string(id) +
   "\n" + "Number of limbs: " + to_string(numLimbs) + "\n";
    return toString;
}
    

