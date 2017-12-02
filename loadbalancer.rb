require "socket"

loadbalancer = TCPServer.open("192.168.174.129",2000)

while true
client = loadbalancer.accept

rhost = client.peeraddr.last
puts "#{rhost} connect to loadbalancer"

fromclient = client.gets
puts "message from client : #{fromclient}"

if fromclient == "lelaki"
sockettoserver1 = TCPSocket.open("192.168.189.129",3000)
sockettoserver1.write(fromclient)
sockettoserver1.close

else if fromclient == "perempuan"
sockettoserver2 = TCPSocket.open("192.168.189.130",4000)
sockettoserver2.write(fromclient)
sockettoserver2.close

else
puts "ERROR!!"

end
end
end
