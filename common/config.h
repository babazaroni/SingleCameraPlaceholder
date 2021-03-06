#ifndef __CONFIGH__
#define __CONFIGH__

#include <string>
#include <cstdio>
#include <ctime>
#include <cassert>
#include <vector>
#include <math.h>
#include <sstream>
#include <iomanip>
#include <iostream>
#include <cstdlib>
#include <vector>

#include <sys/time.h>


#include <opencv2/core/core.hpp>
#include "EGLGlobal.h"
#include <cuda.h>
#include <cuda_runtime.h>
#include "NvUtils.h"
#include "NvCudaProc.h"
#include "nvbuf_utils.h"
#include "NvBuffer.h"
#include "NvAnalysis.h"
#include "cudaEGL.h"

using namespace std;
using namespace cv;

#if 0
#define PRINT(...);    printf("" __VA_ARGS__);
#else
#define PRINT(...);   
#endif


#define USEPOSITIONONLY 1

#define FRAME_SIZE_X 1920
#define FRAME_SIZE_Y 1080

#define PITCH_SIZE_X 2048
#define PITCH_SIZE_Y 1024


struct aaEglFrameBuffer
{
	char           *dataY;
	char           *dataU;
	char           *dataV;

	int				fsizeY;
	int				fsizeU;
	int				fsizeV;

    CUeglFrame     eglFrame;
    CUgraphicsResource pResource;

	int framefd;

    NvBufferParams nvBufParams;

};

#ifdef ENABLETX2
#define ARGUSSIZE Argus::Size2D<uint32_t>
#define RESOLUTIONW resolution.width()
#define RESOLUTIONH resolution.height()
#elif ENABLETX1
#define ARGUSSIZE Argus::Size
#define RESOLUTIONW resolution.width
#define RESOLUTIONH resolution.height
#endif

//#define R281_MEMMAP 1

#define frameBuffer aaEglFrameBuffer
#define DELETE_BUFFER_THRESHOLD 4


namespace ArgusSamples
{
        extern EGLDisplayHolder g_display;
}

extern std::vector<aaEglFrameBuffer> eglFrameBufferList;
#endif
