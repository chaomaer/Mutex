//
// Created by chaomaer on 5/20/17.
//
//简单的信号量的学习
//掌握常见的Linux系统调用

#define TEXT_SIZE 2048

struct MSG{
    int write;
    char text[TEXT_SIZE];
};