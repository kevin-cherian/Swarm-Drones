import serial
import sys
import signal
import time
import threading 

####key inturrupt**************************************
def signal_handler(signal, frame):
        print('######program terminated######')
        port_apm.close()
        port_node.close()
        #port_node2.close()
        sys.exit(0)


signal.signal(signal.SIGINT, signal_handler)

##***************************************************
def serialsend():
        
        while True:
                data1 = []
                for i in range(200):
                        c = ord(port_apm.read())#read from apm
	                data1.append(c)
                        #print chr(c),
                for c1 in data1:        
                        #sys.stdout.write(c)
                        port_node.write(chr(c1))#send to nodemcu
                #time.sleep()
def serialrecv():
        print("I cup")
        while True:
                print("I cup")
                c1 = ord(port_node.read())
                print chr(c1),
                port_apm.write(chr(c1))
                

port_apm = serial.Serial("/dev/ttyACM0",115200)
port_node = serial.Serial('/dev/ttyUSB0',115200)
#port_node2 = serial.Serial('/dev/ttyUSB1',115200)

t1 = threading.Thread(target=serialrecv)
t1.daemon = True
t1.start()

serialsend();


