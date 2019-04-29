#ifndef _CORE_GLOBAL_HPP_
#define _CORE_GLOBAL_HPP_

namespace CoRe {

/** A unique global ID that is incremented when using getUniqueId() */
extern long globalUID;

/**
 * @brief Generates a unique ID
 */
inline long getUniqueID()
{
    globalUID += 1;
    return globalUID;
}

}

#endif