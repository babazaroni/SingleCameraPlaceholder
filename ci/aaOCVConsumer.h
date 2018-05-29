#ifndef AAOCVCONSUMER_H
#define AAOCVCONSUMER_H

#include <Argus/Argus.h>
#include <EGLStream/EGLStream.h>
#include "Thread.h"
#include "EGLGlobal.h"
#include "GLContext.h"
#include <NvEglRenderer.h>
#include "../common/config.h"
#include "../common/Queue.h"
#include "../common/aaDebug.h"
#include "../common/aaCircularBuffer.h"


namespace ArgusSamples
{

using namespace Argus;
using namespace EGLStream;


/*******************************************************************************
 * OCV Consumer thread:
 *   Creates a FrameConsumer object to consume frames from a stream,
 *   to perform open cv processing
 ******************************************************************************/


class aaNewOCVConsumerThread : public Thread
{
public:

    explicit aaNewOCVConsumerThread()
    {
    }

  aaNewOCVConsumerThread(OutputStream *stream,  NvEglRenderer *renderer, int id, Queue<frameBuffer> *q, aaCircularBuffer<aaEglFrameBuffer> *cbq, Queue<int> *msgq)
        : m_stream(stream),  m_renderer(renderer), m_id(id) , m_pinputFrameQ(q),  m_pinputFrameCB(cbq), m_pcamCapture2NewOCVConsumerMsgQ(msgq)
    {
    }

    ~aaNewOCVConsumerThread()
    {
    }
    void init_members(OutputStream *stream, ARGUSSIZE size, NvEglRenderer *renderer);

private:


    /** @name Thread methods */
    /**@{*/
    virtual bool threadInitialize();
    virtual bool threadExecute();
    virtual bool threadShutdown();
    /**@}*/

    OutputStream* m_stream;
    UniqueObj<FrameConsumer> m_consumer;
    ARGUSSIZE m_framesize;
    NvEglRenderer *m_renderer;
    int m_id;


    Queue<aaEglFrameBuffer> *m_pinputFrameQ;
    Queue<aaEglFrameBuffer> m_pinputFrameDelQ;

    Queue<int   > *m_pcamCapture2NewOCVConsumerMsgQ;
    aaCircularBuffer<aaEglFrameBuffer>  *m_pinputFrameCB;

    aaDebug       *m_pDebugObj;

};



} // namespace ArgusSamples

#endif // OCVCONSUMER
