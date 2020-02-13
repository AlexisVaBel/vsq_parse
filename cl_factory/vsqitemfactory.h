//
// Created by lebllex on 2/13/20.
//

#ifndef INC_02_XML_PARSE_VSQITEMFACTORY_H
#define INC_02_XML_PARSE_VSQITEMFACTORY_H

#include "vsqitem.h"


#include <map>
#include <memory>
#include <functional>

#include "iostream"

class VsqItemFactory{
public:
    static VsqItemFactory *instance(){
       static VsqItemFactory _factory;
       return &_factory;
    }

    std::shared_ptr<VsqItem> create(std::string strName){
        VsqItem *instance=nullptr;
        auto it=m_map.find(strName);
        if(it!=m_map.end()){
            instance=it->second();
        }
        if(instance!=nullptr){
            return std::shared_ptr<VsqItem>(instance);
        }
        return nullptr;
    }

    void registerItem(std::string strName, std::function<VsqItem* (void) > itemClass){
        m_map[strName] = itemClass;
    }


private:
    VsqItemFactory(){
    }

    ~VsqItemFactory() = default;

    std::map<std::string , std::function <VsqItem*()> > m_map;
};


#endif //INC_02_XML_PARSE_VSQITEMFACTORY_H
