#include <stdio.h>
#include <zmq.hpp>

#include "conf.h"
#include "data.h"
#include "json.h"
#include "db.h"

void send(config_t config, char *data)
{
        zmq::context_t context(1);

        //  Socket to send messages on
        zmq::socket_t  sender(context, ZMQ_PUSH);
        sender.connect("tcp://192.168.70.125:5555");

	zmq::message_t message(1024);

	snprintf ((char *) message.data(), 1024, "%s", data);

	sender.send(message);

	printf("[%s]\n", data);
}

void recv(config_t config)
{
        zmq::context_t context(1);

        //  Socket to receive messages on
        zmq::socket_t receiver(context, ZMQ_PULL);
        receiver.bind("tcp://*:5555");

	while(1) {

		zmq::message_t message(1024);

		receiver.recv(&message);

		printf("%s\n", (char*)message.data());
		char *data = (char*)message.data();

		json_parser(data);

		db_write(data);

		file_write(data);	
	}
}
