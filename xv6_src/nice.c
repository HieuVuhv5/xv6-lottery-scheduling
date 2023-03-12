#include "types.h"
#include "user.h"

int
main(int argc, char *argv[])
{	
	uint nice_value;
	if(argc < 3){
		printf(1, "Insufficient arguments; it needs 3 arguments : number of nice value; app name and number of running times .\n");
		exit();
	}
	else
	{
		nice_value = (unsigned int)atoi(argv[1]);
	
		if( nice_value < 1 || nice_value > 100 )
		{
			
			printf(1,"the nice value is out of bounds.\n");
			exit();
			
		}
		
		nice(nice_value);
		exec(argv[2], &(argv[2]));
		
		nice(0);


		exit();
		
	}
}