#include "ProcessThread.h"
#include <base/Logger.h>

namespace avg
{

    ProcessThread::ProcessThread(CQueue& CmdQ):
        WorkerThread<ProcessThread>("WorkerThread", CmdQ)
    {
        AVG_LOG_WARNING("WORKER THREAD INIT");
    }

    ProcessThread::~ProcessThread(){
    }

    bool ProcessThread::init(){
        AVG_LOG_WARNING("Inited worker thread");
        return true;
    }

    void ProcessThread::deinit(){
        AVG_LOG_WARNING("Deinit Thread");
    }

    bool ProcessThread::work(){
        AVG_LOG_WARNING("work");
        usleep(10);
        return true;
    }

} /* avg */
