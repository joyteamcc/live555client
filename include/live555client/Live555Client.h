#pragma once


#include "stream/StreamSource.h"


namespace live555client {


stream::IStreamSourcePtr createRtspStream(char const* url);


} // namespace

