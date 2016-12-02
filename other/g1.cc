#include <cstdio>
#include <cstring>

int read_file(int fd, char *buf, int size) {
    static int pos = 0, len = 0;
    const int MX = 1024;
    static char db[MX];
    int ret = 0;
    while (size >= len - pos) {
        memcpy(buf + ret, db + pos, len - pos);
        ret += len - pos;
        size -= len - pos;
        len = read(fd, db, MX);
        pos = 0;
        if (len == 0) return ret;
    }
    memcpy(buf + ret, db + pos, size);
    pos += size;
    ret += size;
    return ret;
}

int main() {
    
    assert();
}
