typedef int rank;
#define DEFAULT_CAPACITY 3;
template<typename T>
class vector{
protected:
    rank size;
    int capacity;
    T * elem = nullptr;
    vector(int capacity = DEFAULT_CAPACITY,int scale = 0,T v = 0)
    {
        elem = new T[c];
        for(int i = 0; i < c;elem[i++] = v);
    };
    void copyFrom(vector<T> const & to_copy,rank from,rank to) //将原向量清空然后再将向量[from,to)复制到原向量
    {
        delete [] elem;
        elem = new T[2*(to - from)];
        size  = 0;
        while (from < to)
        {
            elem[size++] = to_copy[from++];
        }
        capacity = 2*size;
    };
    vector(vector<T> const & to_copy)
    {
        elem = new T[capacity];
        size = 0;
        copyFrom(to_copy,0,to_copy.size);
        return *this;
    };
    vector<T>& operator= (vector<T> const & to_copy){
        copyFrom(to_copy,0,to_copy.size);
        return *this;
    }
    ~vector()
    {
        delete [] elem;
    };
    void expand()
    {
        if(size < capacity) return;
        T* oldelem = elem;
        T* elem = new T[capacity<<=1];
        for (int i = 0; i < size; i++) elem[i] = oldelem[i];
        delete [] oldelem;
        return;
    };
    void shrink()
    {
        if(size << 2 < capacity)
        {
            T* oldelem = elem;
            elem = new T[capacity >>= 1];
            for(int i = 0; i < size;i++) elem[i] = oldelem[i];
            delete [] oldelem;
            return;
        }else{
            return;
        }
    };
    T& operator[] (Rank r) const
    {
        return elem[r];
    };
    // void unsort() 
        //because i cant swap them when there isnt a swap function for this datatype
        // but i hava a plan! i can declare a int pointer and with the sizeof() i can treat the datatype as a intega
        // and copy it to the address i want. then i just declare a T datatype to the first address,
        // jiangjiang! i had the T data copied to the address i want.
    // T&(or may a Rank?) find(T const &)
        //as the unsort function above, i cant get a function to compare the two T data so that i can get a boolean
        //.But i can do this in the similar way above, comparing the binary number.there exist two kinds of find function.
    // void insert(T const &,Rank)
    // void remove(Rank) //consider the valid range
    // void remove(Rank,Rank) //consider the valid range
    // void deduplicate()
        //have the same problem that i cant compare.
    // void find()
    // 二分查找算法（版本C）：在有序向量癿匙间[lo, hi)内查找元素e，0 <= lo <= hi <= _size
    static Rank binSearch(T* A, T const& e, Rank lo, Rank hi) {
    while (lo < hi) { //殏步迭代仅需做一次比较刞断，有两个分支
    Rank mi = (lo + hi) >> 1; //以中点为轴点
    (e < A[mi]) ? hi = mi : lo = mi + 1; //经比较后确定深入[lo, mi)戒(mi, hi)
    } //成功查找丌能提前终止
    return --lo; //循环结束时，lo为大亍e癿元素癿最小秩，故lo - 1即丌大亍e癿元素癿最大秩
    } //有夗个命中元素时，总能保证迒回秩最大者；查找失败时，能够迒回失败癿位置
};