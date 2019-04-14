#include "MutexLock.hpp"

MutexLock::MutexLock()
{
    sem_init(&g_semaphore, 0, 1);
	this->locktime = 0;
	this->islock = true;
     i=0 ;
}

MutexLock::~MutexLock()
{
	sem_destroy(&g_semaphore);
}

bool MutexLock::trylock(long locktime)
{
	bool returnBool = false;
	if(sem_trywait(&g_semaphore) == 0)
	{
	   if(!this->islock)
	   {
          this->islock = true;
          this->locktime = locktime;
          this->lock_time = clock();
          returnBool = true;
	   }
	   else
	   {
	   	  if( clock() > this->lock_time + this->locktime )
	   	  {
	          this->islock = true;
	          this->locktime = locktime;
	          this->lock_time = clock();
	          returnBool = true;   
	   	  }
	   }  
	   sem_post(&g_semaphore);
	} 
	return returnBool;
}

bool MutexLock::tryunlock()
{
   bool returnBool = false;	
   if(sem_post(&g_semaphore) == 0)
   {
   	 this->islock = false;
   	 this->locktime = 0;
	 this->lock_time = 0;
   	 sem_post(&g_semaphore);
   	 returnBool = true;
   }
   return returnBool;
}

bool MutexLock::lock(long locktime , long waittime)
{
  clock_t starttime = clock();
  while(true)
  {
  	if(this->trylock(locktime))
    {
    	return true;
    } 
    if( clock() >  starttime + waittime ) return false;
  }
}

bool MutexLock::lock(long locktime )
{
   return this->trylock(locktime);
}

bool MutexLock::unlock( )
{
   return this->tryunlock();
}