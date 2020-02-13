#include <iostream>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>


#include "xml_procs/xmlreader.h"
#include "cl_factory/vsqitem.h"
#include "cl_factory/vsqitemfactory.h"


void procs_items(const NodeElements *node){
    if(node == nullptr)   return;
//    std::cout << node->_info << " " << node->_text << std::endl;

    std::istringstream iss(node->_info);
    std::vector<std::string> vctInfo;
    for(std::string strTmp; iss >> strTmp; ){
        vctInfo.push_back(strTmp);
        std::cout << strTmp << "|";
        if(strTmp.)
    }
    std::cout << std::endl;


    auto it = node->_setChilds.begin();
    while(it != node->_setChilds.end()){
        procs_items(it->get());
        ++it;
    }
}


int main() {
    XmlReader *parser = new XmlReader();

    std::ifstream istrm("../xml_files/simple.xml", std::ios::binary);
    if(!istrm.is_open()){
        std::cout << "failed to open "<< "../xml_files/simple.xml" << std::endl;
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



        parser->procs_buffer(buffer, readBytes);
//        parser->print_nodes();

        std::cout << "Total node counts " << parser->get_nodes_cnt() << std::endl;

        delete[] buffer;




    }
    istrm.close();

//    auto itm = VsqItemFactory::instance()->create("visual project");
//    if(itm != nullptr)
//        itm.get()->method_empty();
    procs_items(parser->get_root_node());



    delete parser;

    return 0;
}
