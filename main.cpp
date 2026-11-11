#include <iostream>
#include <string>
#include <vector>
#include <limits>

struct Mod {
    std::string name;
    std::string version;
    bool installed;
};

void addMod(std::vector<Mod>& mods, const Mod& new_mod) {
    mods.push_back(new_mod);
}

bool toggleModStatus(std::vector<Mod>& mods, const std::string& name) {
    for(Mod& mod : mods) {
         if(mod.name == name) {
              mod.installed = !mod.installed;
              return 1;
            }
        }
        std::cout << "Mod not found\n";
        return 0;
    }

void findMod(const std::vector<Mod>& mods, const std::string& name) {
    for(const Mod& mod : mods) {
        if(mod.name == name) {
             std::cout << mod.name << "  " << mod.version << "   " << (mod.installed ? "installed" : "not installed") << std::endl;
             return;
            }
        }
        std::cout << "Mod not found\n";
} 

void showMods(const std::vector<Mod>& mods) {
    if(mods.empty()) {
        std::cout << "No mods installed\n";
    }
    else{
    for(const Mod& element : mods) {
        std::cout << element.name << "  " << element.version << "   " << (element.installed ? "installed" : "not installed") << std::endl;
        }
    }
}

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

            std::cout << "Write the mod name: ";
            std::cin >> new_mod.name;

            std::cout << "Write the mod version: ";
            std::cin >> new_mod.version;

            new_mod.installed = true;

            addMod(mods, new_mod);
            break;
        }

        case 4: {
            std::string name;

            std::cout << "Write the mod name: ";
            std::cin >> name;
            
            findMod(mods, name);

            break;
        }

        default:
            std::cout << "Write a valid number\n";
            break;
    }   

} while (choice != 0);
   
}

int main() {
    std::vector<Mod> mods;

    mainMenu(mods);
}