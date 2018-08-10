//Copyright (c) 2018 Ultimaker B.V.
//CuraEngine is released under the terms of the AGPLv3 or higher.

#ifndef LAYERPART_H
#define LAYERPART_H

#include "sliceDataStorage.h"
#include "slicer.h"

/*
The layer-part creation step is the first step in creating actual useful data for 3D printing.
It takes the result of the Slice step, which is an unordered list of polygons, and makes groups of polygons,
each of these groups is called a "part", which sometimes are also known as "islands". These parts represent
isolated areas in the 2D layer with possible holes.

Creating "parts" is an important step, as all elements in a single part should be printed before going to another part.
And all every bit inside a single part can be printed without the nozzle leaving the boundary of this part.

It's also the first step that stores the result in the "data storage" so all other steps can access it.
*/

namespace cura {

void createLayerWithParts(SliceLayer& storageLayer, SlicerLayer* layer, bool union_layers, bool union_all_remove_holes);

void createLayerParts(SliceMeshStorage& mesh, Slicer* slicer, bool union_layers, bool union_all_remove_holes);

void layerparts2HTML(SliceDataStorage& mesh, const char* filename, bool all_layers = true, int layer_nr = -1);

}//namespace cura

#endif//LAYERPART_H
