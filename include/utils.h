#ifndef UTILS_H
#define UTILS_H

#define DEBUG_INFO "INFO"
#define DEBUG_WARN "WARN"
#define DEBUG_ERR  "ERR"

#define INDEX_HTML "index.html"

// HTTP methods
#define GET_METHOD  "GET"
#define HEAD_METHOD "HEAD"

// HTTP status codes
#define HTTP_STATUS_OK                 200
#define HTTP_STATUS_NOT_FOUND          404
#define HTTP_STATUS_FORBIDDEN          403
#define HTTP_STATUS_METHOD_NOT_ALLOWED 405

// HTTP response headers
#define HTTP_OK          "HTTP/1.1 200 OK\r\n"
#define HTTP_NOT_FOUND   "HTTP/1.1 404 Not Found\r\n"
#define HTTP_FORBIDDEN   "HTTP/1.1 403 Forbidden\r\n"
#define HTTP_NOT_ALLOWED "HTTP/1.1 405 Method Not Allowed\r\n"

// HTTP response body messages
#define HTTP_NOT_FOUND_BODY   "<h1>404 Not Found</h1>"
#define HTTP_FORBIDDEN_BODY   "403 Forbidden"
#define HTTP_NOT_ALLOWED_BODY "405 Method Not Allowed"

// Declare template for HTTP response
static const char *HTTP_RESPONSE_TEMPLATE = "%s"
                                            "Server: milchenko\r\n"
                                            "Date: %s\r\n"
                                            "Content-Type: %s\r\n"
                                            "Content-Length: %d\r\n"
                                            "Connection: close\r\n"
                                            "\r\n";

int is_dir(char *path);

char *get_content_type(char *path);

void hex_to_ascii(char *hex_str, char *ascii_str);

void get_current_time(char *time_str);

int is_escaping_path(char *path, char *document_root);

#endif // UTILS_H
