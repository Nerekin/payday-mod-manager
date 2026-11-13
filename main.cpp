#include "ModManager.h"

void mainMenu(std::vector<Mod>& mods) {
    int choice = 0;

do {
    std::cout << "\n\n      Menu        \n\n";
    std::cout << "1. Show mods\n";
    std::cout << "2. Add mods\n";
    std::cout << "3. Toggle the mod status\n";
    std::cout << "4. Find the mod\n";
    std::cout << "0. Exit\n\n";

    if(!(std::cin >> choice)) {
        std::cout << "Invalid input. Please enter a valid number";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        choice = -1;
        continue;
    }

    switch (choice) {
        case 1:
            showMods(mods);
            break;
        case 2: {
            Mod new_mod;

            std::cout << "\nWrite the mod name: ";
            std::getline(std::cin >> std::ws, new_mod.name);

            std::cout << "Write the mod version: ";
            std::getline(std::cin >> std::ws, new_mod.version);

            new_mod.installed = true;

            addMod(mods, new_mod);
            break;
        }

        case 3: {
            std::string name;

            std::cout << "\nWrite the mod name: ";
            std::getline(std::cin >> std::ws, name);
            
            toggleModStatus(mods, name);

            break;
        }


        case 4: {
            std::string name;

            std::cout << "\nWrite the mod name: ";
            std::getline(std::cin >> std::ws, name);
            
            findMod(mods, name);

            break;
        }

        default:
            if (choice != 0) {
                std::cout << "\nWrite a valid number\n";
                break;
            }
    }   

} while (choice != 0);
   
}

int main() {
    std::vector<Mod> mods;

    mainMenu(mods);
}