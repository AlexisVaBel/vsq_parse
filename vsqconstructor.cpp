//
// Created by lebllex on 2/14/20.
//

#include <fstream>
#include <sstream>


#include "vsqconstructor.h"
#include "xml_procs/xmlreader.h"
#include "cl_factory/allitemfactory.h"


static const char* VSQ_CH_CLASS    = "class";
static const char* VSQ_CH_PROPERTY = "property";


VsqConstructor::VsqConstructor():m_parser(std::make_shared<XmlReader>()){
}

bool VsqConstructor::process_xml_ok(std::string &str){
    std::ifstream istrm(str, std::ios::binary);
    if(!istrm.is_open()){
        std::cout << "failed to open "<< str << std::endl;
        istrm.close();
        return false;
    }else{

        istrm.seekg(0,istrm.end);
        size_t  lng = istrm.tellg();

        char * buffer = new char[lng];

        size_t  readBytes = 0;
        while (readBytes < lng){
            istrm.seekg(readBytes);
            istrm.read(buffer + readBytes, sizeof(char));
            readBytes+= sizeof(char);
        }

        m_parser->procs_buffer(buffer, readBytes);
//        std::cout << "Total node counts " << m_parser->get_nodes_cnt() << std::endl;
//        m_parser->print_nodes();
        delete[] buffer;
        istrm.close();
    }
    return true;

}
void VsqConstructor::process_items(){
    process_items(m_parser->get_root_node());
}

void VsqConstructor::process_items(const NodeElements *node){
    if(node == nullptr)   return;

    std::istringstream iss(node->_info);

    for(std::string strTmp; iss >> strTmp; ){

        if(strTmp.find("class") != std::string::npos){

            auto szStart = strTmp.find("\"");
            auto strClsName = strTmp.substr(szStart + 1, strTmp.length() - szStart - 2);

            auto itm = AllItemFactory<VsqItem>::instance()->create(strClsName);
            if(itm != nullptr)
                itm.get()->method_empty();

        }
    }

    auto it = node->_setChilds.begin();
    while(it != node->_setChilds.end()){
        process_items(it->get());
        ++it;
    }
}