// Copyright (C) 2016 David Reid. See included LICENSE file.

#ifdef DRED_WIN32
#define DRED_THREADING_WIN32
#else
#define DRED_THREADING_POSIX
#endif


///////////////////////////////////////////////////////////////////////////////
//
// Win32
//
///////////////////////////////////////////////////////////////////////////////
#ifdef DRED_THREADING_WIN32
bool dred_thread_create__win32(dred_thread* pThread, dred_thread_entry_proc entryProc, void* pData)
{
    *pThread = CreateThread(NULL, 0, entryProc, pData, 0, NULL);
    if (*pThread == NULL) {
        return false;
    }

    return true;
}

void dred_thread_wait__win32(dred_thread* pThread)
{
    WaitForSingleObject(*pThread, INFINITE);
}



bool dred_mutex_create__win32(dred_mutex* pMutex)
{
    *pMutex = CreateEventA(NULL, FALSE, TRUE, NULL);
    if (*pMutex == NULL) {
        return false;
    }

    return true;
}

void dred_mutex_delete__win32(dred_mutex* pMutex)
{
    CloseHandle(*pMutex);
}

void dred_mutex_lock__win32(dred_mutex* pMutex)
{
    WaitForSingleObject(*pMutex, INFINITE);
}

void dred_mutex_unlock__win32(dred_mutex* pMutex)
{
    SetEvent(*pMutex);
}



bool dred_semaphore_create__win32(dred_semaphore* pSemaphore, int initialValue)
{
    *pSemaphore = CreateSemaphoreA(NULL, initialValue, LONG_MAX, NULL);
    if (*pSemaphore == NULL) {
        return false;
    }

    return true;
}

void dred_semaphore_delete__win32(dred_semaphore* pSemaphore)
{
    CloseHandle(*pSemaphore);
}

bool dred_semaphore_wait__win32(dred_semaphore* pSemaphore)
{
    return WaitForSingleObject(*pSemaphore, INFINITE) == WAIT_OBJECT_0;
}

bool dred_semaphore_release__win32(dred_semaphore* pSemaphore)
{
    return ReleaseSemaphore(*pSemaphore, 1, NULL) != 0;
}
#endif  // Win32


///////////////////////////////////////////////////////////////////////////////
//
// Posix
//
///////////////////////////////////////////////////////////////////////////////
#ifdef DRED_THREADING_POSIX
bool dred_thread_create__posix(dred_thread* pThread, dred_thread_entry_proc entryProc, void* pData)
{
}

void dred_thread_wait__posix(dred_thread* pThread)
{
}



bool dred_mutex_create__posix(dred_mutex* pMutex)
{
}

void dred_mutex_delete__posix(dred_mutex* pMutex)
{
}

void dred_mutex_lock__posix(dred_mutex* pMutex)
{
}

void dred_mutex_unlock__posix(dred_mutex* pMutex)
{
}



bool dred_semaphore_create__posix(dred_semaphore* pSemaphore, int initialValue)
{
}

void dred_semaphore_delete__posix(dred_semaphore* pSemaphore)
{
}

bool dred_semaphore_wait__posix(dred_semaphore* pSemaphore)
{
}

bool dred_semaphore_release__posix(dred_semaphore* pSemaphore)
{
}
#endif  // Posix




//// Thread ////

bool dred_thread_create(dred_thread* pThread, dred_thread_entry_proc entryProc, void* pData)
{
    if (pThread == NULL || entryProc == NULL) {
        return false;
    }

#ifdef DRED_THREADING_WIN32
    return dred_thread_create__win32(pThread, entryProc, pData);
#endif

#ifdef DRED_THREADING_POSIX
    return dred_thread_create__posix(pThread, entryProc, pData);
#endif
}

void dred_thread_wait(dred_thread* pThread)
{
    if (pThread == NULL) {
        return;
    }

#ifdef DRED_THREADING_WIN32
    dred_thread_wait__win32(pThread);
#endif

#ifdef DRED_THREADING_POSIX
    dred_thread_wait__posix(pThread);
#endif
}


//// Mutex ////

bool dred_mutex_create(dred_mutex* pMutex)
{
    if (pMutex == NULL) {
        return false;
    }

#ifdef DRED_THREADING_WIN32
    return dred_mutex_create__win32(pMutex);
#endif

#ifdef DRED_THREADING_POSIX
    return dred_mutex_create__posix(pMutex);
#endif
}

void dred_mutex_delete(dred_mutex* pMutex)
{
    if (pMutex == NULL) {
        return;
    }

#ifdef DRED_THREADING_WIN32
    dred_mutex_delete__win32(pMutex);
#endif

#ifdef DRED_THREADING_POSIX
    dred_mutex_delete__posix(pMutex);
#endif
}

void dred_mutex_lock(dred_mutex* pMutex)
{
    if (pMutex == NULL) {
        return;
    }

#ifdef DRED_THREADING_WIN32
    dred_mutex_lock__win32(pMutex);
#endif

#ifdef DRED_THREADING_POSIX
    dred_mutex_lock__posix(pMutex);
#endif
}

void dred_mutex_unlock(dred_mutex* pMutex)
{
    if (pMutex == NULL) {
        return;
    }

#ifdef DRED_THREADING_WIN32
    dred_mutex_unlock__win32(pMutex);
#endif

#ifdef DRED_THREADING_POSIX
    dred_mutex_unlock__posix(pMutex);
#endif
}


//// Semaphore ///

bool dred_semaphore_create(dred_semaphore* pSemaphore, int initialValue)
{
    if (pSemaphore == NULL) {
        return false;
    }

#ifdef DRED_THREADING_WIN32
    return dred_semaphore_create__win32(pSemaphore, initialValue);
#endif

#ifdef DRED_THREADING_POSIX
    return dred_semaphore_create__posix(pSemaphore, initialValue);
#endif
}

void dred_semaphore_delete(dred_semaphore* pSemaphore)
{
    if (pSemaphore == NULL) {
        return;
    }

#ifdef DRED_THREADING_WIN32
    dred_semaphore_delete__win32(pSemaphore);
#endif

#ifdef DRED_THREADING_POSIX
    dred_semaphore_delete__posix(pSemaphore);
#endif
}

bool dred_semaphore_wait(dred_semaphore* pSemaphore)
{
    if (pSemaphore == NULL) {
        return false;
    }

#ifdef DRED_THREADING_WIN32
    return dred_semaphore_wait__win32(pSemaphore);
#endif

#ifdef DRED_THREADING_POSIX
    return dred_semaphore_wait__win32(pSemaphore);
#endif
}

bool dred_semaphore_release(dred_semaphore* pSemaphore)
{
    if (pSemaphore == NULL) {
        return false;
    }

#ifdef DRED_THREADING_WIN32
    return dred_semaphore_release__win32(pSemaphore);
#endif

#ifdef DRED_THREADING_POSIX
    return dred_semaphore_release__posix(pSemaphore);
#endif
}