// ReSharper disable CppClangTidyClangDiagnosticCpp17Extensions

#pragma once
#pragma warning (push)
#pragma warning (disable : 4984)

#include <enginecore.h>
#include <string>

class ENGINECORE_EXPORT Logging
{
public:
    template<class...Args>
    static constexpr void Log(const std::string& inFormat, Args&& ...args)
    {
        if constexpr (true)
        {
            SDL_Log(inFormat.c_str(), std::forward<Args>(args)...);
        }
    }
};

#pragma warning (pop)
