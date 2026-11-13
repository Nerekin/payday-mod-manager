#include "ModManager.h"

void addMod(std::vector<Mod>& mods, const Mod& new_mod) {
    mods.push_back(new_mod);
}

bool toggleModStatus(std::vector<Mod>& mods, const std::string& name) {
    for(Mod& mod : mods) {
         if(mod.name == name) {
              mod.installed = !mod.installed;
              std::cout << "\nStatus is changed\n";
              return true;
            }
        }
        std::cout << "\nMod not found\n";
        return false;
    }

void findMod(const std::vector<Mod>& mods, const std::string& name) {
    for(const Mod& mod : mods) {
        if(mod.name == name) {
             std::cout << mod.name << "  " << mod.version << "   " << (mod.installed ? "installed" : "not installed") << std::endl;
             return;
            }
        }
        std::cout << "\nMod not found\n";
} 

void showMods(const std::vector<Mod>& mods) {
    if(mods.empty()) {
        std::cout << "\nNo mods installed\n";
    }
    else{
    for(const Mod& element : mods) {
        std::cout << "\n--------Mods----------\n";
        std::cout << element.name << "  " << element.version << "   " << (element.installed ? "installed" : "not installed") << std::endl;
        }
    }
}