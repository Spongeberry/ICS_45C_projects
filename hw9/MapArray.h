#include <vector>

template <typename Key, typename Value>
class MapArray {
    std::vector<std::pair<Key, Value>> vec;
public:
    class iterator{
        std::pair<Key, Value>* current;
    public:
        using iterator_categoty = std::random_access_iterator_tag;
        using value_type = std::pair<Key, Value>;
        using pointer = std::pair<Key, Value>*;
        using reference = std::pair<Key, Value>&;
        using difference_type = std::ptrdiff_t;

        explicit iterator(pointer const ptr = nullptr) : current(ptr) {}

        iterator& operator++(){
            ++current;
            return *this;
        }

        iterator& operator--(){
            --current;
            return *this;
        }

        iterator operator++(int){
            iterator temp(current);
            ++current;
            return temp;
        }

        iterator operator--(int){
            iterator temp(current);
            --current;
            return temp;
        }

        iterator& operator+=(difference_type const d){
            current += d;
            return *this;
        }

        iterator& operator-=(difference_type const d){
            current -= d;
            return *this;
        }

        friend iterator operator+(iterator i, difference_type const d){
            return i += d;
        }

        friend iterator operator+(difference_type const d, iterator i){
            return i += d;
        }

        friend iterator operator-(iterator i, difference_type const d){
            return i -= d;
        }

        friend iterator operator-(difference_type const d, iterator i){
            return i -= d;
        }

        friend difference_type operator-(iterator const i, iterator const j){
            return i.current - j.current;
        }

        auto operator <=> (iterator const& other) const = default;

        reference operator*() const{
            return *current;
        }

        pointer operator->() const{
            return current;
        }

        reference operator[](difference_type const d) const{
            return *(*this + d);
        }
    };

    static_assert(std::random_access_iterator<iterator>);

    using value_type = std::pair<Key, Value>;
    
    iterator begin(){
        return iterator(vec.data());
    }

    iterator end(){
        return iterator(vec.data() + vec.size());
    }

    Value& operator[](Key const& key){
        auto it = std::lower_bound(vec.begin(), vec.end(), key, 
            [](auto const& a, auto const& b) { return a.first < b; });

        if (it != vec.end() && it->first == key) {
            return it->second;
        }
        else {
            return vec.emplace(it, key, Value{})->second;
        }
    }
};