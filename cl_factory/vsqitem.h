//
// Created by lebllex on 2/13/20.
//

#ifndef INC_02_XML_PARSE_VSQITEMS_H
#define INC_02_XML_PARSE_VSQITEMS_H

struct VsqItem{
    virtual ~VsqItem() = default;

    virtual  void method_empty()  = 0;
};

#endif //INC_02_XML_PARSE_VSQITEMS_H
