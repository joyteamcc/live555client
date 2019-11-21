
#include "RtspStream.h"
#include "live555client/Live555Client.h"


namespace live555client {

stream::IStreamSourcePtr createRtspStream(char const* url)
{
    return stream::IStreamSourcePtr(new CRtspStreamSource(url));
}

}
