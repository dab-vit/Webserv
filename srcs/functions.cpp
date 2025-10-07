#include <sys/socket.h>
#include <netinet/in.h>
#include "particular_structs.hpp"
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/epoll.h>

int	socketDefinition(t_config& server_config)
{
	int			sockfd;
	int			newsockfd;
	unsigned int		rcvd_addr_len;
	struct sockaddr_in	serv_addr;
	struct sockaddr_in	rcvd_addr;

	(void) server_config;
	rcvd_addr_len = sizeof(rcvd_addr);
//	bzero((char *) &serv_addr, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = INADDR_ANY;
//	serv_addr.sin_port = htons(server_config.port_no);
	serv_addr.sin_port = htons(25315);
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd < 0)
	{
		std::cerr << SOCKET << std::endl;
		return (-1);
	}
	if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
	{
		std::cerr << BIND << std::endl;
		return (-1);
	}
//	listen(sockfd, server_config.connections_queue);	
	listen(sockfd, 3);
	newsockfd = accept(sockfd, (struct sockaddr *) &rcvd_addr, &rcvd_addr_len);
	if (newsockfd < 0)
	{
		std::cerr << ACCEPT << std::endl;
		return (-1);
	}
	return (newsockfd);
}

int	epollOperation(int newsockfd, t_objects& objs)
{
	int			epfd;
	int			ready_fd_num;
	struct epoll_event	event;
	struct epoll_event	events[MAX_EVENTS];
	char			buffer[MAX_BUFFER_SIZE];

	event.events = EPOLLIN | EPOLLOUT | EPOLLET;
	event.data.fd = newsockfd;
	epfd = epoll_create1(0);
	if (epfd == -1)
	{
		std::cerr << EPOLL_CREATE << std::endl;
		return (INTERNAL_SERVER_ERROR);
	}
	if (epoll_ctl(epfd, EPOLL_CTL_ADD, newsockfd, &event))
	{
		std::cerr << EPOLL_CTL << std::endl;
		return (INTERNAL_SERVER_ERROR);
	}
	ready_fd_num = epoll_wait(epfd, events, MAX_EVENTS, -1);
	if (ready_fd_num == -1)
	{
		std::cerr << EPOLL_WAIT << std::endl;
		return (INTERNAL_SERVER_ERROR);
	}
	read(newsockfd, buffer, MAX_BUFFER_SIZE);
	objs.req.setRequestStr(buffer);
	epoll_ctl(epfd, EPOLL_CTL_DEL, newsockfd, &event);
	close(newsockfd);
	close(epfd);	
	return (0);
}

void	parseInput(t_objects& objs, int& code, t_definitions& def)
{
	code = objs.check_rcvd_req.checkRcvdRequest(objs.req.getRequestStr());
	if (!code)
		code = objs.req.parseRequest();
	if (!code)
		code = objs.req_line.parseRequestLine(objs.req.getRequestLine(), def.implemented_methods);
	if (!code)
		code = objs.check_req_line.checkRequestLine(objs.req_line, def);
	if (!code)
		code = objs.req_heads.parseHeaders(objs.req.getHeaders(), def, objs.specific_header);
	if (!code && !objs.specific_header.host.getHostHeadersNum())
		code = BAD_REQUEST;
}

int	serverExecution(t_objects& objs, t_exec& exec, const t_definitions& def)
{
	int	code;

	code = 0;
	switch (objs.req_line.getMethod())
	{
		case GET:
			std::cout << "execution get" << std::endl;
			code = exec.get_method->execParticularMethod(objs.req_line, objs.res_body, objs.specific_header, def);
			break;
/*		case POST:
			code = exec.post_method->execParticularMethod(objs);
			break;
		case DELETE:
			code = exec.del_method->execParticularMethod(objs);
			break;
*/		default:
			break;
	}
	return (code);
}

int	parseOutput(t_objects& objs, int& status, const std::map<int, std::string>& err)
{
	std::cout << "STATUS_CODE " << status << std::endl;
	if (objs.res_status_line.parseStatusLineOut(objs.res, status, err))
		return (-1);
//	parseHeadersOut(status);
	if (objs.res_body.parseBodyOut(status, objs.res, objs.res_status_line, err))
		return (-1);
	objs.res.parseResponse();
	return (0);
}
