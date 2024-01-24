/*
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License").
 * You may not use this file except in compliance with the License.
 * A copy of the License is located at
 *
 *     http://aws.amazon.com/apache2.0/
 *
 * or in the "license" file accompanying this file. This file is distributed
 * on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either
 * express or implied. See the License for the specific language governing
 * permissions and limitations under the License.
 */

#ifndef ALEXA_CLIENT_SDK_AVSCOMMON_UTILS_INCLUDE_AVSCOMMON_UTILS_LOGGER_THREADMONIKER_H_
#define ALEXA_CLIENT_SDK_AVSCOMMON_UTILS_INCLUDE_AVSCOMMON_UTILS_LOGGER_THREADMONIKER_H_

#include <iomanip>
#include <string>
#include <sstream>
#include <thread>

namespace alexaClientSDK {
namespace avsCommon {
namespace utils {
namespace logger {

/**
 * Class to provide unique name for execution context.
 *
 * This class provides management for thread-local execution context identifiers. Execution context identifier is a
 * hexadecimal string which is managed by facilities like @c Executor and @c Timer. Logging framework adds identifier
 * value to all messages to identify which executor or timer is running the task.
 *
 * @note The same identifier can be reused by different threads, but will have the same context.
 */
class ThreadMoniker {
public:
    /// Prefix value for executor monikers.
    static constexpr char PREFIX_EXECUTOR = 'e';

    /// Prefix value for timer monikers.
    static constexpr char PREFIX_TIMER = 't';

    /**
     * Get the moniker for the caller's thread.
     *
     * Method returns identifier value assigned to the current thread by a call to #setThisThreadMoniker(). If the value
     * has not been previously set, a new value is generated by #generateMoniker(), assigned to the current thread, and
     * returned.
     *
     * @return The moniker for the caller's thread.
     */
    static std::string getThisThreadMoniker() noexcept;

    /**
     * Generate a unique moniker.
     *
     * This method generates a fixed-width moniker string. By default the value is a alpha-numeric string, prepended
     * with spaces. If the \a prefix is specified, the value also includes prefix character with colon.
     *
     * @param prefix Optional prefix for moniker value. If @a prefix if not 0, it is used for generating moniker.
     * Some of prefix values are reserved for use by ACSDK: 't' prefix is used by timers, and 'e' prefix is used by
     * executors.
     *
     * @return A new unique moniker.
     */
    static std::string generateMoniker(char prefix = 0) noexcept;

    /**
     * Set the moniker for the caller's thread.
     *
     * This method sets identifier value for the caller's thread. Any subsequent calls to #getThisThreadMoniker() will
     * return @a moniker value.
     *
     * @param moniker The moniker for @c std::this_thread.
     */
    static void setThisThreadMoniker(const std::string& moniker) noexcept;

private:
    /**
     * Constructor.
     */
    ThreadMoniker() = delete;
};

}  // namespace logger
}  // namespace utils
}  // namespace avsCommon
}  // namespace alexaClientSDK

#endif  // ALEXA_CLIENT_SDK_AVSCOMMON_UTILS_INCLUDE_AVSCOMMON_UTILS_LOGGER_THREADMONIKER_H_
