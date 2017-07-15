// Copyright (C) 2017 David Reid. See included LICENSE file.

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
//
// Win32
//
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
#ifdef DTK_WIN32
dtk_bool32 dtk_is_directory__win32(const char* path)
{
    dtk_assert(path != NULL);

    DWORD attributes = GetFileAttributesA(path);
    return attributes != INVALID_FILE_ATTRIBUTES && (attributes & FILE_ATTRIBUTE_DIRECTORY) != 0;
}
#endif


///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
//
// POSIX
//
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
#ifdef DTK_POSIX
dtk_bool32 dtk_is_directory__posix(const char* path)
{
    dtk_assert(path != NULL);

    struct stat info;
    if (stat(path, &info) != 0) {
        return DTK_FALSE;   // Likely the folder doesn't exist.
    }

    return (info.st_mode & S_IFDIR) != 0;
}
#endif


dtk_bool32 dtk_is_directory(const char* path)
{
    if (dtk_string_is_null_or_empty(path)) return DTK_FALSE;

#ifdef DTK_WIN32
    return dtk_is_directory__win32(path);
#endif
#ifdef DTK_POSIX
    return dtk_is_directory__posix(path);
#endif
}