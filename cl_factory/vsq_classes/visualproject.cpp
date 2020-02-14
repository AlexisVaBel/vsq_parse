//
// Created by lebllex on 2/13/20.
//
#include "visualproject.h"
#include "allitemsregistrator.h"

static VsqItemsRegistrator<VsqItem,VisualProject> registerVis("VisualProject");

void VisualProject::method_empty() {
        std::cout << __FUNCTION__ << " VisualProject " << std::endl;
}
