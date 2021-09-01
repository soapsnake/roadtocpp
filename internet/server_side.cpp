//
// Created by soapsnake@gmail.com on 1/9/21.
//


#include "headerFiles.h"
#define SERVER_PORT 80

//udp服务器
int main() {

  int s;   //套接字描述符
  int len;
  char buffer[256];  //数据缓冲区

  struct sockaddr_in servAddr{};  //服务器本地套接字地址
  struct sockaddr_in clintAddr{};  //客户端套接字地址
  socklen_t clintAddrLen;   //客户端套接字地址长度

  //建立本地套接字服务器地址
    memset(&servAddr, 0, sizeof(servAddr));  //分配内存
    servAddr.sin_family = AF_INET;   //族字段
    servAddr.sin_port = htons(SERVER_PORT);  //默认端口号
    servAddr.sin_addr.s_addr = htonl(INADDR_ANY);  //默认ip地址

    //create socket
    if ((s = socket(PF_INET, SOCK_DGRAM, 0) < 0)) {
        perror("Error, socket failed!");
        exit(1);
    }

    //bind socket to local ip and port
    if (bind(s, (struct sockaddr *) &servAddr, sizeof(servAddr)) == -1) {
        perror("Error, bind failed!");
        exit(1);
    }

    //本地无限循环,等待客户端的链接
    for (;;) {
        len = recvfrom(s, buffer, sizeof(buffer), 0, (struct sockaddr*) &clintAddr, &clintAddrLen);
        //send
        sendto(s, buffer, len, 0, (struct sockaddr*) & clintAddr, sizeof(clintAddr));
    }
}

