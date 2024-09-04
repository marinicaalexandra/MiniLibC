struct timespec{
    long tv_sec;
    long tv_nsec;
};

unsigned int sleep(unsigned int seconds);
int nanosleep(struct timespec *req, struct timespec *rem);
