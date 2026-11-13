#ifndef MODMANAGER_H
#define MODMANAGER_H

#include <string>
#include <vector>

struct Mod {
    std::string name;
    std::string version;
    bool installed;
};

void addMod(std::vector<Mod>& mods, const Mod& new_mod);
bool toggleModStatus(std::vector<Mod>& mods, const std::string& name);
void findMod(const std::vector<Mod>& mods, const std::string& name);
void showMods(const std::vector<Mod>& mods);

#endif
