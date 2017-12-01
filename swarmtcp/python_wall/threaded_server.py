import threading
import SocketServer
import sys 
import signal
from time import sleep
import socket
import Queue

data_from_apm = Queue.Queue()
data_from_dronekit = Queue.Queue()

sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)      
#.......................key intrrupt...............
def signal_handler(signal, frame):
    print('######program terminated######')
    server1.shutdown()
    server1.server_close()
    #server2.server_close() 
    sock.close()
                  
    sys.exit(0)


signal.signal(signal.SIGINT, signal_handler)
#'''''''''''''''''''''''''''''''''''''''''''''''''''
def clientsend():
    # Connect to server and send data
    global data_from_dronekit
    sock.connect(("192.168.0.2", 9991))
    sleep(2)
    print("connected")
    
    while True:
        
        #print("hi")
        while not data_from_dronekit.empty(): 
            each = data_from_dronekit.get()
            sock.sendall(chr(each))#send each char by char
            data_from_dronekit.task_done()
            #print chr(each),
            #print("....................................") 
            received = sock.recv(1)

#...........................................................
class ThreadedTCPRequestHandler(SocketServer.BaseRequestHandler):   
    """
    The request handler class for our server.

    It is instantiated once per connection to the server, and must
    override the handle() method to implement communication to the
    client.
    """

    def handle(self):
        # self.request is the TCP socket connected to the client
        global data_from_apm
        global data_from_dronekit
        
        if self.client_address[0] ==  "192.168.0.3":   
            
            data1 = self.request.recv(2048)
            lst = data1.split()#lst is list of integer strings
            #print lst

            for i in lst:
                #print(chr(int(i))),
                data_from_apm.put(i)

            self.request.sendall('1')
#...............................................................            
        elif self.client_address[0] ==  "192.168.0.5":
           while True: 
                
                data2 = self.request.recv(2048)
                for each_char in data2:
                    data_from_dronekit.put(ord(each_char))#e
                    #print each_char,
                
            
               
                while not data_from_apm.empty():        
                        int_str = data_from_apm.get()
                        self.request.send(chr(int(int_str)))#int-str -> int -> char, then write to the drone_kit client
                        print chr(int(int_str))
                        data_from_apm.task_done()        
                      
                #self.request.sendall(final_packet)  
                #data_from_apm = []#we have cleaned everything in data_from_apm buffer list
               # print("......................................................................................................................................................")
        # just send back the same data, but upper-cased
 

class ThreadedTCPServer(SocketServer.ThreadingMixIn, SocketServer.TCPServer):
    pass         
            

                
if __name__ == "__main__":

    HOST, PORT = "192.168.0.5", 9999
    
    # Create the server, binding to loca`9host on port 9999
    server1 = ThreadedTCPServer((HOST, PORT), ThreadedTCPRequestHandler)
    #server2 = SocketServer.TCPServer((HOST, PORT2), MyTCPHandler)
    # Activate the server; this will keep running until you
    # interrupt the program with Ctrl-C
    server_thread = threading.Thread(target=server1.serve_forever)
    # Exit the server thread when the main thread terminates
    server_thread.daemon = True
    server_thread.start()
    
    clientsend()
    
    
    

    
    #server1.serve_forever()
    #server2.serve_forever()   
