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

struct Character {
    std::string name;
    int health;
    int attack;
    int defense;
    int level;
    int experience;
    CharacterClass characterClass;

    // constructor for initializing default values
    Character() : health(0), attack(0), defense(0), level(1), experience(0) {}

    // function to display character information
    void displayInfo() {
        cout << "Name: " << name << "\n";
        cout << "Class: " << static_cast<int>(characterClass) << "\n";
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
            break;
        case 1:
            character.characterClass = CharacterClass::ROGUE;
            break;
        case 2:
            character.characterClass = CharacterClass::RANGER;
            break;
        case 3:
            character.characterClass = CharacterClass::MAGE;
            break;
        //add more classes as needed
        default:
            break;
    }

    srand(static_cast<unsigned>(time(0))); // seed the random number generator

    character.health = rand() % 11 + 30; // random number between 30 and 40
    character.attack = rand() % 7 + 12;   // random number between 12 and 18
    character.defense = rand() % 8 + 8;   // random number between 8 and 15

    return character;
}

bool askUserIfLiked(const std::string& characterName) {
    char response;
    cout << "Do you like the character " << characterName << "? (y/n): ";
    cin >> response;
    return (response == 'y' || response == 'Y');
}

int main() {
    std::vector<Character> characters;

    for (int i = 0; i < 3; i++) {
        Character newCharacter;
        bool userLikesCharacter = false;

        while (!userLikesCharacter) {
            newCharacter = createCharacter();

            std::cout << "Character " << i + 1 << " created:\n";
            std::cout << "Name: " << newCharacter.name << "\n";
            std::cout << "Health: " << newCharacter.health << "\n";
            std::cout << "Attack: " << newCharacter.attack << "\n";
            std::cout << "Defense: " << newCharacter.defense << "\n";
            std::cout << "\n";

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
