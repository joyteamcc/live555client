#ifndef __APP_RTSP_CLIENT_IMPL_H__
#define __APP_RTSP_CLIENT_IMPL_H__


#include <boost/bind.hpp>
#include "wize/LoopThread.h"
#include "wize/Component.h"
#include "stream/EncodeSpecific.h"
#include "stream/StreamSource.h"


namespace live555client {


class CRtspStreamSource : public stream::IStreamSource, public wize::CLoopThread
{
public:
    CRtspStreamSource(const char* uri);

    ~CRtspStreamSource();

    Connection connect(StreamCallback);

    /// 开启
    bool start();

    /// 停止
    bool stop();

private:
    CRtspStreamSource(CRtspStreamSource const&);
    CRtspStreamSource& operator=(CRtspStreamSource const&);

    void threadProc();
    void onStreamCallback(stream::CFrame const& frame);

private:
    std::string     mUri;
    char volatile   mEventLoopWatchVariable;
    Signal          mSignal;
};


} // namespace rtsp

#endif // __APP_RTSP_CLIENT_IMPL_H__

