import socket

def getIP(domain):
    try:
        data = socket.gethostbyname(domain)
        ip = repr(data)
        return ip
    except Exception:

        return False

def getHost(ip):
    
    try:
        data = socket.gethostbyaddr(ip)
        host=repr(data[0])
        return host
    except Exception:
       
        return False

x=raw_input("URL or IP >  ")
data=x.split(".")
first=data[0]

if (first.isdigit()):
	data=getHost(x)
	if data:
		print "IP : " + x + "\n" + "Host Name : " + data
	else:
		print "\nError : IP not Addressable" 
else:
	data=getIP(x)
	if data:
		print "Host Name : " + x + "\n" + "IP : " + data
	else:
		print "\nError : Domain Name Not Resolved" 

