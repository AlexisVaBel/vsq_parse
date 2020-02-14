#ifndef XMLREADER_H
#define XMLREADER_H

#include <iostream>

#include <set>
#include <vector>

#include <chrono>
#include <memory>


struct NodeElements{
    NodeElements():_parent(nullptr){
    }

    ~NodeElements(){
    }

    std::string    _info;
    std::string    _text;
    NodeElements  *_parent;

    std::set<std::shared_ptr<NodeElements>> _setChilds;
};


class XmlReader{
    NodeElements *m_root;
    int           m_iNodeCnt;


public:
    XmlReader():m_root(new NodeElements()), m_iNodeCnt(0){

    };

    ~XmlReader(){
        delete m_root;
    }

    const NodeElements * get_root_node() {
        return m_root;
    }


    int get_nodes_cnt(){
        return m_iNodeCnt;
    }

    void procs_buffer(char pnt[], size_t sz){
        NodeElements *curNode = nullptr;


        size_t  pos = 0;
        size_t  startPos = 0;

        bool    bClosed = false;

//        auto t1 = std::chrono::high_resolution_clock::now();

        while(pos < sz){


            if(pnt[pos] == '<'){
                std::string str = "";
                if(pos - startPos) {
                    while(startPos < (pos)){
                        bool bFound = false;
                        if(!(pnt[startPos] == '\f' ||
                             pnt[startPos] == '\n' || pnt[startPos] == '\r'  ||
                             pnt[startPos] == '\t' || pnt[startPos] == '\v'  ||
                             pnt[startPos] == '>') || bFound
                                ) {
                            bFound = true;
                            str+=pnt[startPos];
                        }
                        ++startPos;
                    }
                }
                if((pos+1 < sz) && (pnt[pos+1] == '/')){
                    bClosed = true;
                    if(!str.empty())  curNode->_text = str;
                } else {
                    startPos = pos;
                    if (curNode != nullptr) {
                        auto tmp =std::make_shared<NodeElements>();
                        tmp->_parent = curNode;
                        if(!str.empty())  curNode->_text = str;
                        curNode->_setChilds.insert(tmp);
                        curNode = tmp.get();
                        ++m_iNodeCnt;
                    } else {
                        curNode = m_root;
                    }
                };
            };

            if(pnt[pos] == '>'){
                std::string str = "";
                while(startPos < (pos-1)){
                    str+=pnt[++startPos];
                }
                if(pnt[pos-1] == '/') {
                    curNode->_info = str;
                    bClosed = true;
                }

                if(bClosed){
                    if(curNode->_parent != nullptr){
                        curNode = curNode->_parent;
                    }
                }else{
                    curNode->_info = str;
                }
                bClosed = false;
                startPos = pos;
            }

            ++pos;
        }

//        auto t2 = std::chrono::high_resolution_clock::now();
//        auto duration_procs = std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
//
//
//        std::cout << "char* procs: " << duration_procs << std::endl;



    }

    void print_nodes(){
        print_all_nodes(m_root, 1);
    }




private:

    void print_all_nodes(NodeElements *rootNode, int spacer){
        std::cout << std::string(spacer,'-')  << rootNode->_info << " : " << rootNode->_text << std::endl;
        auto it = rootNode->_setChilds.begin();
        while(it != rootNode->_setChilds.end()){
            print_all_nodes(it->get(),spacer+1);
            ++it;
        }

    }





};

#endif // XMLREADER_H
