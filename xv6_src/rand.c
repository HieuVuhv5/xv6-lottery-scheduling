#include "types.h"
#include "user.h"
#include "rand.h"
#include "x86.h"


# define RAND_MAX (1 << 31)



unsigned long int rand_next = 1;

unsigned int rand()
{
	
	rand_next = rand_next * 1103515245 + 12345;
	return ((unsigned int)(rand_next / 65536) % (RAND_MAX +1));
	
		
}

void srand(unsigned int seed)
{
	rand_next = seed;
}