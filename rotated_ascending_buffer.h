#ifndef _ROTATED_ASCENDING_BUFFER_H
#define _ROTATED_ASCENDING_BUFFER_H

#include <cstddef>
#include <cstdint>

/**
 * @brief Abstract base class for a rotated ascending buffer.
 * 
 * This class provides a wraptter interface for a buffer that stores elements in ascending order. 
 * The buffer may be rotated, meaning that the elements are shifted by some number of positions.
 */
class RotatedAscendingBufferWrapper {
public:
    
    /**
     * @brief Get the number of elements in the buffer.
     * @return The number of elements in the buffer.
     */
    virtual size_t get_size() const = 0;

    /**
     * @brief Get the value of the element at the given index.
     * @param index The index of the requested element.
     * @return The value of the element at the given index.
     */
    virtual uint32_t get_value(size_t index) const = 0;
};
    
/**
 * @brief Utility class for operations on RotatedAscendingBufferWrapper.
 */
class RotatedAscendingBufferUtils {
public:
    
     /**
     * @brief Find the index of the maximum element in the buffer.
     * @param buffer The buffer to search.
     * @return The index of the maximum element in the buffer.
     */
    static size_t find_max_index(RotatedAscendingBufferWrapper& buffer);
};
    

#endif // _ROTATED_ASCENDING_BUFFER_H