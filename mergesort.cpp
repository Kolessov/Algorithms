#include <iostream>
#include <vector>

using namespace std;

template<typename InputIterator, typename OutputIterator, typename Compare>
OutputIterator Merge(InputIterator first_begin, InputIterator first_end, InputIterator second_begin,
                     InputIterator second_end, OutputIterator buffer_begin, Compare compare) {
    size_t current_first_index = 0, current_second_index = 0;

    while ((first_begin + current_first_index != first_end) &&
           (second_begin + current_second_index != second_end)) {
        if (compare(*(second_begin + current_second_index), *(first_begin + current_first_index))) {
            *buffer_begin = *(second_begin + current_second_index);
            ++current_second_index;
        } else {
            *buffer_begin = *(first_begin + current_first_index);
            ++current_first_index;
        }
        ++buffer_begin;
    }

    std::copy(first_begin + current_first_index, first_end, buffer_begin);
    return std::copy(second_begin + current_second_index, second_end, buffer_begin);
}


template<typename Iterator, typename Compare>
void MergeSort(Iterator begin, Iterator end,
    std::vector<typename std::iterator_traits<Iterator>::value_type>& buffer, Compare compare) {
    if (begin + 1 >= end) {
        return;
    }

    Iterator middle = begin + (end - begin) / 2;

    MergeSort(begin, middle, buffer, compare);
    MergeSort(middle, end, buffer, compare);

    Merge(begin, middle, middle, end, std::back_inserter(buffer), compare);

    std::copy(buffer.begin(), buffer.end(), begin);
    buffer.clear();
}

template<typename Iterator, typename Compare>
void Sort(Iterator begin, Iterator end, Compare compare) {
    std::vector<typename std::iterator_traits<Iterator>::value_type> additional_buffer;
    MergeSort(begin, end, additional_buffer, compare);
}

int main() {
  size_t size;
  cin >> size;
  vector<size_t> array(size);
  for (int i = 0; i < size; i++) {
    cin >> array[i];
  }
  MergeSort(array.begin(), array.end(), Compare());
  for (int i = 0; i < size; i++) {
    cout << array[i] << endl;
  }
  return 0;
}
