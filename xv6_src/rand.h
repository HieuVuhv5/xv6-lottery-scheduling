#ifdef RAND_S



#ifdef RAND_MAX
# define RAND_MAX (1 << 31)
#endif


unsigned int rand();
void srand(unsigned int seed);

#endif // RAND_S