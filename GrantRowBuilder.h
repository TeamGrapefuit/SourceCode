#include <stdio.h>
#include "Grant_rowObject.h"
#include <string>
#include "attributeretriever.h"
#include "ColIndex.h"

class GrantRowBuilder{
public:
    GrantRowBuilder(){};
    
    
    Grant_rowObject buildRow(string data, ColIndex index);
    
};
