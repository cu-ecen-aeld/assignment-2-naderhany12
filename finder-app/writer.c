#include <stdio.h>
#include <stdlib.h>
#include <syslog.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

int main(int argc, char *argv[]){
 openlog("writer" , LOG_PID | LOG_CONS , LOG_USER);

  if(argc != 3) {
   syslog(LOG_ERR, "Error: Invalid number of arguments. Expected 2, got %d", argc - 1);
    fprintf(stderr, "Usage: %s <file_path> <string_to_write>\n", argv[0]);
   closelog();
    return 1;
}

const char *writefile = argv[1];
const char *writestr = argv[2];

int fd = open(writefile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
   if (fd == -1){
   syslog(LOG_ERR, "Error opening file %s: %s", writefile, strerror(errno));
   perror("Error opening file");
   closelog();
   return 1;
}

   syslog(LOG_DEBUG, "Writing %s to %s", writestr, writefile);

    ssize_t bytes_written = write(fd, writestr, strlen(writestr));
    if (bytes_written == -1) {
        syslog(LOG_ERR, "Error writing to file %s: %s", writefile, strerror(errno));
        perror("Error writing to file");
        close(fd);
        closelog();
        return 1;
    }

    close(fd);
    closelog();

    return 0;

}

