#include <phpcpp.h>
#include "PHP_MutexLock.hpp"


extern "C" {
    PHPCPP_EXPORT void *get_module() 
    {
        static Php::Extension extension("aaaaa", "1.0");
        Php::Class<PHP_MutexLock> counter("MutexLock");
        counter.method<&PHP_MutexLock::lock> ("lock",{ 
            Php::ByVal("locktime", Php::Type::Numeric) ,
            Php::ByVal("waittime", Php::Type::Numeric,0) 
        });
        counter.method<&PHP_MutexLock::unlock> ("unlock");
        counter.method<&PHP_MutexLock::i> ("i");
        extension.add(std::move(counter));
        return extension.module();
    }
}
