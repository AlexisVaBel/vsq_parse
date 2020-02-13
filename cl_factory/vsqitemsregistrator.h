//
// Created by lebllex on 2/13/20.
//

#ifndef INC_02_XML_PARSE_VSQITEMSREGISTRATOR_H
#define INC_02_XML_PARSE_VSQITEMSREGISTRATOR_H

#include <string>
#include "vsqitemfactory.h"

using namespace std;
template <class T>
struct VsqItemsRegistrator{
    VsqItemsRegistrator(string strName){
        VsqItemFactory::instance()->registerItem(strName, [] () ->VsqItem * {return new T();});
    }
};

#endif //INC_02_XML_PARSE_VSQITEMSREGISTRATOR_H
