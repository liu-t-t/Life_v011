//
//  main.cpp
//  Life
//
//  Created by liu on 19/02/2022.
//

#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>
#include <vector>
#include <map>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>


class playerData //The class of player
{
private:
    std::string name;
    std::string passwd;
    std::map<std::string, std::string> mod_data;
    int level;
    int exp;
public:
    void setPlayerData(std::string, std::string);
    //~playerData();
    int saveData();
};

void playerData::setPlayerData(std::string n_name, std::string n_passwd) {
    name = n_name;
    passwd = n_passwd;
}

int playerData::saveData() {
    std::fstream fIO;

    remove("gamelog.log");
    fIO.open("gamelog.log", std::ios::in | std::ios::out);
    if (fIO.is_open()) {
        fIO << name << " " << passwd;//Do
        std::map<std::string, std::string>::iterator it;
        for (it = mod_data.begin(); it != mod_data.end(); it++) {
            fIO << (*it).second << std::endl;
        }
        fIO.close();
        return 1;
    }
    else {
        fIO.close();
        return 0;
    }
}

playerData* player;

int main() {
    ;
    return 0;
}

