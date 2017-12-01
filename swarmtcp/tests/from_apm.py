import serial
import sys
import signal
import time

####key inturrupt**************************************
def signal_handler(signal, frame):
        print('######program terminated######')
        port_apm.close()
        port_node.close()
        sys.exit(0)


signal.signal(signal.SIGINT, signal_handler)

##***************************************************

port_apm = serial.Serial("/dev/ttyACM0",115200)
port_node = serial.Serial('/dev/ttyUSB0',115200)

while True:
        c = port_apm.read()#read from apm
	#sys.stdout.write(c)
        port_node.write(c)#send to nodemcu
        #time.sleep()
        
        

