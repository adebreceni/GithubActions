#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>

int main(){
  char hostname[1024] = {};
  gethostname(hostname, 1024);
  std::cout << "Hostname: " << hostname << std::endl;
  addrinfo hints;
  memset(&hints, 0, sizeof hints);
  hints.ai_family = AF_UNSPEC;
  hints.ai_socktype = SOCK_STREAM;
  hints.ai_flags = AI_CANONNAME;
  hints.ai_protocol = 0;
  
  addrinfo* result = nullptr;
  const int errcode = getaddrinfo(static_cast<const char*>(hostname), "0", &hints, &result);
  
  if(errcode == 0){
    std::cout << "No error occured" << std::endl;
  }else{
    std::cout << "Error: " << gai_strerror(errcode) << std::endl;
  }
}
