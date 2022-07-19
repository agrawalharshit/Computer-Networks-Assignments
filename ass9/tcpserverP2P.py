host = "127.0.0.1"
port = 4444

from socket import *
s = socket(AF_INET, SOCK_STREAM)
s.bind((host, port))
s.listen(1)
print("Listening to the connection")
q, addr = s.accept()
msg = raw_input("Enter the Message to send :- ")
q.send(msg)

s.close()
