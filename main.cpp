#include <iostream>
#include <getopt.h>
#include <memory>
#include "vsqconstructor.h"

static const char *optString = "p:";
static char * CH_DEFAULT_XML_FILE = "../xml_files/simple.xml";

struct globalArgs_t{
    char *fullPath;
} globalArgs;

void fill_cmd_args(int &opt){
    switch (opt){
        case 'p' : globalArgs.fullPath = optarg;
    }
}

void prepare_args(){
    globalArgs.fullPath = CH_DEFAULT_XML_FILE;
}

void read_cmd_conf(int &argc, char ** argv){
    int opt = 0;
    prepare_args();
    do{
        opt = getopt(argc, argv, optString);
        fill_cmd_args(opt);
    }while (opt != -1);
}




int main(int argc, char ** argv) {
    read_cmd_conf(argc, argv);

    std::string str = globalArgs.fullPath;

    std::unique_ptr<VsqConstructor> vsq_construct = std::make_unique<VsqConstructor>();
    if(vsq_construct->process_xml_ok(str))
        vsq_construct->process_items();

    return 0;
}
