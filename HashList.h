
template <typename K, typename V>
struct HashNode
{
    HashNode(){}
    HashNode(K & key, V & value) : key_(key), value_(value){}
    K key_;
    V value_;
    HashNode* next;
    void operator<< (HashNode tmp)
    {
        cout << tmp.key << " " << tmp.value << endl;
    }
};

template <typename K, typename V>
 class HashList
 {
 public:
    HashList()
    {
        head = new HashNode<K, V>;
        head = nullptr;
        tail = new HashNode<K, V>;
        tail = nullptr;
    }
    ~HashList()
    {
        if(head)
			{
				if(head != tail )
				{
					delete head;
					head = nullptr;
					delete tail;
					tail = nullptr;
				}
				else
				{
					delete head;
					head = nullptr;
				}
			}
    }
    void push_back(K key, V value)
    {
        if(head)
			{
				HashNode<K, V>* temp = new HashNode<K, V>(key, value);
				temp->next = nullptr;
				tail->next = temp;
				tail = tail->next;
			}
			else
			{
				head = new HashNode<K, V>(key, value);
				tail = head;
			}
    }
    int size()
    {
        if(!head)
			{
				return 0;
			}
			int len = 1;
			HashNode<K, V>*temp= new HashNode<K, V>;
			temp = head;
			while(temp && temp != tail )
			{
				++len;
				temp = temp->next;
			}
			return len;
    }
    HashNode<K, V>* find(K key)
    {
        HashNode<K, V>* temp = new HashNode<K, V>;
        temp = head;
        while(temp)
        {
            if(temp->key_ == key)
            {
                return temp;
            }
            temp = temp->next;
        }
        return nullptr;
    }
    void print()
    {
            if(!head)
			{
				return;
			}
			HashNode<K, V>* temp = head;
			while(temp)
			{
				cout <<  "(" << temp->key_ << ", " << temp->value_ << ")   ";
				temp = temp->next;
			}
            cout << endl;
    }
    // 1 2 3 4 5
    void empty()
    {
        HashNode<K, V>* temp = new HashNode<K, V>;
			while(head->next)
			{
                temp = head;
				head = head->next;
				delete temp;
			}
			delete head;
			head = nullptr;
    }
    void remove(K key, V value)
    {
        HashNode<K,V>* temp = new HashNode<K,V>;
        temp = head;
        if(head->key_ == key && head->value_ == value)
        {
            head = head->next;
            delete temp;
            temp = nullptr;
            return;
        }
        HashNode<K,V>* before = new HashNode<K,V>;
        HashNode<K,V>* after = new HashNode<K,V>;
        before = head;
        after = before->next;
        while(after->next)
        {   
            if(after->key_ == key && after->value_ == value)
            {
                temp = after;
                after = after->next;
                before ->next = after;
                delete temp;
                temp = nullptr;
            }
        }
    }
 private: 
    HashNode<K, V>* head;
    HashNode<K, V>* tail;
 };
