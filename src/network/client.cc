#include <string>

#include <grpcpp/grpcpp.h>
#include "network.grpc.pb.h"

using grpc::Channel;
using grpc::ClientContext;
using grpc::Status;

using network::Network;
using network::Query;
using network::QueryResponse;
using network::Credentials;
using network::AuthResponse;

class NetworkClient {
    public:
        NetworkClient(std::shared_ptr<Channel> channel) : stub_(Network::NewStub(channel)) {}

    std::string sendRequest(std::string user, std::string password) {
        Credentials request;

        request.set_user(user);
        request.set_password(password);

        AuthResponse reply;

        ClientContext context;

        Status status = stub_->auth(&context, request, &reply);

        if(status.ok()){
            return reply.token();
        } else {
            std::cout << status.error_code() << ": " << status.error_message() << std::endl;
            return reply.token();
        }
    }

    private:
        std::unique_ptr<Network::Stub> stub_;
};

void Run() {
    std::string address("0.0.0.0:5000");
    NetworkClient client(
        grpc::CreateChannel(
            address, 
            grpc::InsecureChannelCredentials()
        )
    );

    std::string response;
    std::string user;
    std::string password;
    std::cout << "User: ";
    std::cin >> user;
    std::cout << "Password: ";
    std::cin >> password;
    response = client.sendRequest(user,password);
    std::cout << "Answer received: User - " << user << " Password - " << password << " : " << response << std::endl;
}

int main(int argc, char* argv[]){
    Run();

    return 0;
}