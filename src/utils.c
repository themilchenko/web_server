#include <sys/stat.h>
#include <string.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

#include "utils.h"

int is_dir(char *path) {
    struct stat path_stat;
    if (stat(path, &path_stat) == 0) {
        return S_ISDIR(path_stat.st_mode);
    }
    return 0;
}

char *get_content_type(char *path) {
    char *extension = strrchr(path, '.');
    
    if (extension == NULL) {
        return "text/plain";
    }
    if (strcmp(extension, ".html") == 0) {
        return "text/html";
    }
    if (strcmp(extension, ".css") == 0) {
        return "text/css";
    }
    if (strcmp(extension, ".js") == 0) {
        return "application/javascript";
    }
    if (strcmp(extension, ".jpeg") == 0 || 
        strcmp(extension, ".jpg") == 0) {
        return "image/jpeg";
    }
    if (strcmp(extension, ".png") == 0) {
        return "image/png";
    }
    if (strcmp(extension, ".gif") == 0) {
        return "image/gif";
    }
    if (strcmp(extension, ".swf") == 0) {
        return "application/x-shockwave-flash";
    }
    return "text/plain";
}

void hex_to_ascii(char *hex_str, char *ascii_str) {
    size_t j = 0;
    for (size_t i = 0; i < strlen(hex_str); i++) {
        if (hex_str[i] == '%') {
            if (i + 2 < strlen(hex_str) && isxdigit(hex_str[i+1]) && isxdigit(hex_str[i+2])) {
                char hex[3] = { hex_str[i+1], hex_str[i+2], '\0' };
                int value = strtol(hex, NULL, 16);
                ascii_str[j++] = value;
                i += 2;
            } else {
                ascii_str[j++] = hex_str[i];
            }
        } else {
            ascii_str[j++] = hex_str[i];
        }
    }
    ascii_str[j] = '\0';
}

void get_current_time(char *time_str) {
    time_t now = time(NULL);
    struct tm *tm = gmtime(&now);
    strftime(time_str, sizeof(time_str), "%a, %d %b %Y %H:%M:%S GMT", tm);
}

int is_escaping_path(char *path, char *document_root) {
    char absolute_path[1024];
    char *real_path = realpath(path, absolute_path);
    if (real_path == NULL) {
        return 1;
    }
    
    char *contains = strstr(absolute_path, document_root);
    return contains == NULL;
}
