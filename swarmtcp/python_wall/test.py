
import socketserver
import sys
import signal
'''
##########thread for listening for dronekkit
def recv_dronekit():
    while True:
        data1, addr1 = sock2.recvfrom(1)
        #print data1,
        sock1.sendto(data1, ("192.168.0.6",2808))

#.......................key intrrupt...............
def signal_handler(signal, frame):
        print('######program terminated######')
        sock1.close()
        sock2.close()

        sys.exit(0)


signal.signal(signal.SIGINT, signal_handler)
#'''''''''''''''''''''''''''''''''''''''''''''''''''

class MyTCPHandler(socketserver.BaseRequestHandler):
    """
    The request handler class for our server.
    It is instantiated once per connection to the server, and must
    override the handle() method to implement communication to the
    client.
    """

    def handle(self):
        # self.request is the TCP socket connected to the client
        send_string = '65'
        print(1)
        self.data = self.request.recv(1024).strip()
        print("{} wrote:".format(self.client_address[0]))
        print self.data
        # just send b(ck the same data, but upper-cased
        self.request.sendall(send_string.encode())

if __name__ == "__main__":

    HOST, PORT = "192.168.43.72", 9113
    # Create the server, binding to localhost on port 9999
    server = socketserver.TCPServer((HOST, PORT), MyTCPHandler)

    # Activate the server; this will keep running until you
    # interrupt the program with Ctrl-C
server.serve_forever()
