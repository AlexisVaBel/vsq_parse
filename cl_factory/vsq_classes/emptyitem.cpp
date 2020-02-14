//
// Created by lebllex on 2/14/20.
//


#include "emptyitem.h"
#include "allitemsregistrator.h"

static VsqItemsRegistrator<VsqItem,EmptyItem> registerVis("EmptyItem");

void EmptyItem::method_empty() {
    std::cout << "EmptyItem" << std::endl;
}
