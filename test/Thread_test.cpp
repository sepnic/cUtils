#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "osal/os_thread.h"
#include "cutils/memory_helper.h"
#include "cutils/log_helper.h"
#include "utils/UtilsCommon.h"
#include "utils/Thread.h"

#define LOG_TAG "ThreadTest"

SYSUTILS_NAMESPACE_USING

class ThreadTest : public Thread {
public:
    ThreadTest() {}
    ~ThreadTest() {}

    virtual bool readyToRun();
    virtual bool threadLoop();
};

bool ThreadTest::readyToRun()
{
    OS_LOGI(LOG_TAG, "-->readyToRun");
    return true;
}

bool ThreadTest::threadLoop()
{
    static int count = 0;
    OS_LOGI(LOG_TAG, "-->threadLoop, count=%d", count);
    count++;
    sleep(1);
    return true;
}

int main()
{
    ThreadTest *threadTest;
    OS_NEW(threadTest, ThreadTest);

    threadTest->run();
    sleep(5);

    threadTest->requestExitAndWait();

    OS_DELETE(threadTest);
    return 0;
}
