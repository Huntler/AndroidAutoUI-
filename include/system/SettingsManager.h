#ifndef SETTINGSMANAGER_H
#define SETTINGSMANAGER_H

#include <QWidget>

class SettingsManager {

public:
    void readFile();
    void writeFile(std::string str);

};

#endif // SETTINGSMANAGER_H
