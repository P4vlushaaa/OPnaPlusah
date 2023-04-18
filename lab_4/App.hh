#ifndef LAB_4_APP_HH
#define LAB_4_APP_HH

//#include "line.h"
#include <vector>
#include <iostream>
#include "IDialogInitiable.hh"
#include "IGeoFig.hh"

class app : public IDialogInitiable {
private:
    std::vector<IGeoFig *> arr;
public:
    void initFromDialog() override;

    void add(IGeoFig *figure);

    int start();
};


#endif //OP4_APP_H
