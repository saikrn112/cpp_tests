#!/usr/local/bin/python3
import signal

import socket
import threading
import socketserver

class ThreadedTCPRequestHandler(socketserver.BaseRequestHandler):

    def handle(self):
        data = str(self.request.recv(1024), 'ascii')
        cur_thread = threading.current_thread()
        response = bytes("{}: {}".format(cur_thread.name, data), 'ascii')
        self.request.sendall(response)

class ThreadedTCPServer(socketserver.ThreadingMixIn, socketserver.TCPServer):
    pass

def client(ip, port, message):
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as sock:
        sock.connect((ip, port))
        sock.sendall(bytes(message, 'ascii'))
        response = str(sock.recv(1024), 'ascii')
        print("Received: {}".format(response))

def cleanUp(signalnumber,frame):
    print('SignalRecieved[',str(signalnumber),']')
    return

if __name__ == '__main__':
    print('Called as a individual module')
    # Port 0 means to select an arbitrary unused port
    HOST, PORT = "localhost", 1234 

    server = ThreadedTCPServer((HOST, PORT), ThreadedTCPRequestHandler)
    with server:
        ip, port = server.server_address
        server.allow_reuse_address = True

        # Start a thread with the server -- that thread will then start one
        # more thread for each request
        server_thread = threading.Thread(target=server.serve_forever())
        # Exit the server thread when the main thread terminates
        server_thread.daemon = True
        print("Server loop running in thread:", server_thread.name)
        #server_thread.start()


else:
    print('Called as imported module')
