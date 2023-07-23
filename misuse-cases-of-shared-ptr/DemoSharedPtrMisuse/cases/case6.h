#pragma once
#include <memory>
#include <vector>
#include "common.h"

namespace case6
{
    class CPerson
    {
    public:
        CPerson() { printf(__FUNCTION__ "\n"); }
        virtual ~CPerson() { printf(__FUNCTION__ "\n"); }
    };

    class CParent : public CPerson
    {
    public:
        CParent() { printf(__FUNCTION__ "\n"); }
        virtual ~CParent() { printf(__FUNCTION__ "\n"); }
        std::vector<std::shared_ptr<CPerson>> children;
    };

    class CChild : public CPerson
    {
    public:
        CChild() { printf(__FUNCTION__ "\n"); }
        virtual ~CChild() { printf(__FUNCTION__ "\n"); }
        std::shared_ptr<CPerson> parent;
    };

    static void Entry()
    {
        // Oops, no one will be died then.
        std::shared_ptr<CParent> parent = std::make_shared<CParent>();
        std::shared_ptr<CChild> child1 = std::make_shared<CChild>();
        std::shared_ptr<CChild> child2 = std::make_shared<CChild>();
        std::shared_ptr<CChild> child3 = std::make_shared<CChild>();

        parent->children.push_back(child1);
        parent->children.push_back(child2);
        parent->children.push_back(child3);
        child1->parent = parent;
        child2->parent = parent;
        child3->parent = parent;
    }
}