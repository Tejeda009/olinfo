#include <bits/stdc++.h>

struct Message {
    int src;
    int dst;
    std::string payload;
};


void net_send(Message);
Message net_recv();

enum class states : std::uint8_t {
    IDLE,
    SYN_SENT,
    CONNECTED
};


struct Client {

public:
    int id;
    int server_id;
    states state;

    Client(const int id, const int server_id) : id(id), server_id(server_id) {
        state = states::IDLE;
    };

    void connect() {
        if (state == states::IDLE) {
            Message message = {id, server_id, "SYN"};
            net_send(message);
            state = states::SYN_SENT;
        } 
    }

    void tick() {
        while (true) {
            std::optional<Message> msg = net_recv();

            if (!msg) break;

            if (msg->dst == id && msg -> src == server_id) {
                if (state == states::SYN_SENT && msg->payload == "SYN-ACK") {
                    net_send({id, server_id, "ACK"});
                    state = states::CONNECTED;
                }
            }
        }
    }

    bool connected() {
        return state == states::CONNECTED;
    }

};

struct Server {
    int id;
    std::map<int, states> clients;

    Server(const int id) : id(id) {};

    void tick() {

        while (true) {
            std::optional<Message> msg = net_recv();
            if (!msg) break;

            if (msg->dst == id) {

                const auto it = clients.find(msg->src);
                if (it -> second == states::CONNECTED) continue;

                if (msg->payload == "SYN") {
                    

                    net_send({id, msg->src, "SYN-ACK"});
                    clients[msg->src] = states::SYN_SENT;
                } else if (msg->payload == "ACK") {

                    if (it != clients.end() && it->second == states::SYN_SENT) {
                        it->second = states::CONNECTED;
                    }
                }
            }

        }
    }

    bool has_connection(const int client_id) {
        const auto it = clients.find(client_id);

        return it != clients.end() && it -> second == states::CONNECTED;
    }

};