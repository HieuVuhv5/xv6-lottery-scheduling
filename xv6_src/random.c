#include "types.h"
#include "user.h"


int
main(int argc, char *argv[])
{
	unsigned int seed = 1;
	if(argc > 1)
	{
		seed = (unsigned int)argv[1];
		setsrand(seed);
	}
	for(int n =0 ; n <10 ; n ++)
	{
		//printf(1, "test success: %d\n", 111);
		printf(1, "Random number is : %u\n", (unsigned int) getrand());

	}
	exit();
}