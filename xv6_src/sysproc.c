#include "types.h"
#include "x86.h"
#include "defs.h"
#include "date.h"
#include "param.h"
#include "memlayout.h"
#include "mmu.h"
#include "proc.h"

int
sys_fork(void)
{
  return fork();
}

int
sys_exit(void)
{
  exit();
  return 0;  // not reached
}

int
sys_wait(void)
{
  return wait();
}

int
sys_kill(void)
{
  int pid;

  if(argint(0, &pid) < 0)
    return -1;
  return kill(pid);
}

int
sys_getpid(void)
{
  return myproc()->pid;
}

#ifdef GETPPID
int
sys_getppid(void)
{
    int ppid = 1;

    if (myproc()->parent) {
        ppid = myproc()->parent->pid;
    }
    return ppid;
}
#endif // GETPPID

int
sys_sbrk(void)
{
  int addr;
  int n;

  if(argint(0, &n) < 0)
    return -1;
  addr = myproc()->sz;
  if(growproc(n) < 0)
    return -1;
  return addr;
}

int
sys_sleep(void)
{
  int n;
  uint ticks0;

  if(argint(0, &n) < 0)
    return -1;
  acquire(&tickslock);
  ticks0 = ticks;
  while(ticks - ticks0 < n){
    if(myproc()->killed){
      release(&tickslock);
      return -1;
    }
    sleep(&ticks, &tickslock);
  }
  release(&tickslock);
  return 0;
}

#ifdef PROC_TIMES
# error I implemented a function here called suptime (because it
# error makes me think of supper time.
# error it does all the things of sys_uptime() below. I then have
# error sys_uptime() just call suptime().
#endif // PROC_TIMES

// return how many clock tick interrupts have occurred
// since start.
int
sys_uptime(void)
{
  uint xticks;

  acquire(&tickslock);
  xticks = ticks;
  release(&tickslock);
  
 
  return xticks;
}

#ifdef CPS
int
sys_cps(void)
{
    proc_cps();
    return 0;
}
#endif // CPS

#ifdef RAND_S
int
sys_getrand(void)
{
	return proc_getrand();	
}

int
sys_setsrand(void)
{
	int seed;

  if(argint(0, &seed) < 0)
    return -1;

  return proc_setsrand(seed);
	
}

#endif // RAND_S


#ifdef LOTTERY
//# error this is where the sys_renice function should live
int 
sys_nice(void)
{
	int value;
	if(argint(0, &value) < 0)
    return -1;
	return proc_nice(value);
	
}

int
sys_renice(void)
{
	int nice_val;
	int pid_1;
	int pid_2;
	if(argint(0, &nice_val) < 0)
		return -1;
	if(argint(1,&pid_1) < 0)
		return -1;
	if(argint(2,&pid_2) < 0)
		return -1;
	return proc_renice(nice_val, pid_1, pid_2);
}
	
#endif // LOTTERY
