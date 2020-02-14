//
// Created by lebllex on 2/14/20.
//

#ifndef INC_02_XML_PARSE_VSQCONSTRUCTOR_H
#define INC_02_XML_PARSE_VSQCONSTRUCTOR_H


#include <memory>
#include "xml_procs/xmlreader.h"
#include "cl_factory/vsq_classes/vsqitem.h"

class VsqConstructor{
public:
    VsqConstructor();
    ~VsqConstructor() = default;
    bool process_xml_ok(std::string &str);
    void process_items();
private:
    void process_items(const NodeElements *node);

    std::shared_ptr<XmlReader> m_parser;
    std::shared_ptr<VsqItem>   m_rootItem;
};
#endif //INC_02_XML_PARSE_VSQCONSTRUCTOR_H
