
#include "Log.hpp"

#define HEX_PREFIX "$"

Log Log::sVerboseLog(true);
Log Log::sDebugLog(true);
Log Log::sTraceLog(true);
Log Log::sErrorLog(true);

Log::Log(const bool enabled) : mEnabled(enabled) {
}

Log& Log::dbg(const char *tag) {
    sDebugLog.mTag = tag;
    return sDebugLog;
}

Log& Log::vrb(const char *tag) {
    sVerboseLog.mTag = tag;
    return sVerboseLog;
}

Log& Log::trc(const char *tag) {
    sTraceLog.mTag = tag;
    return sTraceLog;
}

Log& Log::err(const char *tag) {
    sErrorLog.mTag = tag;
    return sErrorLog;
}

Log &Log::str(const char *msg) {
    if (mEnabled) mStream << msg;
    return *this;
}

Log &Log::hex(uint32_t val) {
    if (mEnabled) mStream << HEX_PREFIX << std::hex << val;
    return *this;
}

Log &Log::hex(uint32_t val, uint8_t w) {
    if (mEnabled) mStream << HEX_PREFIX << std::setw(w) << std::setfill('0') << std::hex << val;
    return *this;
}

Log &Log::dec(uint32_t val) {
    if (mEnabled) mStream << std::dec << val;
    return *this;
}

Log &Log::dec(uint32_t val, uint8_t w) {
    if (mEnabled) mStream << std::setw(w) << std::setfill('0') << val;
    return *this;
}

Log &Log::sp() {
    if (mEnabled) mStream << " ";
    return *this;
}

void Log::show() {
    if (mEnabled) {
        std::cout << mTag << ": " << mStream.str() << std::endl;
        mStream.str("");
        mStream.clear();
    }
}

