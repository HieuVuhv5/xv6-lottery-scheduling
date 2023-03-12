#include "syscall.h"
#include "traps.h"

#define SYSCALL(name) \
  .globl name; \
  name: \
    movl $SYS_ ## name, %eax; \
    int $T_SYSCALL; \
    ret

SYSCALL(fork)
SYSCALL(exit)
SYSCALL(wait)
SYSCALL(pipe)
SYSCALL(read)
SYSCALL(write)
SYSCALL(close)
SYSCALL(kill)
SYSCALL(exec)
SYSCALL(open)
SYSCALL(mknod)
SYSCALL(unlink)
SYSCALL(fstat)
SYSCALL(link)
SYSCALL(mkdir)
SYSCALL(chdir)
SYSCALL(dup)
SYSCALL(getpid)
SYSCALL(sbrk)
SYSCALL(sleep)
SYSCALL(uptime)
#ifdef GETPPID
SYSCALL(getppid)
#endif // GETPPID    
#ifdef CPS
SYSCALL(cps)
#endif // CPS
#ifdef RAND_S
SYSCALL(getrand)
SYSCALL(setsrand)
#endif // RAND_S

#ifdef LOTTERY
//# error some new system calls go in here
SYSCALL(nice)
SYSCALL(renice)
#endif // LOTTERY
    
