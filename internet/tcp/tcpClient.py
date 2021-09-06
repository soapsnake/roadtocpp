# -*- coding: utf-8 -*-
from socket import *

serverName = 'localhost'
serverPort = 12000
clientSocket = socket(AF_INET, SOCK_STREAM)
clientSocket.connect((serverName, serverPort))
sentence = raw_input('please Input sentence:')

# tcp发送和接收消息都不需要再指定ip和端口
clientSocket.send(sentence.encode())
modifiedSentence = clientSocket.recv(1024)
print ('From server: ', modifiedSentence.decode())
clientSocket.close()

