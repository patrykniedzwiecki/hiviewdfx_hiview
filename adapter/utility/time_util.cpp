/*
 * Copyright (c) 2021 Huawei Device Co., Ltd.
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "time_util.h"

#include <chrono>
#include <ctime>
namespace OHOS {
namespace HiviewDFX {
namespace TimeUtil {
time_t StrToTimeStamp(const std::string &tmStr, const std::string& format)
{
    std::string stTime = tmStr;
    struct tm tmFormat;
    strptime(stTime.c_str(), format.c_str(), &tmFormat);
    tmFormat.tm_isdst = -1;
    return mktime(&tmFormat);
}

uint64_t GetNanoTime()
{
    auto nanoNow = std::chrono::steady_clock::now().time_since_epoch();
    return nanoNow.count();
}
} // namespace TimeUtil
} // namespace HiviewDFX
} // namespace OHOS