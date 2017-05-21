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
    char buffer[BUFSIZ+1];
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
    msg->write = 1;
    while(running){
        while(msg->write==0){
            sleep(2);
            printf("waiting.....\n");
        }
        printf("input some text:\n");
        fgets(buffer,BUFSIZ,stdin);
        strcpy(msg->text,buffer);
        msg->write = 0;
        if (strncmp(buffer,"end",3) == 0){
            running = 0;
            printf("game over\n");
        }
    }

    //取消关联
    shmdt(msg);
    shmctl(shmid,IPC_RMID,0);
    exit(EXIT_SUCCESS);
}
