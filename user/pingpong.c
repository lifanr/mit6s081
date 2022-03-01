#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int main(int argc, char *argv[]){
    int parent_fd[2];
    int child_fd[2];
    pipe(parent_fd);
    pipe(child_fd);
    if(parent_fd== -1){
        printf("pipe1 error");
    }
    if(child_fd== -1){
        printf("pipe2 error");
    }
    int pid = fork();
    char buf[64];
    if(pid == 0){ //child
        read(parent_fd[0], buf, 4);
        printf("%d: received %s\n", getpid(), buf);
        write(child_fd[1], "ping", strlen('ping'));
    }else{
        // parent
        write(parent_fd[1], "pang", strlen("pang"));
        read(child_fd[0], buf, 4);
        printf("%d: received %s\n", getpid(), buf);
    }
    close(parent_fd[0]);
    close(parent_fd[1]);
    close(child_fd[0]);
    close(child_fd[1]);
    exit(0);

//
// Created by rikka on 2022/2/23.
//

