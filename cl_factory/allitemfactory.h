//
// Created by lebllex on 2/13/20.
//

#ifndef INC_02_XML_PARSE_ALLITEMFACTORY_H
#define INC_02_XML_PARSE_ALLITEMFACTORY_H


#include <map>
#include <memory>
#include <functional>

#include "iostream"

template <typename  typeGenerated>
class AllItemFactory{
public:
    static AllItemFactory *instance(){
       static AllItemFactory _factory;
       return &_factory;
    }

    std::shared_ptr<typeGenerated> create(std::string strName){
        typeGenerated *instance=nullptr;
        auto it=m_map.find(strName);
        if(it!=m_map.end()){
            instance=it->second();
        }
        if(instance!=nullptr){
            return std::shared_ptr<typeGenerated>(instance);
        }
        it = m_map.find("EmptyItem");
        return std::shared_ptr<typeGenerated>(it->second());
    }

    void registerItem(std::string strName, std::function<typeGenerated* (void) > itemClass){
        m_map[strName] = itemClass;
    }


private:
    AllItemFactory(){
    }

    ~AllItemFactory() = default;

    std::map<std::string , std::function <typeGenerated*()> > m_map;
};


#endif //INC_02_XML_PARSE_ALLITEMFACTORY_H
