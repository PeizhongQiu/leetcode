/*
 * @lc app=leetcode.cn id=432 lang=cpp
 *
 * [432] 全 O(1) 的数据结构
 *
 * https://leetcode-cn.com/problems/all-oone-data-structure/description/
 *
 * algorithms
 * Hard (38.52%)
 * Likes:    178
 * Dislikes: 0
 * Total Accepted:    12.2K
 * Total Submissions: 28.4K
 * Testcase Example:  '["AllOne","inc","inc","getMaxKey","getMinKey","inc","getMaxKey","getMinKey"]\n' +
  '[[],["hello"],["hello"],[],[],["leet"],[],[]]'
 *
 * 请你设计一个用于存储字符串计数的数据结构，并能够返回计数最小和最大的字符串。
 * 
 * 实现 AllOne 类：
 * 
 * 
 * AllOne() 初始化数据结构的对象。
 * inc(String key) 字符串 key 的计数增加 1 。如果数据结构中尚不存在 key ，那么插入计数为 1 的 key 。
 * dec(String key) 字符串 key 的计数减少 1 。如果 key 的计数在减少后为 0 ，那么需要将这个 key
 * 从数据结构中删除。测试用例保证：在减少计数前，key 存在于数据结构中。
 * getMaxKey() 返回任意一个计数最大的字符串。如果没有元素存在，返回一个空字符串 "" 。
 * getMinKey() 返回任意一个计数最小的字符串。如果没有元素存在，返回一个空字符串 "" 。
 * 
 * 
 * 
 * 
 * 示例：
 * 
 * 
 * 输入
 * ["AllOne", "inc", "inc", "getMaxKey", "getMinKey", "inc", "getMaxKey",
 * "getMinKey"]
 * [[], ["hello"], ["hello"], [], [], ["leet"], [], []]
 * 输出
 * [null, null, null, "hello", "hello", null, "hello", "leet"]
 * 
 * 解释
 * AllOne allOne = new AllOne();
 * allOne.inc("hello");
 * allOne.inc("hello");
 * allOne.getMaxKey(); // 返回 "hello"
 * allOne.getMinKey(); // 返回 "hello"
 * allOne.inc("leet");
 * allOne.getMaxKey(); // 返回 "hello"
 * allOne.getMinKey(); // 返回 "leet"
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= key.length <= 10
 * key 由小写英文字母组成
 * 测试用例保证：在每次调用 dec 时，数据结构中总存在 key
 * 最多调用 inc、dec、getMaxKey 和 getMinKey 方法 5 * 10^4 次
 * 
 * 
 */

// @lc code=start
class AllOne {
public:
    struct ListNode {
        string data;
        int freq;
        ListNode *prev;
        ListNode *next;
    };
    vector<ListNode*> listHead;
    unordered_map<string, ListNode*> pointerMap;
    int maxFreq = 0;
    int minFreq = INT_MAX;

    AllOne() {

    }

    void listDel(ListNode* delNode) {
        delNode->prev->next = delNode->next;
        if(delNode->next != nullptr)
            delNode->next->prev = delNode->prev;
    }

    void listInsert(ListNode* newNode) {
        if(listHead.size() < newNode->freq) {
            ListNode *newHead = new ListNode();
            newHead->prev = NULL;
            newHead->next = newNode;
            listHead.push_back(newHead);
            newNode->prev = listHead[newNode->freq - 1];
            newNode->next = NULL;
        } else {
            newNode->prev = listHead[newNode->freq - 1];
            newNode->next = listHead[newNode->freq - 1]->next;
            listHead[newNode->freq - 1]->next = newNode;
            if(newNode->next != nullptr)
                newNode->next->prev = newNode;
        }
    }
     
    void inc(string key) {
        ListNode* incNode = NULL;
        if(pointerMap.find(key) == pointerMap.end()) {
            incNode = new ListNode();
            incNode->data = key;
            incNode->freq = 1;
            pointerMap[key] = incNode;
            listInsert(incNode);
        } else {
            incNode = pointerMap[key];
            ++incNode->freq;
            //cout << incNode->freq << key << endl;
            listDel(incNode);
            listInsert(incNode);
        }
        if(incNode->freq > maxFreq) {
            //cout << maxFreq << incNode->data << endl;
            maxFreq = incNode->freq;
        }
        if(incNode->freq < minFreq) {
            minFreq = incNode->freq;
        } else if(incNode->freq - 1 == minFreq && listHead[minFreq - 1]->next == nullptr){
            ++minFreq;
        } 
    }
    
    void dec(string key) {
        ListNode* delNode = pointerMap[key];
        --delNode->freq;
        listDel(delNode);
        if(delNode->freq == 0) {
            pointerMap.erase(key);
            if(pointerMap.empty()) {
                maxFreq = 0;
                minFreq = INT_MAX;
            } else {
                for(int i = 0; i < listHead.size(); ++i) {
                    if(listHead[i]->next != nullptr) {
                        minFreq = i + 1;
                        break;
                    }
                }
            }
        } else {
            listInsert(delNode);
            if(delNode->freq < minFreq) {
                minFreq = delNode->freq;
            }
            if(delNode->freq + 1 == maxFreq && listHead[maxFreq - 1]->next == nullptr){
                --maxFreq;
            } 
        }

    }
    
    string getMaxKey() {
        if(maxFreq > 0) {
            return listHead[maxFreq - 1]->next->data;
        } else {
            return "";
        }
    }
    
    string getMinKey() {
        if(minFreq != INT_MAX) {
            return listHead[minFreq - 1]->next->data;
        } else {
            return "";
        }
    }

    
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */
// @lc code=end

