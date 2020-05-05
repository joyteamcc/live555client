#include <unistd.h>
#include "wize/Log.h"
#include "wize/Component.h"
#include "wize/Packet.h"
#include "live555client/Live555Client.h"



////////////////////////////////////////////////////////////////////////////////


int main(int argc, char *argv[])
{
    printf("hello\n");

    // init packet pool
    tracepoint();
    wize::CPacketFactory::instance()->addPool<4*1024>();
    wize::CPacketFactory::instance()->addPool<8*1024>();
    wize::CPacketFactory::instance()->addPool<16*1024>();
    wize::CPacketFactory::instance()->addPool<32*1024>();
    wize::CPacketFactory::instance()->addPool<40*1024>();
    wize::CPacketFactory::instance()->addPool<64*1024>();
    wize::CPacketFactory::instance()->addPool<80*1024>();
    wize::CPacketFactory::instance()->addPool<128*1024>();

    tracepoint();

    //char const* url = "rtsp://admin:closeli@192.168.1.10:8554/live/1/0";
    //char const* url = "rtsp://admin:123456@192.168.1.117/H264?ch=1&subtype=0";
    char const* url = "rtsp://admin:admin@127.0.0.1:8554/live/0/media0";
    auto rtspclient = live555client::createRtspStream(url);

    rtspclient->start();
    sleep(10);
    rtspclient->stop();

    tracepoint();
    return 0;
}


