#include "PHP_MutexLock.hpp"

 
 

 
Php::Value PHP_MutexLock::lock(Php::Parameters &params)
{

  long locktime = (long)params[0];
  long waittime = (long)params[1];
  if(waittime == 0)
  {
     return this->mutexlock.lock(locktime);
  }

  return this->mutexlock.lock(locktime,waittime);
  
}

Php::Value PHP_MutexLock::unlock( )
{
   return this->mutexlock.unlock();
}

Php::Value PHP_MutexLock::i()
{
	return this->mutexlock.i++;
}