#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int
main(int argc, char *argv[])
{
    if(argc < 2){
        fprintf(2, "Usage: time outs\n");
        exit(1);
    }

    int time = atoi(argv[1]);
    sleep(time);
    exit(0);
}//
// Created by rikka on 2022/2/22.
//

