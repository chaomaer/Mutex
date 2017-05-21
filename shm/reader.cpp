//
// Created by chaomaer on 5/20/17.
//
#include <stdio.h>
#include <iostream>
#include "sharedata.h"
#include <sys/shm.h>
#include <zconf.h>
#include <string.h>
#include <stdlib.h>

int main(){
    //首先创建一个共享内存段
    int running = 1;
    struct MSG* msg;
    void * ptr;
    int shmid = shmget(1234, sizeof(struct MSG), 0666|IPC_CREAT);
    //条件判断
    if(shmid==-1) {
        fprintf(stderr,"fail\n");
        exit(EXIT_FAILURE);
    }
    //进行关联
    ptr = (MSG *) shmat(shmid, 0, 0);
    //条件判断
    if(ptr==(void*)-1){
        fprintf(stderr, "link fail\n");
        exit(EXIT_FAILURE);
    }
    printf("memory attach at %x\n",ptr);
    msg = (MSG *) ptr;
    while(running){
        if(msg->write!=1){
            printf("read from memory:%s\n",msg->text);
            msg->write=1;
            if(strncmp(msg->text,"end",3)==0){
                running=0;
                printf("reader is over\n");
            }
            sleep(2);
        } else {
            printf("mem is occupied\n");
            sleep(2);
        }
    }

    //取消关联
    shmdt(msg);
    shmctl(shmid,IPC_RMID,0);
    exit(EXIT_SUCCESS);
}