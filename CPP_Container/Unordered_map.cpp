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
    int bucketSize;
    int sz;

    //해시 함수
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
    void insert(const K& ket, const V& value)
    {
        size_t idx = hashFunc(key);

        
    }
}
