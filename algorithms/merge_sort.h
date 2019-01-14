#include "utils.h"

using std::array;

namespace merge_sort {
	template<class T>
	struct queue_element {
		T value;
		shared_ptr<queue_element> next;
		
		queue_element(T initValue, shared_ptr<queue_element> initNext): value(initValue), next(initNext) {}
	};
	
	template<class T>
	class queue {
	public:
		bool is_empty() {
			return this->_head == nullptr;
		}
		
		void enqueue(T element) {
			auto new_element = std::make_shared<queue_element<T>>(element, nullptr);
			if ( is_empty() ) {
				this->_head = new_element;
			} else {
				auto current = this->_head;
				while ( true ) {
					auto next = current->next;
					if ( next == nullptr ) {
						current->next = new_element;
						return;
					}
					current = next;
				}
			}
		}
		
		shared_ptr<queue_element<T>> dequeue() {
			if ( !is_empty() ) {
				auto head = this->_head;
				this->_head = head->next;
				head->next.reset();
				return head;
			}
			return nullptr;
		}
		
		shared_ptr<queue_element<T>> peek() {
			if ( !is_empty() ) {
				return this->_head;
			}
			return nullptr;
		}
		
	private:
		shared_ptr<queue_element<T>> _head;
		
	};
	
	template<size_t Size>
	void merge(array<int, Size>& array, size_t low, size_t middle, size_t high) {
		queue<int> lowQueue;
		queue<int> highQueue;
		for ( auto i = low; i <= middle; i++ ) {
			lowQueue.enqueue(array[i]);
		}
		for ( auto i = middle + 1; i <= high; i++ ) {
			highQueue.enqueue(array[i]);
		}
		auto i = low;
		while ( !(lowQueue.is_empty() || highQueue.is_empty()) ) {
			if ( lowQueue.peek()->value <= highQueue.peek()->value ) {
				array[i] = lowQueue.dequeue()->value;
			} else {
				array[i] = highQueue.dequeue()->value;
			}
			i++;
		}
		while ( !lowQueue.is_empty() ) {
			array[i] = lowQueue.dequeue()->value;
			i++;
		}
		while ( !highQueue.is_empty() ) {
			array[i] = highQueue.dequeue()->value;
			i++;
		}
	}
	
	template<size_t Size>
	void merge_sort(array<int, Size>& array, size_t low, size_t high) {
		if ( low < high ) {
			auto middle = (low + high) / 2;
			merge_sort(array, low, middle);
			merge_sort(array, middle + 1, high);
			merge(array, low, middle, high);
		}
	}
	
	void run() {
		array<int, 7> arr      = {{  5, 10, 15, 8, 6,  1, -1 }};
		array<int, 7> expected = {{ -1,  1,  5, 6, 8, 10, 15 }};
		merge_sort(arr, 0, arr.size() - 1);
		assert_equals(arr, expected);
	}
}

