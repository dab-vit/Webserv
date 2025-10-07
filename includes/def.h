#ifndef STATUS_H
# define STATUS_H

//REFERENCES DEFINITIONS
#define REF "\r\n"
//#define REF "\\r\\n"
#define REF2 " "
#define OWS " \t\n\v\f\r"

//HTTP DEFINITIONS
#define METHOD 0
#define REQUEST_TARGET 1
#define VER "HTTP/1.1"

//SERVER MESSAGES
#define OK 200
#define E201 "Created\n"
#define E204 "No Content\n"
#define E301 "Moved Permanently\n"
#define E302 "Found\n"
#define BAD_REQUEST 400
#define E403 "Forbidden\n"
#define NOT_FOUND 404
#define METHOD_NOT_ALLOWED 405
#define E413 "Payload Too Large\n"
#define INTERNAL_SERVER_ERROR 500
#define NOT_IMPLEMENTED 501
#define E502 "Bad Gateway\n"
#define E503 "Service Unavailable\n"
#define E504 "Gateway Timeout\n"
#define E505 "HTTP Version Not Supported\n"
/*
#define "Uri Too Long"
#define "Expectation Failed"
#define "Request Header Fields Too Large"
#define "Unsupported media type"
*/

//PROGRAM ERRORS
#define OUT_OF_RANGE "Variable \"pos\" in substr function is greater than string size\n"
#define BAD_ALLOC "Error allocating memory\n"
#define LENGTH_ERROR "Maximum string length due to implementation limitations reached\n"
#define ARGS "Wrong arguments number\n"
#define INTERNAL_SERVER_ERROR_PHRASE "Internal server error"
#define SOCKET "Error opening socket\n"
#define BIND "Socket address binding failed\n"
#define ACCEPT "Socket did not accept connection\n"
#define EPOLL_CREATE "System could not create epoll instance\n"
#define EPOLL_CTL "System could not add/del/modify fd in epoll instance\n"
#define EPOLL_WAIT "System epoll_wait call failed\n"
#define OPEN_DIR "Error opening directory\n"
#define CLOSE_DIR "Error closing directory\n"
#define OPEN_FILE "Error opening file\n"
#define MODIFY "Trying to modify response\n"

//DEFAULT SETTINGS
#define DEFAULT_PATH "web_server/default_config"
#define DEFAULT_MAX_CONN_QUEUE 5
#define MAX_EVENTS 1
#define MAX_BUFFER_SIZE 5000

//SITES AND PATHS SERVED
#define ADDRESS "127.0.0.1"
#define SITE1 "prueba.com"
#define SITE2 "prueba2.com"
#define SITE3 "prueba3.com"
#define DEFAULT_SITE SITE1
#define PATH1 "web_server/web_content/site1"
#define PATH2 "web_server/web_content/site2"
#define PATH3 "web_server/web_content/site3"
#define	ERRORS_PATH "web_server/web_content/errors"

# endif //STATUS_H
