#client.py

import threading
import time
import socket


shutdown = False

def receving(name, sock):
    while not shutdown:
        try:

            while True:
                data, addr = sock.recvfrom(1024)

                print str(data)
        except:
            pass


host = 'localhost'
port = 6500

server = ('localhost',6500)

s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
s.bind((host, port))
#s.setblocking(0)

for i in range(5):
    threading.Thread(target=receving, args=("RecvThread",s)).start()


alias = raw_input("Name: ")
message = raw_input(alias + "-> ")
while message != 'q':
    if message != '':
        s.sendto(alias + ": " + message, server)

    message = raw_input(alias + "-> ")

    time.sleep(0.1)

shutdown = True

s.close()

