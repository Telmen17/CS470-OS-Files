// C Program to simulate child and parent processes in an Operating System.
// @author Telmen Enkhtuvshin

// Importing header files
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

// Main function
int main() {
    // Process ID
    pid_t pid;
    // Status integer variables
    int status;
    // Number of children variable
    const int numberofChildren = 12;

    // Array of commands
    char *commands[][12] = {
        {"ls", "-l",NULL},
        {"echo","Hello from CS470",NULL},
        {"date", NULL, NULL},
        {"touch", "sample1.txt", NULL},
        {"pwd", NULL},
        {"ls", "-R", NULL},
        {"date", "+%s", NULL},
        {"pip", "--version", NULL},
        {"mkdir", "sampleDirectory", NULL},
        {"who", NULL},
        {"uptime", NULL},
        {"df", "-h", NULL}
    };

    // Printing parent process
    printf("Parent process PID: %d\n", getpid());

    // Creating child processes
    for (int i = 0; i < numberofChildren; i++) {
        // Getting the pid with fork
        pid = fork();

        // If pid is a negative integer
        if (pid < 0) {
            // Fork has failed
            perror("Fork failed");
            exit(EXIT_FAILURE);
        // If PID is equal to 0, then process can be executed    
        } else if (pid == 0) {
            // Printing details
            printf("Child process PID: %d - Executing commands: %s\n", getpid(), commands[i][0]);
            // Command execution
            execvp(commands[i][0], commands[i]);
            // Error message to catch failures
            perror("Exec failed");
            exit(EXIT_FAILURE);
        }
    }

    // Parent
    printf("Pirnt out history: ------\n");

    // Printing message that the child processes have finished.
    while ((pid = wait(&status)) > 0) {
        printf("Child process with PID %d finished\n", pid);
    }

    // Returning final exit success number
    return EXIT_SUCCESS;
}