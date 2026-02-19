// unordered_map

/*

1. 'unordered_map'이란?
해시 맵 자료구조를 구현한 컨테이너

해시 맵 : 키(key)와 값(value)로 이루어진 쌍(Pair) 데이터를 저장
         키를 통해 값을 빠르게 검색가능
키와 같이 일대일로 대응되는 맵을 구현


2. 'unordered_map'의 특징
I. 해시 함수 사용
따라서 매우 빠른 검색 속도를 제공하며, 0(1) 시간 복잡도로 요소에 접근할 수 있다.

II. 중복된 키 방지
각 키는 유일해야 하며, 새로운 값을 추가할 때 이미 존재하는 키에 해당하는 값을 덮어쓸 수 있다.

III. 범용성 
다양한 데이터 유형 제공 - 정수, 문자열, 사용자 정의 객체 등

IV. 크기 조절 가능
동적으로 크기 조절 가능
요소를 추가하거나 제거함에 따라 내부 저장 공간이 자동으로 관리된다.

*/

// unordered_map CPP 구현
#include <iostream>
#include <vector>
#include <list>
#include <string>

using namespace std;

template<typename K, typename V>
class MyUnorderedMap
{
private:
    static const int DEFALT_BUCKET = 1009;

    vector<list<pair<K,V>>> table;
    int bucketSize; // 버킷 개수
    int sz; // 현재 저장된 (key,value) 개수

    //해시 함수
    // key -> bucket index 변환
    size_t hashFunc(const K& key) const
    {
        return std::hash<K>{}(key) % bucketSize;
    }

    
public:
    MyUnorderedMap(int bucket = DEFAULT_BUCKET)
        :bucketSize(bucket), sz(0) {
            table.resize(bucketSize);
        }

    // insert
    void insert(const K& key, const V& value)
    {
        size_t idx = hashFunc(key); // 해시값 -> 버킷 위치 계산

        // 이미 key가 존재하면 value만 갱신
        for (auto& p : table[idx])
        {
            if (p.first == key)
            {
                p.second = value;
                return;
            }
        }

        // 없으면 새 pair 추가
        table[idx].push_back({key,value});
        sz++;
    }


    // find
    V* find(const K& key) 
    {
        size_t idx = hashFuc(key); 

        // 해당 버킷 리스트 탐색
        for (auto& p : table[idx])
        {
            if (p.first == key)
                return &p.second;
        }

        return nullptr;
    }

    // operator[]
    // map[key] 형태로 접근가능

    V& operator[](const K& key)
    {
        size_t idx = hashFuc(key);

        // key 존재하면 해당 value 반환
        for (auto& p : table[idx])
        {
            if (p.first == key)
                return p.second;
        }

        // 없으면 기본값 v() 생성 후 삽입
        table[idx].push_back({key,V()});

        // 방금 넣은 값 반환
        return table[idx].back().second;
    }

    // erase
    void erase(const K& key)
    {
        size_t idx = hasjFunc(key);

        auto& lst = table[idx]; // 해당 버킷 리스트 참조

        // 리스트 순회하며 삭제
         for (auto it = lst.begin() ; it != lst.end(); ++it)
         {
            if (it->first == key)
            {
                lst.erase(it);
                sz--;
                return;
            }
         }
    }

    // size
    int size() const 
    {
        return sz;
    }
}
