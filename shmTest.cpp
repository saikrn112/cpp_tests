#include <sys/mman.h>
#include <fcntl.h>
#include <semaphore.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string>
#define errExit(msg)    do { perror(msg); exit(EXIT_FAILURE); \
                        } while (0)


int main()
{
    std::string path = "/Users/sairamanakiran/shmtmp";
    int fd = shm_open(path, O_CREAT | O_EXCL | O_RDWR, S_IRUSR | S_IWUSR);
    if (fd == -1)
        errExit("shm_open");

    char* shmp = mmap(NULL, sizeof(char[10]), PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);

    if (ftruncate(fd, sizeof(char[11])) == -1)
        errExit("ftruncate");
    std::string tmpStr = "ThisString";
    memcpy(shmp,(void*)tmpStr.c_str(),10);
    return 0;
}

