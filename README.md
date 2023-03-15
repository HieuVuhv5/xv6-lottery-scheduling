# xv6-lottery-scheduling
This is class lab assignmet from my classs cs333 at PSU.<br>
This source using  PThreads on  Linux system<br>

<b> How to run <br>
After cloning<br>
Go to xv6_src directory and run the comand "Make nox" to start xv6 operating system <br>
run command "ps" to show time tracking information how many process are running.<br>

run command nice 55 mfork 6 -> call runing mfork application for 6 times with nice number is 55. <br>
run command renice xx yy zz to change the nice number with (xx is new nice number, yy and zz are the PID (Process ID).<br>

When you have processes with large differences in nice values, you should notice that the processes with higher nice values get scheduled more frequently and accumulate more time/ticks on the CPU. <br>
Thanks.


