#ifndef BRANCHINIT_H
#define BRANCHINIT_H
#include "TTree.h"
#include "TChain.h"
void InitINTree( TChain * tree );
void InitOUTTree( TTree * tree );
void CopyInputVarsToOutput();
#endif
