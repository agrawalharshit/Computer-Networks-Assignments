#server.py

import socket
import time

host = 'localhost'
port = 6500

clients = []

s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
a=s.bind((host, port))
#s.setblocking(0)

quitting = False
print "Server Started."
print("socket binded to %s" % (port))
while not quitting:
    try:
        data, addr = s.recvfrom(1024)
        if "Quit" in str(data):
            quitting = True
        if addr not in clients:
            clients.append(addr)
            #print clients
        for client in clients:
            if not a:# tried this for broadcasting to others not c1

                s.sendto(data, client)

        print time.ctime(time.time()) + str(addr) + ": :" + str(data)

    except:
        pass
s.close()

