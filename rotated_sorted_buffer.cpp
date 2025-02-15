
#include "rotated_sorted_buffer.h"

size_t RotatedSortedBufferUtils::find_max_index(RotatedSortedBufferWrapper& buffer) {

    // cache buffer size locally
    size_t buffer_size = buffer.get_size(); 

    // no elements in buffer
    if (buffer_size == 0) {
        return 0;
    }

    // starting buffer boundaries
    int left_index = 0;
    int right_index = buffer_size - 1;

    // cache values locally
    uint32_t left_value = buffer.get_value(left_index);
    uint32_t right_value = buffer.get_value(right_index);
    
    // not rotated array
    if (left_value <= right_value) {
        return right_index;
    }

    // find the pivot element
    while (left_index < right_index) {

        // find middle elements prenting integer overflows
        int mid_index = left_index + (right_index - left_index) / 2;
    
        // cache values locally
        uint32_t mid_value = buffer.get_value(mid_index);
      
        // otherwise narrowing search range
        if (mid_value > right_value) {
            // max value in lower range
            left_index = mid_index + 1;
        } else {
            // max value in upper range
            right_index = mid_index;
            right_value = buffer.get_value(right_index);
        }
    }
    
    // return index of max element
    return (left_index == 0) ? buffer_size-1 : left_index-1;
}
