#include <iostream>
#include <string>
#include <vector>

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

int main() {
    std::vector<Mod> mods;

    Mod wolfhud{"WolfHud", "17.1", true};

    addMod(mods, wolfhud);
    showMods(mods);

    std::string mod_name = "WolfHud";
    findMod(mods, mod_name);
    
    findMod(mods, "Jacobmod");

    toggleModStatus(mods, "WolfHud");

    showMods(mods);

    toggleModStatus(mods, "ABCD");
}