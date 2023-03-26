template <typename T>
class SetList {
    struct ListNode {
        T data;
        ListNode* next;
    };
    ListNode* head;
public:
    class iterator {
        ListNode* current;
    public:
        using iterator_category = std::forward_iterator_tag;
        using value_type = T;
        using pointer = T*;
        using reference = T&;
        using difference_type = std::ptrdiff_t;

        explicit iterator(ListNode* const ptr = nullptr) : current(ptr){}

        iterator& operator++(){
            current = current -> next;
            return *this;
        }

        iterator operator++(int){
            iterator temp = *this;
            current = current -> next;
            return temp;
        }

        reference operator*() const{
            return current -> data;
        }

        pointer operator->() const{
            return &(current -> data);
        }

        bool operator==(iterator const& other) const = default;
    };

    static_assert(std::forward_iterator<iterator>);
public:
    using value_type = T;

    SetList() : head(nullptr){}

    SetList(SetList const& other) = delete;

    SetList& operator=(SetList const& other) = delete;

    iterator begin(){
        return iterator(head);
    }

    iterator end(){
        return iterator(nullptr);
    }

    iterator find(T value){
        for (ListNode* curr = head; curr; curr = curr->next) {
            if (curr->data == value) {
                return iterator(curr);
            }
        }
        return iterator(nullptr);
    }

    iterator insert(iterator const, T value){
        iterator found = find(value);
        if (found != end()) {
            return found;
        }
        head = new ListNode{value, head};
        return iterator(head);
    }
    
    ~SetList(){
        while (head) {
            ListNode* next = head -> next;
            delete head;
            head = next;
        }
    }
};