#include <iostream>
#include <string>
#include <cstdlib> // for rand() and srand()
#include <ctime>   // for time()
#include <vector>  // for vector

using namespace std;

// enum to represent character classes (warrior, rogue, ranger, mage)
enum class CharacterClass {
    WARRIOR,
    ROGUE,
    RANGER,
    MAGE,
    // add classes as needed
};

enum class AttackType {
    STANDARD,
    RANGED,
    // add more if needed, perhaps damage types (fire, ice, nature, poison, etc.)
};

struct Character {
    std::string name;
    int health;
    int attack;
    int defense;
    int level;
    int experience;
    CharacterClass characterClass;
    AttackType attackType;

    // constructor for initializing default values
    Character() : health(0), attack(0), defense(0), level(1), experience(0) {}

    // function to display character information
    void displayInfo() {
        cout << "Name: " << name << "\n";
        cout << "Class: " << static_cast<int>(characterClass) << "\n";
        cout << "Attack Type: " << static_cast<int>(attackType) << "\n";
        cout << "Health: " << health << "\n";
        cout << "Attack: " << attack << "\n";
        cout << "Defense: " << defense << "\n";
        cout << "Level: " << level << "\n";
        cout << "Experience: " << experience << "\n";
        cout << "\n";
    }
};

Character createCharacter() {
    Character character;

    cout << "Enter character name: ";
    cin >> character.name;

    // Randomize character classes
    int classChoice = rand() % 4; // number obviously needs to be changed if more classes are added
    switch (classChoice) {
        case 0:
            character.characterClass = CharacterClass::WARRIOR;
            character.attackType = AttackType::STANDARD;
            break;
        case 1:
            character.characterClass = CharacterClass::ROGUE;
            character.attackType = AttackType::STANDARD;
            break;
        case 2:
            character.characterClass = CharacterClass::RANGER;
            character.attackType = AttackType::RANGED;
            break;
        case 3:
            character.characterClass = CharacterClass::MAGE;
            character.attackType = AttackType::RANGED;
            break;
        //add more classes as needed
        default:
            break;
    }

    srand(static_cast<unsigned>(time(0))); // seed the random number generator

    character.health = rand() % 11 + 30; // random number between 30 and 40
    character.defense = rand() % 8 + 8;   // random number between 8 and 15

    //set attack based on class
    if (character.characterClass == CharacterClass::RANGER || character.characterClass == CharacterClass::MAGE) {
        character.attack = rand() % 5 + 8; // random number between 8 and 12
    } else {
        //standard attack for warriors and rogues
        character.attack = rand() % 7 + 12; // random number between 12 and 18
    }

    return character;
}

bool askUserIfLiked(const std::string& characterName) {
    char response;
    cout << "Do you like the character " << characterName << "? (y/n): ";
    cin >> response;
    return (response == 'y' || response == 'Y');
}

void displayCharacterDetails(const Character& character) {
    std::cout << "Name: " << character.name << "\n";
    std::cout << "Health: " << character.health << "\n";
    std::cout << "Attack: " << character.attack << "\n";
    std::cout << "Defense: " << character.defense << "\n";
    std::cout << "\n";

    // Display the character's class
    std::string className;
    switch (character.characterClass) {
        case CharacterClass::WARRIOR:
            className = "Warrior";
            break;
        case CharacterClass::ROGUE:
            className = "Rogue";
            break;
        case CharacterClass::RANGER:
            className = "Ranger";
            break;
        case CharacterClass::MAGE:
            className = "Mage";
            break;
    }
    std::cout << "Class: " << className << "\n";

    std::cout << "\n";
}

int main() {
    std::vector<Character> characters;

    for (int i = 0; i < 3; i++) {
        Character newCharacter;
        bool userLikesCharacter = false;

        while (!userLikesCharacter) {
            newCharacter = createCharacter();

            // create a function to display character details
            displayCharacterDetails(newCharacter);

            userLikesCharacter = askUserIfLiked(newCharacter.name);
        }

        characters.push_back(newCharacter);
    }

    cout << "All characters created:\n";
    for (size_t i = 0; i < characters.size(); i++) {
        cout << "Character " << i + 1 << ":\n";
        cout << "Name: " << characters[i].name << "\n";
        cout << "Health: " << characters[i].health << "\n";
        cout << "Attack: " << characters[i].attack << "\n";
        cout << "Defense: " << characters[i].defense << "\n";
        cout << "\n";
    }

    return 0;
}
