#ifndef _ROTATED_SORTED_BUFFER_H
#define _ROTATED_SORTED_BUFFER_H

#include <cstdint>

/**
* @brief Generic library error code
*/
static int32_t RSB_ERROR = -1;


/**
 * @brief Abstract base class for a rotated sorted buffer.
 * 
 * This class provides a wraptter interface for a buffer that stores elements in sorted order. 
 * The buffer may be rotated, meaning that the elements are shifted by some number of positions.
 */
class RotatedSortedBufferWrapper {
public:
    
    /**
     * @brief Get the number of elements in the buffer.
     * @return The number of elements in the buffer.
     */
    virtual int32_t get_size() const = 0;

    /**
     * @brief Get the value of the element at the given index.
     * @param index The index of the requested element.
     * @return The value of the element at the given index.
     */
    virtual int32_t get_value(uint32_t index) const = 0;
};
    
/**
 * @brief Utility class for operations on RotatedSortedBufferWrapper.
 */
class RotatedSortedBufferUtils {
public:
    
     /**
     * @brief Find the index of the maximum element in the buffer.
     * @param buffer The buffer to search.
     * @return The index of the maximum element in the buffer.
     */
    static int32_t find_max_index(RotatedSortedBufferWrapper& buffer);
};
    

#endif // _ROTATED_SORTED_BUFFER_H