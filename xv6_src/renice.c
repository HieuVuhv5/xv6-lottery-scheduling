#include "types.h"
#include "user.h"

int
main(int argc, char *argv[])
{	
	int nice_value,pid_1, pid_2;
	
	if(argc < 3){
		printf(1, "Insufficient arguments; it needs 3 arguments : number of nice value; app name and number of running times .\n");
		exit();
	}
	else
	{
		nice_value = (int)atoi(argv[1]);
		pid_1 =(int)atoi(argv[2]);
		pid_2 = (int)atoi(argv[3]);
		renice(nice_value, pid_1, pid_2);
		
	}
	exit();
}
		
		