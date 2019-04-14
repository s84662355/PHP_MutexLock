#include "MutexLock.hpp"
#include <phpcpp.h>
 

class PHP_MutexLock  : public Php::Base
{
public:
	Php::Value lock(Php::Parameters &params);
	Php::Value unlock();
	Php::Value i();
private:
    MutexLock mutexlock;


};