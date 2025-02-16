#ifdef UTESTS

// compile uising: 
// g++ rotated_sorted_buffer.cpp rotated_sorted_buffer_tests.cpp -DUTESTS -o rotated_sorted_buffer_tests

#include "utest.h"
#include "rotated_sorted_buffer.h"


class ArrayRABWrapper : public RotatedSortedBufferWrapper {

    public:
        ArrayRABWrapper(const uint32_t* buffer, size_t buffer_capacity, size_t buffer_size);
        virtual ~ArrayRABWrapper();
    
        size_t get_size() const;
        uint32_t get_value(size_t entry) const;
    
    private:
        const uint32_t* _buffer;
        size_t _buffer_capacity;
        size_t _buffer_size;
    };
    
    
    ArrayRABWrapper::ArrayRABWrapper(const uint32_t* buffer, size_t buffer_capacity, size_t buffer_size) {
        _buffer = buffer;
        _buffer_capacity = buffer_capacity;
        _buffer_size = buffer_size; 
    }
    
    ArrayRABWrapper::~ArrayRABWrapper() {
        // do nothing
    }
    
    
    size_t ArrayRABWrapper::get_size() const {
        return _buffer_size;
    }
    
    
    uint32_t ArrayRABWrapper::get_value(size_t entry) const {
        return _buffer[entry % _buffer_capacity];
    }
    
    
    UTEST(find_max, empty_buffer) {
        uint32_t buffer[1] = { };
        size_t buffer_size = 0;
    
        ArrayRABWrapper w = ArrayRABWrapper(buffer, buffer_size, buffer_size);
        int result = RotatedSortedBufferUtils::find_max_index(w);
    
        ASSERT_EQ(result, 0);
    }
    
    UTEST(find_max, single_element) {
        uint32_t buffer[] = { 0 };
        size_t buffer_size = 1;
    
        ArrayRABWrapper w = ArrayRABWrapper(buffer, buffer_size, buffer_size);
        int result = RotatedSortedBufferUtils::find_max_index(w);
    
        ASSERT_EQ(result, 0);
    }
    
    UTEST(find_max, not_rotated_two_elements) {
        uint32_t buffer[] = { 1, 2 };
        size_t buffer_size = 2;
    
        ArrayRABWrapper w = ArrayRABWrapper(buffer, buffer_size, buffer_size);
        int result = RotatedSortedBufferUtils::find_max_index(w);
    
        ASSERT_EQ(result, 1);
    }
    
    UTEST(find_max, rotated_two_elements) {
        uint32_t buffer[] = { 2, 1 };
        size_t buffer_size = 2;
    
        ArrayRABWrapper w = ArrayRABWrapper(buffer, buffer_size, buffer_size);
        int result = RotatedSortedBufferUtils::find_max_index(w);
    
        ASSERT_EQ(result, 0);
    }
    
    UTEST(find_max, not_rotated_three_elements) {
        uint32_t buffer[] = { 1, 2, 3 };
        size_t buffer_size = 3;
    
        ArrayRABWrapper w = ArrayRABWrapper(buffer, buffer_size, buffer_size);
        int result = RotatedSortedBufferUtils::find_max_index(w);
    
        ASSERT_EQ(result, 2);
    }
    
    UTEST(find_max, once_rotated_three_elements) {
        uint32_t buffer[] = { 3, 1, 2 };
        size_t buffer_size = 3;
    
        ArrayRABWrapper w = ArrayRABWrapper(buffer, buffer_size, buffer_size);
        int result = RotatedSortedBufferUtils::find_max_index(w);
    
        ASSERT_EQ(result, 0);
    }
    
    UTEST(find_max, double_rotated_three_elements) {
        uint32_t buffer[] = { 2, 3, 1 };
        size_t buffer_size = 3;
    
        ArrayRABWrapper w = ArrayRABWrapper(buffer, buffer_size, buffer_size);
        int result = RotatedSortedBufferUtils::find_max_index(w);
    
        ASSERT_EQ(result, 1);
    }
    
    UTEST(find_max, not_rotated_consecutive_even) {
        uint32_t buffer[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
        size_t buffer_size = 10;
    
        ArrayRABWrapper w = ArrayRABWrapper(buffer, buffer_size, buffer_size);
        int result = RotatedSortedBufferUtils::find_max_index(w);
    
        ASSERT_EQ(result, 9);
    }
    
    UTEST(find_max, n1_rotated_consecutive_even) {
        uint32_t buffer[] = { 10, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
        size_t buffer_size = 10;
    
        ArrayRABWrapper w = ArrayRABWrapper(buffer, buffer_size, buffer_size);
        int result = RotatedSortedBufferUtils::find_max_index(w);
    
        ASSERT_EQ(result, 0);
    }
    
    UTEST(find_max, n2_rotated_consecutive_even) {
        uint32_t buffer[] = { 9, 10, 1, 2, 3, 4, 5, 6, 7, 8 };
        size_t buffer_size = 10;
    
        ArrayRABWrapper w = ArrayRABWrapper(buffer, buffer_size, buffer_size);
        int result = RotatedSortedBufferUtils::find_max_index(w);
    
        ASSERT_EQ(result, 1);
    }
    
    UTEST(find_max, n3_rotated_consecutive_even) {
        uint32_t buffer[] = { 8, 9, 10, 1, 2, 3, 4, 5, 6, 7 };
        size_t buffer_size = 10;
    
        ArrayRABWrapper w = ArrayRABWrapper(buffer, buffer_size, buffer_size);
    
        int result = RotatedSortedBufferUtils::find_max_index(w);
    
        ASSERT_EQ(result, 2);
    }
    
    UTEST(find_max, n4_rotated_consecutive_even) {
        uint32_t buffer[] = { 7, 8, 9, 10, 1, 2, 3, 4, 5, 6 };
        size_t buffer_size = 10;
    
        ArrayRABWrapper w = ArrayRABWrapper(buffer, buffer_size, buffer_size);
        
        int result = RotatedSortedBufferUtils::find_max_index(w);
    
        ASSERT_EQ(result, 3);
    }
    
    UTEST(find_max, n5_rotated_consecutive_even) {
        uint32_t buffer[] = { 6, 7, 8, 9, 10, 1, 2, 3, 4, 5 };
        size_t buffer_size = 10;
    
        ArrayRABWrapper w = ArrayRABWrapper(buffer, buffer_size, buffer_size);
        
        int result = RotatedSortedBufferUtils::find_max_index(w);
    
        ASSERT_EQ(result, 4);
    }
    
    UTEST(find_max, n6_rotated_consecutive_even) {
        uint32_t buffer[] = { 5, 6, 7, 8, 9, 10, 1, 2, 3, 4 };
        size_t buffer_size = 10;
    
        ArrayRABWrapper w = ArrayRABWrapper(buffer, buffer_size, buffer_size);
        
        int result = RotatedSortedBufferUtils::find_max_index(w);
    
        ASSERT_EQ(result, 5);
    }
    
    UTEST(find_max, n7_rotated_consecutive_even) {
        uint32_t buffer[] = { 4, 5, 6, 7, 8, 9, 10, 1, 2, 3 };
        size_t buffer_size = 10;
    
        ArrayRABWrapper w = ArrayRABWrapper(buffer, buffer_size, buffer_size);
        
        int result = RotatedSortedBufferUtils::find_max_index(w);
    
        ASSERT_EQ(result, 6);
    }
    
    UTEST(find_max, n8_rotated_consecutive_even) {
        uint32_t buffer[] = { 3, 4, 5, 6, 7, 8, 9, 10, 1, 2 };
        size_t buffer_size = 10;
    
        ArrayRABWrapper w = ArrayRABWrapper(buffer, buffer_size, buffer_size);
        
        int result = RotatedSortedBufferUtils::find_max_index(w);
    
        ASSERT_EQ(result, 7);
    }
    
    UTEST(find_max, n9_rotated_consecutive_even) {
        uint32_t buffer[] = { 2, 3, 4, 5, 6, 7, 8, 9, 10, 1 };
        size_t buffer_size = 10;
    
        ArrayRABWrapper w = ArrayRABWrapper(buffer, buffer_size, buffer_size);
        
        int result = RotatedSortedBufferUtils::find_max_index(w);
    
        ASSERT_EQ(result, 8);
    }
    
    UTEST(find_max, not_rotated_consecutive_odd) {
        uint32_t buffer[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
        size_t buffer_size = 9;
    
        ArrayRABWrapper w = ArrayRABWrapper(buffer, buffer_size, buffer_size);
        int result = RotatedSortedBufferUtils::find_max_index(w);
    
        ASSERT_EQ(result, 8);
    }
    
    UTEST(find_max, n1_rotated_consecutive_odd) {
        uint32_t buffer[] = { 9, 1, 2, 3, 4, 5, 6, 7, 8 };
        size_t buffer_size = 9;
    
        ArrayRABWrapper w = ArrayRABWrapper(buffer, buffer_size, buffer_size);
        int result = RotatedSortedBufferUtils::find_max_index(w);
    
        ASSERT_EQ(result, 0);
    }
    
    UTEST(find_max, n2_rotated_consecutive_odd) {
        uint32_t buffer[] = { 8, 9, 1, 2, 3, 4, 5, 6, 7 };
        size_t buffer_size = 9;
    
        ArrayRABWrapper w = ArrayRABWrapper(buffer, buffer_size, buffer_size);
        int result = RotatedSortedBufferUtils::find_max_index(w);
    
        ASSERT_EQ(result, 1);
    }
    
    UTEST(find_max, n3_rotated_consecutive_odd) {
        uint32_t buffer[] = { 7, 8, 9, 1, 2, 3, 4, 5, 6 };
        size_t buffer_size = 9;
    
        ArrayRABWrapper w = ArrayRABWrapper(buffer, buffer_size, buffer_size);
    
        int result = RotatedSortedBufferUtils::find_max_index(w);
    
        ASSERT_EQ(result, 2);
    }
    
    UTEST(find_max, n4_rotated_consecutive_odd) {
        uint32_t buffer[] = { 6, 7, 8, 9, 1, 2, 3, 4, 5 };
        size_t buffer_size = 9;
    
        ArrayRABWrapper w = ArrayRABWrapper(buffer, buffer_size, buffer_size);
        
        int result = RotatedSortedBufferUtils::find_max_index(w);
    
        ASSERT_EQ(result, 3);
    }
    
    UTEST(find_max, n5_rotated_consecutive_odd) {
        uint32_t buffer[] = { 5, 6, 7, 8, 9, 1, 2, 3, 4 };
        size_t buffer_size = 9;
    
        ArrayRABWrapper w = ArrayRABWrapper(buffer, buffer_size, buffer_size);
        
        int result = RotatedSortedBufferUtils::find_max_index(w);
    
        ASSERT_EQ(result, 4);
    }
    
    UTEST(find_max, n6_rotated_consecutive_odd) {
        uint32_t buffer[] = { 4, 5, 6, 7, 8, 9, 1, 2, 3 };
        size_t buffer_size = 9;
    
        ArrayRABWrapper w = ArrayRABWrapper(buffer, buffer_size, buffer_size);
        
        int result = RotatedSortedBufferUtils::find_max_index(w);
    
        ASSERT_EQ(result, 5);
    }
    
    UTEST(find_max, n7_rotated_consecutive_odd) {
        uint32_t buffer[] = { 3, 4, 5, 6, 7, 8, 9, 1, 2 };
        size_t buffer_size = 9;
    
        ArrayRABWrapper w = ArrayRABWrapper(buffer, buffer_size, buffer_size);
        
        int result = RotatedSortedBufferUtils::find_max_index(w);
    
        ASSERT_EQ(result, 6);
    }
    
    UTEST(find_max, n8_rotated_consecutive_odd) {
        uint32_t buffer[] = { 2, 3, 4, 5, 6, 7, 8, 9, 1 };
        size_t buffer_size = 9;
    
        ArrayRABWrapper w = ArrayRABWrapper(buffer, buffer_size, buffer_size);
        
        int result = RotatedSortedBufferUtils::find_max_index(w);
    
        ASSERT_EQ(result, 7);
    }
    
    UTEST(find_max, not_rotated_odd) {
        uint32_t buffer[] = { 139, 263, 312, 493, 598, 6, 723, 857, 932 };
        size_t buffer_size = 9;
    
        ArrayRABWrapper w = ArrayRABWrapper(buffer, buffer_size, buffer_size);
        int result = RotatedSortedBufferUtils::find_max_index(w);
    
        ASSERT_EQ(result, 8);
    }
    
    UTEST(find_max, n1_rotated_odd) {
        uint32_t buffer[] = { 936, 194, 234, 394, 423, 529, 683, 734, 844 };
        size_t buffer_size = 9;
    
        ArrayRABWrapper w = ArrayRABWrapper(buffer, buffer_size, buffer_size);
        int result = RotatedSortedBufferUtils::find_max_index(w);
    
        ASSERT_EQ(result, 0);
    }
    
    UTEST(find_max, n2_rotated_odd) {
        uint32_t buffer[] = { 886, 934, 128, 255, 373, 428, 542, 689, 723 };
        size_t buffer_size = 9;
    
        ArrayRABWrapper w = ArrayRABWrapper(buffer, buffer_size, buffer_size);
        int result = RotatedSortedBufferUtils::find_max_index(w);
    
        ASSERT_EQ(result, 1);
    }
    
    UTEST(find_max, n3_rotated_odd) {
        uint32_t buffer[] = { 766, 824, 985, 157, 212, 376, 423, 553, 639 };
        size_t buffer_size = 9;
    
        ArrayRABWrapper w = ArrayRABWrapper(buffer, buffer_size, buffer_size);
    
        int result = RotatedSortedBufferUtils::find_max_index(w);
    
        ASSERT_EQ(result, 2);
    }
    
    UTEST(find_max, n4_rotated_odd) {
        uint32_t buffer[] = { 634, 796, 845, 978, 133, 245, 364, 445, 576 };
        size_t buffer_size = 9;
    
        ArrayRABWrapper w = ArrayRABWrapper(buffer, buffer_size, buffer_size);
        
        int result = RotatedSortedBufferUtils::find_max_index(w);
    
        ASSERT_EQ(result, 3);
    }
    
    UTEST(find_max, n5_rotated_odd) {
        uint32_t buffer[] = { 523, 665, 743, 829, 976, 134, 256, 322, 464 };
        size_t buffer_size = 9;
    
        ArrayRABWrapper w = ArrayRABWrapper(buffer, buffer_size, buffer_size);
        
        int result = RotatedSortedBufferUtils::find_max_index(w);
    
        ASSERT_EQ(result, 4);
    }
    
    UTEST(find_max, n6_rotated_odd) {
        uint32_t buffer[] = { 486, 534, 665, 794, 826, 955, 172, 245, 358 };
        size_t buffer_size = 9;
    
        ArrayRABWrapper w = ArrayRABWrapper(buffer, buffer_size, buffer_size);
        
        int result = RotatedSortedBufferUtils::find_max_index(w);
    
        ASSERT_EQ(result, 5);
    }
    
    UTEST(find_max, n7_rotated_odd) {
        uint32_t buffer[] = { 367, 434, 595, 622, 765, 843, 923, 154, 288 };
        size_t buffer_size = 9;
    
        ArrayRABWrapper w = ArrayRABWrapper(buffer, buffer_size, buffer_size);
        
        int result = RotatedSortedBufferUtils::find_max_index(w);
    
        ASSERT_EQ(result, 6);
    }
    
    UTEST(find_max, n8_rotated_odd) {
        uint32_t buffer[] = { 211, 357, 496, 535, 654, 756, 846, 943, 123 };
        size_t buffer_size = 9;
    
        ArrayRABWrapper w = ArrayRABWrapper(buffer, buffer_size, buffer_size);
        
        int result = RotatedSortedBufferUtils::find_max_index(w);
    
        ASSERT_EQ(result, 7);
    }


    UTEST_MAIN()

#endif // UTESTS