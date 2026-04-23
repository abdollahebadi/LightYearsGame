// In the name of Allah

#pragma once

namespace LY {
    class Object {
    public:
        Object() ;
        virtual ~Object() ;

        // So this function will help clean any resources related to the class that is inheriting from Object.
        // The actual freeing destruction will no be performed here but rather when an object's memory is deallocated.
        void Destroy() ;

        bool isObjectPendingDestroy() ;

    private:
        bool isPendingDestroy ;
    };

}
