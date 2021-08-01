
#include "RtspStream.h"
#include "live555client/Live555Client.h"


namespace live555client {

stream::IStreamSourcePtr createRtspStream(char const* url, char const* username, char const* password)
{
    std::string full_url;
    if (username != NULL && password != NULL) {
        auto p = strstr(url, "://");
        if (p == NULL) {
            errorf("invalid url!\n");
            return stream::IStreamSourcePtr();
        }

        p += 3;
        full_url.assign(url, p);
        full_url += username;   // FIXME: url encode
        full_url += ":";
        full_url += password;   // FIXME: url encode
        full_url += "@";
        full_url += p;
        url = full_url.c_str();
    }

    tracef("url(%s)\n", url);
    return stream::IStreamSourcePtr(new CRtspStreamSource(url));
}

}
