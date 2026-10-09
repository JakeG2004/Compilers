#ifndef SEMANTIC_ANALYZER_H
#define SEMANTIC_ANALYZER_H

#include "treenode.h"

class SemanticAnalyzer
{
    public:
        SemanticAnalyzer();
        void Analyze(TreeNode* root, bool stDebug);
};

#endif