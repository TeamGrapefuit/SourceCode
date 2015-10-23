
#include <stdio.h>
#include "Pres_rowObject.h"
#include <string>
#include "attributeretriever.h"
#include "ColIndex.h"


class PresentationRowBuilder{
public:
    PresentationRowBuilder(){};
    
    
    Pres_rowObject buildRow(string data, ColIndex index);
    
};

