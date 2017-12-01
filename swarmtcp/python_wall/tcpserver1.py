import SocketServer
import sys 
import signal

data_from_apm = []
data_from_dronekit = [] 
        
#.......................key intrrupt...............
def signal_handler(signal, frame):
        print('######program terminated######')
        #server.shutdown()
        server1.server_close()
        #server2.server_close()               
        sys.exit(0)


signal.signal(signal.SIGINT, signal_handler)
#'''''''''''''''''''''''''''''''''''''''''''''''''''

class MyTCPHandler(SocketServer.BaseRequestHandler):
    """
    The request handler class for our server.

    It is instantiated once per connection to the server, and must
    override the handle() method to implement communication to the
    client.
    """

    def handle(self):
        # self.request is the TCP socket connected to the client
        global data_from_apm
        
        if self.client_address[0] ==  "192.168.0.3":   
            
            data1 = self.request.recv(2048)
            lst = data1.split()#lst is list of integer strings
            print lst
            data_from_apm  = data_from_apm + lst
            self.request.sendall('1')
            
        elif self.client_address[0] ==  "192.168.0.5":
            final_packet = ""
            data2 = self.request.recv(2048)
            for int_str in data_from_apm:
                

                final_packet = final_packet + (chr(int(int_str)))#int-str -> int -> char, then write to the drone_kit client
            
            self.request.sendall(final_packet)    
            data_from_apm = []#we have cleaned everything in data_from_apm buffer list
            
        # just send back the same data, but upper-cased
           
            

                
if __name__ == "__main__":

    HOST, PORT = "192.168.0.5", 9996
    PORT2 = 9998
    # Create the server, binding to localhost on port 9999
    server1 = SocketServer.TCPServer((HOST, PORT), MyTCPHandler)
    #server2 = SocketServer.TCPServer((HOST, PORT2), MyTCPHandler)
    # Activate the server; this will keep running until you
    # interrupt the program with Ctrl-C
    server1.serve_forever()
    #server2.serve_forever()   
