# coding=utf-8
from socket import *

serverPort = 12000

# 两个参数分别代表是IPV4, UDP协议
serverSocket = socket(AF_INET, SOCK_DGRAM)
serverSocket.bind(('', serverPort))
print ("The server is ready to receive....")
while True:
    message, clientAddress = serverSocket.recvfrom(2048)
    modifiedMessage = message.decode()
    print ("got message from some client: " + modifiedMessage)
    serverSocket.sendto(modifiedMessage.upper().decode(), clientAddress)
