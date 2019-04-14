#include <semaphore.h>
#include <time.h>

 

class MutexLock
{
public:
	MutexLock();
	~MutexLock();
	bool lock(long locktime , long waittime);
	bool lock(long locktime );
	bool unlock();

	 int i ;
protected:
	bool trylock(long locktime);
	bool tryunlock();
private:
	sem_t g_semaphore;
	long lock_time;
	long locktime;
	bool islock ;


};