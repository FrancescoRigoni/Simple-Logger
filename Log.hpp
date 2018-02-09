
#ifndef __LOG__
#define __LOG__

#include <stdint.h>
#include <iostream>
#include <sstream>
#include <iomanip>

class Log {
    private:
        static Log sDebugLog;
        static Log sVerboseLog;
        static Log sTraceLog;
        static Log sErrorLog;
        
        Log(const bool);
        const char *mTag;
        const bool mEnabled;
        std::ostringstream mStream;
        
    public:
        // Returns debug log
        static Log& dbg(const char *);
        // Returns verbose log
        static Log& vrb(const char *);
        // Returns trace log
        static Log& trc(const char *);
        // Returns error log
        static Log& err(const char *);
        
        Log &str(const char *);
        Log &hex(uint32_t);
        Log &hex(uint32_t, uint8_t);
        Log &dec(uint32_t);
        Log &dec(uint32_t, uint8_t);
        Log &sp();
        
        void show();
};

#endif

