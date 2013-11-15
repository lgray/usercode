#ifndef BRANCHINIT_H
#define BRANCHINIT_H
#include "TTree.h"
#include "TChain.h"
void InitINTree( TChain * tree );
void InitOUTTree( TTree * tree );
void CopyInputVarsToOutput(std::string prefix = std::string() );
void CopyPrefixBranchesInToOut( const std::string & prefix );
void CopyPrefixIndexBranchesInToOut( const std::string & prefix, unsigned index );
void ClearOutputPrefix ( const std::string & prefix );
#endif
