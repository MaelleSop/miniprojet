#ifndef UTILS_H
#define UTILS_H

#include <QtGlobal>
#include <QRandomGenerator>

class Utils {
public:
    static int randInt(int low, int high) {
        // Random number between low and high
        return QRandomGenerator::global()->bounded(low, high);

    }

};

#endif // UTILS_H
