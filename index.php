<?php
  
 $lock = new MutexLock();

  $lock->lock(111 );
 echo "dadas";
   $lock->unlock( );

   class test extends Thread {
    public function __construct($arg){
        $this->arg = $arg;
    }
 
    //当调用start方法时，该对象的run方法中的代码将在独立线程中异步执行。
    public function run(){
        if($this->arg){
            printf("Hello %s\n", $this->arg);
        }
    }
}

 