#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char **argv, char *envp[]) {

    int i, pid;

    for (i = 1; i <= 3; i++) {

        pid = fork();

        if (pid == 0) {   // processo filho

            if (i == 1) {
                char *args[] = {"xcalc", NULL};
                execve("/usr/bin/xcalc", args, envp);
            }

            if (i == 2) {
                char *args[] = {"brave", NULL};
                execve("/usr/bin/brave", args, envp);
            }

            if (i == 3) {
                char *args[] = {"gedit", NULL};
                execve("/usr/bin/gedit", args, envp);
            }

            // só executa se execve falhar
            perror("Erro no execve");
            return 1;
        }
        else {  // processo pai
            waitpid(pid, NULL, 0);
        }
    }

    return 0;
}