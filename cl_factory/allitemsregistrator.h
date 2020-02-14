//
// Created by lebllex on 2/13/20.
//

#ifndef INC_02_XML_PARSE_ALLITEMSREGISTRATOR_H
#define INC_02_XML_PARSE_ALLITEMSREGISTRATOR_H

#include <string>
#include "allitemfactory.h"

using namespace std;
template <class typeBase, class typeGenerated>
struct VsqItemsRegistrator{
    VsqItemsRegistrator(string strName){
        AllItemFactory<typeBase>::instance()->registerItem(strName, [] () ->typeBase * {return new typeGenerated();});
    }
};

#endif //INC_02_XML_PARSE_ALLITEMSREGISTRATOR_H
