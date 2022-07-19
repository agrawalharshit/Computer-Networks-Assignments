#TCP Client Code

host = "127.0.0.1"

port = 4444

from socket import *

s = socket(AF_INET, SOCK_STREAM)
s.connect((host, port))

msg = s.recv(1024)

print ("Message from server : " + msg.strip().decode('ascii'))

s.close() 
