//
// Created by lebllex on 2/13/20.
//

#ifndef INC_02_XML_PARSE_VISUALPROJECT_H
#define INC_02_XML_PARSE_VISUALPROJECT_H


#include "vsqitem.h"
#include "vsqitemsregistrator.h"


struct VisualProject: public VsqItem{
    void method_empty() override  {
        std::cout << "VisualProject " << std::endl;
    }
};





#endif //INC_02_XML_PARSE_VISUALPROJECT_H
